/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

//#include <ADF7021_Module.h>
//#include "ADF7021_Module.c"


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define BUFFER_SIZE   40


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi3;

/* USER CODE BEGIN PV */


uint8_t data_in[BUFFER_SIZE];
uint8_t data_out[BUFFER_SIZE];



/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI3_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


//---------adf7021.c---------
		void ADF_WriteReg(uint32_t val)
		{
			HAL_GPIO_WritePin(SLE_GPIO_Port, SLE_Pin, 0);
			HAL_Delay(0);

			HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 0);
			HAL_Delay(0);

			for(uint8_t i=0; i<32; i++)
			{
				HAL_GPIO_WritePin(SDATA_GPIO_Port, SDATA_Pin, (val>>(31-i))&1);
				for(uint16_t i=0; i<100; i++)
					asm("NOP");
				HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 1);
				for(uint16_t i=0; i<100; i++)
					asm("NOP");
				HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 0);
				for(uint16_t i=0; i<100; i++)
					asm("NOP");
			}

			HAL_GPIO_WritePin(SLE_GPIO_Port, SLE_Pin, 1);
			//HAL_GPIO_WritePin(TEST2_GPIO_Port, TEST2_Pin, 1);
			for(uint16_t i=0; i<100; i++)
				asm("NOP");
			HAL_GPIO_WritePin(SLE_GPIO_Port, SLE_Pin, 0);
			//HAL_GPIO_WritePin(TEST2_GPIO_Port, TEST2_Pin, 0);
			for(uint16_t i=0; i<100; i++)
				asm("NOP");
		}
//		ADF_SetFreq(439075000, 0);

		void ADF_SetFreq(uint32_t freq, uint8_t rx)
		{
			uint8_t i=0;
			uint16_t f=0;

			if(rx)
				freq-=100000;	//IF correction

			i=freq/(12288000/(3*2));
			f=10*(freq-i*(12288000/(3*2)))/625;

			ADF_WriteReg((i<<19)|(f<<4)|(rx<<27));
		}

		float ADF_GetRSSI(void)
		{
			uint32_t val=0x147;
			uint16_t rv=0;

			HAL_GPIO_WritePin(SLE_GPIO_Port, SLE_Pin, 0);
			HAL_Delay(0);

			HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 0);
			HAL_Delay(0);

			for(uint8_t i=0; i<9; i++)
			{
				HAL_GPIO_WritePin(SDATA_GPIO_Port, SDATA_Pin, (val>>(8-i))&1);
				for(uint16_t i=0; i<100; i++)
					asm("NOP");
				HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 1);
				for(uint16_t i=0; i<100; i++)
					asm("NOP");
				HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 0);
				for(uint16_t i=0; i<100; i++)
					asm("NOP");
			}

			HAL_GPIO_WritePin(SLE_GPIO_Port, SLE_Pin, 1);
			for(uint16_t i=0; i<100; i++)
				asm("NOP");

			//readback
			for(uint8_t i=0; i<16+1; i++)
			{
				HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 1);
				for(uint16_t i=0; i<100; i++)
					asm("NOP");
				HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 0);
				for(uint16_t i=0; i<100; i++)
					asm("NOP");

				if(i)
				{
					rv|=((((SREAD_GPIO_Port->IDR)>>7)&1)<<(16-i));
				}

				for(uint16_t i=0; i<100; i++)
					asm("NOP");
			}

			HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 1);
			for(uint16_t i=0; i<100; i++)
				asm("NOP");
			HAL_GPIO_WritePin(SLE_GPIO_Port, SLE_Pin, 0);
			for(uint16_t i=0; i<100; i++)
				asm("NOP");
			HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 0);

			uint8_t lna_gain=(rv>>9)&3;
			uint8_t filter_gain=(rv>>7)&3;
			uint8_t rdb=rv&0x7F;
			float gain_corr=0.0;

			if(lna_gain==2 && filter_gain==2)
				gain_corr=0.0;
			else if(lna_gain==1)
			{
				if(filter_gain==2)
					gain_corr=24.0;
				else if(filter_gain==1)
					gain_corr=38.0;
				else
					gain_corr=58.0;
			}
			else if(lna_gain==0 && filter_gain==0)
				gain_corr=86.0;

			return -130.0+((float)rdb+gain_corr)/2.0;
		}

		uint16_t ADF_GetChipVersion(void)
		{
			uint32_t val=0x1C7;
			uint16_t rv=0;

			HAL_GPIO_WritePin(SLE_GPIO_Port, SLE_Pin, 0);
			HAL_Delay(0);

			HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 0);
			HAL_Delay(0);

			for(uint8_t i=0; i<9; i++)
			{
				HAL_GPIO_WritePin(SDATA_GPIO_Port, SDATA_Pin, (val>>(8-i))&1);
				for(uint16_t i=0; i<100; i++)
					asm("NOP");
				HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 1);
				for(uint16_t i=0; i<100; i++)
					asm("NOP");
				HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 0);
				for(uint16_t i=0; i<100; i++)
					asm("NOP");
			}

			HAL_GPIO_WritePin(SLE_GPIO_Port, SLE_Pin, 1);
			for(uint16_t i=0; i<100; i++)
				asm("NOP");

			//readback
			for(uint8_t i=0; i<16+1; i++)
			{
				HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 1);
				for(uint16_t i=0; i<100; i++)
					asm("NOP");
				HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 0);
				for(uint16_t i=0; i<100; i++)
					asm("NOP");

				if(i)
				{
					rv|=((((SREAD_GPIO_Port->IDR)>>7)&1)<<(16-i));
				}

				for(uint16_t i=0; i<100; i++)
					asm("NOP");
			}

			HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 1);
			for(uint16_t i=0; i<100; i++)
				asm("NOP");
			HAL_GPIO_WritePin(SLE_GPIO_Port, SLE_Pin, 0);
			for(uint16_t i=0; i<100; i++)
				asm("NOP");
			HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 0);

			return rv;
		}






