/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : stm32f10x_it.c
* Author             : MCD Application Team
* Version            : V2.0.1
* Date               : 06/13/2008
* Description        : Main Interrupt Service Routines.
*                      This file provides template for all exceptions handler
*                      and peripherals interrupt service routine.
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "platform_config.h"
#include "..\Application\main.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : NMIException
* Description    : This function handles NMI exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void NMIException(void)
{
}

/*******************************************************************************
* Function Name  : HardFaultException
* Description    : This function handles Hard Fault exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void HardFaultException(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/*******************************************************************************
* Function Name  : MemManageException
* Description    : This function handles Memory Manage exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void MemManageException(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/*******************************************************************************
* Function Name  : BusFaultException
* Description    : This function handles Bus Fault exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void BusFaultException(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/*******************************************************************************
* Function Name  : UsageFaultException
* Description    : This function handles Usage Fault exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void UsageFaultException(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/*******************************************************************************
* Function Name  : DebugMonitor
* Description    : This function handles Debug Monitor exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DebugMonitor(void)
{
}

/*******************************************************************************
* Function Name  : SVCHandler
* Description    : This function handles SVCall exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SVCHandler(void)
{
}

/*******************************************************************************
* Function Name  : PendSVC
* Description    : This function handles PendSVC exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void PendSVC(void)
{
}

/*******************************************************************************
* Function Name  : SysTickHandler
* Description    : This function handles SysTick Handler.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SysTickHandler(void)
{

}

/*******************************************************************************
* Function Name  : WWDG_IRQHandler
* Description    : This function handles WWDG interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void WWDG_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : PVD_IRQHandler
* Description    : This function handles PVD interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void PVD_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TAMPER_IRQHandler
* Description    : This function handles Tamper interrupt request. 
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TAMPER_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : RTC_IRQHandler
* Description    : This function handles RTC global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RTC_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : FLASH_IRQHandler
* Description    : This function handles Flash interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void FLASH_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : RCC_IRQHandler
* Description    : This function handles RCC interrupt request. 
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RCC_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : EXTI0_IRQHandler
* Description    : This function handles External interrupt Line 0 request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI0_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : EXTI1_IRQHandler
* Description    : This function handles External interrupt Line 1 request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI1_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : EXTI2_IRQHandler
* Description    : This function handles External interrupt Line 2 request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI2_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : EXTI3_IRQHandler
* Description    : This function handles External interrupt Line 3 request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI3_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : EXTI4_IRQHandler
* Description    : This function handles External interrupt Line 4 request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI4_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMA1_Channel1_IRQHandler
* Description    : This function handles DMA1 Channel 1 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA1_Channel1_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMA1_Channel2_IRQHandler
* Description    : This function handles DMA1 Channel 2 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA1_Channel2_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMA1_Channel3_IRQHandler
* Description    : This function handles DMA1 Channel 3 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA1_Channel3_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMA1_Channel4_IRQHandler
* Description    : This function handles DMA1 Channel 4 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA1_Channel4_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMA1_Channel5_IRQHandler
* Description    : This function handles DMA1 Channel 5 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA1_Channel5_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMA1_Channel6_IRQHandler
* Description    : This function handles DMA1 Channel 6 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA1_Channel6_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMA1_Channel7_IRQHandler
* Description    : This function handles DMA1 Channel 7 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA1_Channel7_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : ADC1_2_IRQHandler
* Description    : This function handles ADC1 and ADC2 global interrupts requests.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void ADC1_2_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : USB_HP_CAN_TX_IRQHandler
* Description    : This function handles USB High Priority or CAN TX interrupts 
*                  requests.
                   此中断函数在此项目的 can.c 已有定义并且占用 2010-3-22 14:01:39
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
/*
void USB_HP_CAN_TX_IRQHandler(void)
{
}
*/
/*******************************************************************************
* Function Name  : USB_LP_CAN_RX0_IRQHandler
* Description    : This function handles USB Low Priority or CAN RX0 interrupts 
*                  requests.
                   此中断函数在此项目的 can.c 已有定义并且占用 2010-3-22 14:03:33
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
/*
void USB_LP_CAN_RX0_IRQHandler(void)
{
}
*/

