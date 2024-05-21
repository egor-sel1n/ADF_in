/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Pin GPIO_PIN_9
#define LED_GPIO_Port GPIOC
#define LAMP_Pin GPIO_PIN_12
#define LAMP_GPIO_Port GPIOA
#define MUX_Pin GPIO_PIN_15
#define MUX_GPIO_Port GPIOA
#define SWD_Pin GPIO_PIN_2
#define SWD_GPIO_Port GPIOD
#define SCLK_Pin GPIO_PIN_3
#define SCLK_GPIO_Port GPIOB
#define SREAD_Pin GPIO_PIN_4
#define SREAD_GPIO_Port GPIOB
#define SDATA_Pin GPIO_PIN_5
#define SDATA_GPIO_Port GPIOB
#define SLE_Pin GPIO_PIN_8
#define SLE_GPIO_Port GPIOB
#define CE_Pin GPIO_PIN_9
#define CE_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