/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI3_Init();
  /* USER CODE BEGIN 2 */


	for(uint16_t i = 0; i < BUFFER_SIZE; i++)
	{
		data_in[i]=i;
	}



			//example ADF7021 init


	HAL_Delay(3000);
	HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, 0);
	HAL_Delay(100);
	HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, 1);
	HAL_Delay(100);
	HAL_GPIO_WritePin(SLE_GPIO_Port, SLE_Pin, 0);
	HAL_Delay(100);


			//---------registers adf eval soft-------
	//0
	ADF_WriteReg((uint32_t)0x115AA660); //0x115AA660
	HAL_Delay(2-1);

	//1
	ADF_WriteReg((uint32_t)0x21F5021); //0x21F5021
	HAL_Delay(2-1);

	//2
	ADF_WriteReg((uint32_t)0x107F082); //0x107F082
	HAL_Delay(2-1);

	//3
	ADF_WriteReg((uint32_t)0x2A807D13); //0x2A807D13
	HAL_Delay(2-1);

	//4
	ADF_WriteReg((uint32_t)0x8057F894); //0x8057F894
	HAL_Delay(2-1);

	//5
	ADF_WriteReg((uint32_t)0x02815); //0x02815
	HAL_Delay(2-1);

	//6
	ADF_WriteReg((uint32_t)0x507AF46); //0x507AF46
	HAL_Delay(2-1);

	//7
	ADF_WriteReg((uint32_t)0x007); //0x007
	HAL_Delay(2-1);

	//8
	ADF_WriteReg((uint32_t)0x0008); //0x0008
	HAL_Delay(2-1);

	//9
	ADF_WriteReg((uint32_t)0x231E9); //0x231E9
	HAL_Delay(2-1);

	//10
	ADF_WriteReg((uint32_t)0x3296418A); //0x3296418A
	HAL_Delay(2-1);

	//11
	ADF_WriteReg((uint32_t)0x0003B); //0x0003B
	HAL_Delay(2-1);

	//12
	ADF_WriteReg((uint32_t)0x0010C); //0x0010C
	HAL_Delay(2-1);

	//13
	ADF_WriteReg((uint32_t)0x0000D); //0x0000D
	HAL_Delay(2-1);

	//14
	ADF_WriteReg((uint32_t)0x0000000E); //0x0000000E
	HAL_Delay(2-1);

	//15
	ADF_WriteReg((uint32_t)0x0000000F); //0x0000000F
	HAL_Delay(2-1);