/*******************************************************************************
* Function Name  : CAN_RX1_IRQHandler
* Description    : This function handles CAN RX1 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void CAN_RX1_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : CAN_SCE_IRQHandler
* Description    : This function handles CAN SCE interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void CAN_SCE_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : EXTI9_5_IRQHandler
* Description    : This function handles External lines 9 to 5 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
/*------------------------------------------------------------------------------------------------------------------------------------------
| Description    : 本中断函数只涉及ADF7021的数据接收
|                  数据接收采用ADF7021的时钟信号上升沿中断的方式，进入中断后必须立即读数据
|									 由于调试的问题，暂时仍然放在 stm32f10x_it.c 中，以后考虑挪走
|									 约几十微秒的时间可以处理完本中断，某次实测是 32us
| Input          : NONE
| Output         : 把接收到的数据存入最底层的数组缓冲区中
| Return         : 无返回
| Remark         : 
| Designer       : xudong@engineer.com  2010.3.11
------------------------------------------------------------------------------------------------------------------------------------------*/
void EXTI9_5_IRQHandler( void )
{
	//-----<<<< 检测模块M1 左通道 425MHz >>>>
	if( EXTI_GetITStatus( ADF7021_MODULE_M1 ) != RESET )   // 约需0.4us
	{
		//---- 1 左移
		array_shift_left( M1_Buf, sizeof(M1_Buf) );  // 数组整体左移，约需9us

		//---- 2 读数据
		if( ( GPIO_ReadInputData( ADF7021_MODULE_M1_DATA_PORT ) & ADF7021_MODULE_M1_DATA_PORT_BIT ) == ADF7021_MODULE_M1_DATA_PORT_BIT )
		{   // 如果读到的是1,在数组的最后一个元素的最低位 处理
			M1_Buf[ sizeof(M1_Buf) - 1 ] |= 0x01 ;
		}
			else
			{
				M1_Buf[ sizeof(M1_Buf) - 1 ] &= 0xfe ;  // 不能省，因为之前数组是循环左移，数组最后一个字节的最低位可能会变成1
			}

		//---- 3 每接收1 bit就通知主程序处理
		M1_Packet_end_Mark = RECEIVE_OK ;  // 通知主函数处理

		//---- 4 退出中断
	  EXTI_ClearITPendingBit( ADF7021_MODULE_M1 );
	}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//-----<<<< 检测模块M2 右通道 433MHz >>>>
	if( EXTI_GetITStatus( ADF7021_MODULE_M2 ) != RESET )
	{
		//---- 1 左移
		array_shift_left( M2_Buf, sizeof(M2_Buf) );  // 数组整体左移，约需9us

		//---- 2 读数据
		if( ( GPIO_ReadInputData( ADF7021_MODULE_M2_DATA_PORT ) & ADF7021_MODULE_M2_DATA_PORT_BIT ) == ADF7021_MODULE_M2_DATA_PORT_BIT )
		{   // 如果读到的是1,在数组的最后一个元素的最低位 处理
			M2_Buf[ sizeof(M2_Buf) - 1 ] |= 0x01 ;
		}
			else
			{
				M2_Buf[ sizeof(M2_Buf) - 1 ] &= 0xfe ;  // 不能省，因为之前数组是循环左移，数组最后一个字节的最低位可能会变成1
			}

		//---- 3 每接收1 bit就通知主程序处理
		M2_Packet_end_Mark = RECEIVE_OK ;  // 通知主函数处理

		//---- 4 退出中断
	  EXTI_ClearITPendingBit( ADF7021_MODULE_M2 );
	}
}

