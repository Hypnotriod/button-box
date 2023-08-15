/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define MATRIX_COL0_Pin GPIO_PIN_1
#define MATRIX_COL0_GPIO_Port GPIOA
#define MATRIX_COL1_Pin GPIO_PIN_2
#define MATRIX_COL1_GPIO_Port GPIOA
#define MATRIX_COL2_Pin GPIO_PIN_3
#define MATRIX_COL2_GPIO_Port GPIOA
#define MATRIX_COL3_Pin GPIO_PIN_4
#define MATRIX_COL3_GPIO_Port GPIOA
#define MATRIX_COL4_Pin GPIO_PIN_5
#define MATRIX_COL4_GPIO_Port GPIOA
#define MATRIX_COL5_Pin GPIO_PIN_6
#define MATRIX_COL5_GPIO_Port GPIOA
#define MATRIX_COL6_Pin GPIO_PIN_7
#define MATRIX_COL6_GPIO_Port GPIOA
#define ENC1_S1_Pin GPIO_PIN_0
#define ENC1_S1_GPIO_Port GPIOB
#define ENC1_S1_EXTI_IRQn EXTI0_IRQn
#define ENC2_S1_Pin GPIO_PIN_1
#define ENC2_S1_GPIO_Port GPIOB
#define ENC2_S1_EXTI_IRQn EXTI1_IRQn
#define MATRIX_ROW3_Pin GPIO_PIN_11
#define MATRIX_ROW3_GPIO_Port GPIOB
#define MATRIX_ROW4_Pin GPIO_PIN_12
#define MATRIX_ROW4_GPIO_Port GPIOB
#define MATRIX_ROW0_Pin GPIO_PIN_13
#define MATRIX_ROW0_GPIO_Port GPIOB
#define MATRIX_ROW1_Pin GPIO_PIN_14
#define MATRIX_ROW1_GPIO_Port GPIOB
#define MATRIX_ROW2_Pin GPIO_PIN_15
#define MATRIX_ROW2_GPIO_Port GPIOB
#define MATRIX_COL7_Pin GPIO_PIN_8
#define MATRIX_COL7_GPIO_Port GPIOA
#define MATRIX_COL8_Pin GPIO_PIN_9
#define MATRIX_COL8_GPIO_Port GPIOA
#define ENC1_S2_Pin GPIO_PIN_6
#define ENC1_S2_GPIO_Port GPIOB
#define ENC2_S2_Pin GPIO_PIN_7
#define ENC2_S2_GPIO_Port GPIOB
#define ENC1_KEY_Pin GPIO_PIN_8
#define ENC1_KEY_GPIO_Port GPIOB
#define ENC2_KEY_Pin GPIO_PIN_9
#define ENC2_KEY_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