/*

 * ---------lib-code-------
	ADF_WriteReg((uint32_t)0x0003B|((uint32_t)0x3243<<8));	//SWD (0x3B) syncword: 0x3243  00111011
	HAL_Delay(2-1);
	ADF_WriteReg((uint32_t)0x0010C|(uint32_t)1<<8);			//DPL (0x10C)
	HAL_Delay(2-1);
	ADF_WriteReg((uint32_t)0x5770B4); //0x5770B4
	HAL_Delay(2-1);
	ADF_WriteReg((uint32_t)0x01ED5);	//coarse cal ON
	HAL_Delay(2-1);
	ADF_WriteReg((uint32_t)0x505EBA6|(uint32_t)1<<4);			//0x505EBA6
	HAL_Delay(10-1);
	//((uint32_t)0x007);
	//HAL_Delay(2-1);
	//ADF_WriteReg((uint32_t)0x0008);
	//HAL_Delay(2-1);
	ADF_WriteReg((uint32_t)0x9|(uint32_t)40<<4|(uint32_t)70<<11);//|((uint32_t)1<<18)|((uint32_t)2<<20)|((uint32_t)2<<22)); //manual gain - max
	HAL_Delay(2-1);
	ADF_WriteReg((uint32_t)0x3296556B);
	HAL_Delay(2-1);
	ADF_WriteReg((uint32_t)0x003BD);

	ADF_WriteReg((uint32_t)0x475031);    //  010001110101000000110001
	HAL_Delay(2-1);

	ADF_WriteReg((uint32_t)0x29ECA093);	//CDR=40
	//ADF_WriteReg((uint32_t)(0x29ECA093&(~(0xFF<<10)))|1<<10);	//CDR=1 for DAC test
	HAL_Delay(2-1);

	//ADF_SetFreq(439425000, 1);	//SR5ND
	//ADF_SetFreq(439350000, 1);	//SR5WA
	//ADF_SetFreq(438625000, 1);	//SR5WP
	//ADF_SetFreq(439000000, 1);	//SR5WZ
	//ADF_SetFreq(439075000, 0);	//SR5MS


	//ADF_WriteReg(((uint32_t)212<<19)|((uint32_t)13184<<4));
	//ADF_WriteReg(((uint32_t)177<<19)|((uint32_t)64<<4));
	HAL_Delay(2-1);

	uint8_t pwr=63;	//1=-16dBm, 63=+13dBm
	ADF_WriteReg((uint32_t)0x00D018B2|(0<<30)|(pwr<<13));	//4FSK raw
	//ADF_WriteReg((uint32_t)0x00D018F2|(0<<30)|(pwr<<13));	//4FSK + RC filter
	HAL_Delay(2-1);

	ADF_WriteReg((uint32_t)0x0000000F|(1<<8));	//1:TX carrier, 2:+f_i, 3:-f_i
	//ADF_WriteReg((uint32_t)(14|(1<<4)|(0<<21)));	//test DAC EN, no DAC gain
*/


  /* USER CODE END 2 */





  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */




		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
		HAL_Delay(100);
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
		HAL_Delay(100);

		//HAL_SPI_Transmit(&hspi3, data_in, BUFFER_SIZE, 100);




  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV4;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI3_Init(void)
{

  /* USER CODE BEGIN SPI3_Init 0 */

  /* USER CODE END SPI3_Init 0 */

  /* USER CODE BEGIN SPI3_Init 1 */

  /* USER CODE END SPI3_Init 1 */
  /* SPI3 parameter configuration*/
  hspi3.Instance = SPI3;
  hspi3.Init.Mode = SPI_MODE_MASTER;
  hspi3.Init.Direction = SPI_DIRECTION_2LINES;
  hspi3.Init.DataSize = SPI_DATASIZE_16BIT;
  hspi3.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi3.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi3.Init.NSS = SPI_NSS_SOFT;
  hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi3.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi3.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi3.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi3.Init.CRCPolynomial = 7;
  hspi3.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi3.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI3_Init 2 */

  /* USER CODE END SPI3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LAMP_GPIO_Port, LAMP_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SCLK_Pin|SDATA_Pin|SLE_Pin|CE_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED_Pin */
  GPIO_InitStruct.Pin = LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LAMP_Pin */
  GPIO_InitStruct.Pin = LAMP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LAMP_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : MUX_Pin */
  GPIO_InitStruct.Pin = MUX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(MUX_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : SWD_Pin */
  GPIO_InitStruct.Pin = SWD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SWD_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : SCLK_Pin SDATA_Pin SLE_Pin CE_Pin */
  GPIO_InitStruct.Pin = SCLK_Pin|SDATA_Pin|SLE_Pin|CE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : SREAD_Pin */
  GPIO_InitStruct.Pin = SREAD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SREAD_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