/*******************************************************************************
* Function Name  : TIM1_BRK_IRQHandler
* Description    : This function handles TIM1 Break interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM1_BRK_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM1_UP_IRQHandler
* Description    : This function handles TIM1 overflow and update interrupt request.
                   此中断函数完成
                   1、LED2闪烁，作为CPU运行指示，上电就闪烁；
                   2、安全间隙计时器M1_security、M2_security的分别累加；
                   3、判断M1_security、M2_security是否超时，如果超时则清除CAN上相应的位并关闭LED3、LED4
                   4、最后一步是向CAN上发送数据
* Input          : None
* Output         : None
* Return         : None
* Remark         : 1、上电约1s后执行，之后约0.3us中断一次（仿真测量）
* Designer       : xudong@engineer.com   2010-6-18 18:13:35
*******************************************************************************/
void TIM1_UP_IRQHandler(void)
{
	#ifndef   MODBUS_ENABLE
	u8 i ;
	u16 crc16_value ;
	#endif
	
	TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
	
	//--------------------------------------------------------------------------------------------------------------------
	// 发送到CAN时，D9闪烁，也可用于测量发送频率
	//--------------------------------------------------------------------------------------------------------------------
	led2++ ;

	if( led2 % 2 == 0 )
	{
		GPIO_ResetBits( LED2 );  // LED2是系统运行的指示，LED3、LED4分别是两个通道收到了数据的指示
	}
		else
		{
			GPIO_SetBits( LED2 );
		}
	

	//--------------------------------------------------------------------------------------------------------------------
	// 安全间隔计时
	//--------------------------------------------------------------------------------------------------------------------
	if( M1_security != 0xff ) // 保证 M1_security 记到最大时不复位，只能由主程序复位
	{
		M1_security++ ;
	}

	if( M2_security != 0xff )
	{
		M2_security++ ;
	}
	

	//--------------------------------------------------------------------------------------------------------------------
	// 安全间隔超时处理
	//--------------------------------------------------------------------------------------------------------------------
	if( ( M1_security >= SEC_TIME ) && ( M2_security >= SEC_TIME ) )
	{
		GPIO_ResetBits( OE_4094 ) ;    // 超时后关闭4094的输出并且切断继电器的电源（二者硬件上相关），防止干扰误动作
		GPIO_ResetBits( STR_4094 ) ;   //STR置低这里似乎意义并不大，但只有STR也是高了，才可能写入4094，所以这里也置低
		GPIO_ResetBits( SDATA_4094 ) ; //数据端口总是置低，设想即使被干扰误写入很大程度上也是写的零
		GPIO_SetBits( CLK_4094 ) ;     //因为是上升沿写入数据，所以这里总是给置高，使产生不了上升沿
	}

	//--------------------------------------------------------------------------------------------------------------------
	// 单边超时处理
	//--------------------------------------------------------------------------------------------------------------------
	if( M1_security >= SEC_TIME )
	{
		relay_value_left = 0 ;

		CAN_TxMsg.data[0] = 0 ; // 遥控器键值清零
		CAN_TxMsg.data[1] = 0 ;
		CAN_TxMsg.data[2] = 0 ;
		CAN_TxMsg.data[3] = 0 ;

		#ifndef   MODBUS_ENABLE
			RS485_Cache[3] = 0 ;
			RS485_Cache[4] = 0 ;
			RS485_Cache[5] = 0 ;
			RS485_Cache[6] = 0 ;
		#endif

		MODBusSendBuf[3] = 0 ;
		MODBusSendBuf[4] = 0 ;
		MODBusSendBuf[5] = 0 ;
		MODBusSendBuf[6] = 0 ;

		GPIO_SetBits( LED3 );  // 超过时间后LED的状态也清零
	}
	
	if( M2_security >= SEC_TIME )
	{
		relay_value_right = 0 ;

		CAN_TxMsg.data[4] = 0 ; // 遥控器键值清零
		CAN_TxMsg.data[5] = 0 ;
		CAN_TxMsg.data[6] = 0 ;
		CAN_TxMsg.data[7] = 0 ;

		#ifndef   MODBUS_ENABLE
			RS485_Cache[7]  = 0 ;
			RS485_Cache[8]  = 0 ;
			RS485_Cache[9]  = 0 ;
			RS485_Cache[10] = 0 ;
		#endif

		MODBusSendBuf[7]  = 0 ;
		MODBusSendBuf[8]  = 0 ;
		MODBusSendBuf[9]  = 0 ;
		MODBusSendBuf[10] = 0 ;

		GPIO_SetBits( LED4 );  // 超过时间后LED的状态也清零
	}


	//--------------------------------------------------------------------------------------------------------------------
	// 发送到CAN上  因为CAN的速度相当快，所以请先发CAN的
	//--------------------------------------------------------------------------------------------------------------------
  CAN_TxRdy = 0;
  CAN_wrMsg( &CAN_TxMsg );
  

	//--------------------------------------------------------------------------------------------------------------------
	// 发送到485上
	//--------------------------------------------------------------------------------------------------------------------
	#ifndef   MODBUS_ENABLE  // 如果不用MODBus，就直接用RS485发送出去了
	                         // Modbus工作模式时，直接在主程序中发送，因为牵涉到总线的时间规范问题，放到主程序中应该较好
	RS485_Cache[0] = 0xAA ;
	RS485_Cache[1] = 0xAA ;
	RS485_Cache[2] = 0xAA ;

	crc16_value = CRC16_WCT( RS485_Cache + 3, sizeof( RS485_Cache ) - 5 ) ;

	RS485_Cache[ sizeof( RS485_Cache ) - 2 ] = (u8)  crc16_value ;      // 低字节在前
	RS485_Cache[ sizeof( RS485_Cache ) - 1 ] = (u8)( crc16_value >> 8 ) ; // 高字节在后
	
	for( i = 0 ; i < sizeof( RS485_Cache ) ; i++ )
	{
	  while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)  ;
	  USART_SendData( USART1, RS485_Cache[i] );  //
	}
	#endif   // end  MODBUS_ENABLE
}

/*******************************************************************************
* Function Name  : TIM1_TRG_COM_IRQHandler
* Description    : This function handles TIM1 Trigger and commutation interrupts 
*                  requests.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM1_TRG_COM_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM1_CC_IRQHandler
* Description    : This function handles TIM1 capture compare interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM1_CC_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM2_IRQHandler
* Description    : This function handles TIM2 global interrupt request.
                   由于4094需要快速频繁写入以防止跳动，所以单独用一个定时中断
                   这个定时中断将是高速的
                   2011-2-11 11:45:37
                   1、不用较好，直接在主函数中控制了
                   2、但CAN及485仍然保留在中断中发出
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM2_IRQHandler(void)
{
	//NByteDataTo4094( CAN_TxMsg.data , 2 ) ;  // 这是包括CAN_TxMsg.data[0]及 CAN_TxMsg.data[1]的两字节，先这样测试
}

/*******************************************************************************
* Function Name  : TIM3_IRQHandler
* Description    : This function handles TIM3 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM3_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM4_IRQHandler
* Description    : This function handles TIM4 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM4_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : I2C1_EV_IRQHandler
* Description    : This function handles I2C1 Event interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void I2C1_EV_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : I2C1_ER_IRQHandler
* Description    : This function handles I2C1 Error interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void I2C1_ER_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : I2C2_EV_IRQHandler
* Description    : This function handles I2C2 Event interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void I2C2_EV_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : I2C2_ER_IRQHandler
* Description    : This function handles I2C2 Error interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void I2C2_ER_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : SPI1_IRQHandler
* Description    : This function handles SPI1 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SPI1_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : SPI2_IRQHandler
* Description    : This function handles SPI2 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SPI2_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : USART1_IRQHandler
* Description    : This function handles USART1 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USART1_IRQHandler(void)
{
/*
  原程序用超时检测实现的一帧一帧的检测，似乎不妥，这里将采用缓存的方式
	if( ( modbus_time > MODBUD_TIME_OUT ) || ( USART_buf_i == ( sizeof( USART_buf ) - 1 ) ) )
	{    // 如果超时   或者   缓存即将溢出时
		modbus_time = 0; // 定时计数器复位
		USART_buf_i = 0 ; // 缓存指针复位
	}
		else
		{
			modbus_time = 0; // 定时计数器复位
			USART_buf_i++ ;  // 缓存指针调整
		}
*/

	#ifdef  MODBUS_ENABLE
	if( USART_GetITStatus(USART1, USART_IT_RXNE) != RESET )
	{
		ArrayLeftMove1Byte( MODBusReceiveBuf, sizeof( MODBusReceiveBuf ) ) ; // 接收缓冲区左移一个字节
		MODBusReceiveBuf[ sizeof( MODBusReceiveBuf ) - 1 ] = USART_ReceiveData( USART1 ) ;
	}

	//USART_ClearITPendingBit(USART1, USART_IT_ORE);
	//USART_ClearITPendingBit(USART1, USART_IT_RXNE); // 清除串口接收中断标志
	#endif  // end  MODBUS_ENABLE
}

/*******************************************************************************
* Function Name  : USART2_IRQHandler
* Description    : This function handles USART2 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USART2_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : USART3_IRQHandler
* Description    : This function handles USART3 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USART3_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : EXTI15_10_IRQHandler
* Description    : This function handles External lines 15 to 10 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI15_10_IRQHandler(void)
{
	//GPIO_SetBits( LED5 );
  EXTI_ClearITPendingBit( EXTI_Line12 );
}

/*******************************************************************************
* Function Name  : RTCAlarm_IRQHandler
* Description    : This function handles RTC Alarm interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RTCAlarm_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : USBWakeUp_IRQHandler
* Description    : This function handles USB WakeUp interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USBWakeUp_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM8_BRK_IRQHandler
* Description    : This function handles TIM8 Break interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM8_BRK_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM8_UP_IRQHandler
* Description    : This function handles TIM8 overflow and update interrupt 
*                  request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM8_UP_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM8_TRG_COM_IRQHandler
* Description    : This function handles TIM8 Trigger and commutation interrupts 
*                  requests.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM8_TRG_COM_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM8_CC_IRQHandler
* Description    : This function handles TIM8 capture compare interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM8_CC_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : ADC3_IRQHandler
* Description    : This function handles ADC3 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void ADC3_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : FSMC_IRQHandler
* Description    : This function handles FSMC global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void FSMC_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : SDIO_IRQHandler
* Description    : This function handles SDIO global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SDIO_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM5_IRQHandler
* Description    : This function handles TIM5 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM5_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : SPI3_IRQHandler
* Description    : This function handles SPI3 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SPI3_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : UART4_IRQHandler
* Description    : This function handles UART4 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void UART4_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : UART5_IRQHandler
* Description    : This function handles UART5 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void UART5_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM6_IRQHandler
* Description    : This function handles TIM6 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM6_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM7_IRQHandler
* Description    : This function handles TIM7 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM7_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMA2_Channel1_IRQHandler
* Description    : This function handles DMA2 Channel 1 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA2_Channel1_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMA2_Channel2_IRQHandler
* Description    : This function handles DMA2 Channel 2 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA2_Channel2_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMA2_Channel3_IRQHandler
* Description    : This function handles DMA2 Channel 3 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA2_Channel3_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMA2_Channel4_5_IRQHandler
* Description    : This function handles DMA2 Channel 4 and DMA2 Channel 5
*                  interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA2_Channel4_5_IRQHandler(void)
{
}

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
