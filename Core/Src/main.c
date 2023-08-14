/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usbd_hid.h"
#include <stdbool.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef struct {
      int8_t joyX;
      int8_t joyY;
      uint8_t buttons1;
      uint8_t buttons2;
      uint8_t buttons3;
} report_t;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
extern USBD_HandleTypeDef hUsbDeviceFS;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  report_t report;
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
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    report.joyX = 0;
    report.joyY = 0;
    report.buttons1 = 0;
    report.buttons2 = 0;
    report.buttons3 = 0;

    HAL_GPIO_WritePin(MATRIX_ROW0_GPIO_Port, MATRIX_ROW0_Pin, GPIO_PIN_RESET);
    if (HAL_GPIO_ReadPin(MATRIX_COL0_GPIO_Port, MATRIX_COL0_Pin) == GPIO_PIN_RESET)
        report.buttons1 |= 0x01;
    if (HAL_GPIO_ReadPin(MATRIX_COL1_GPIO_Port, MATRIX_COL1_Pin) == GPIO_PIN_RESET)
        report.joyY = 127;
    if (HAL_GPIO_ReadPin(MATRIX_COL2_GPIO_Port, MATRIX_COL2_Pin) == GPIO_PIN_RESET)
    	report.joyY = -127;
    if (HAL_GPIO_ReadPin(MATRIX_COL3_GPIO_Port, MATRIX_COL3_Pin) == GPIO_PIN_RESET)
        report.joyX = -127;
    if (HAL_GPIO_ReadPin(MATRIX_COL4_GPIO_Port, MATRIX_COL4_Pin) == GPIO_PIN_RESET)
        report.joyX = 127;
    if (HAL_GPIO_ReadPin(MATRIX_COL5_GPIO_Port, MATRIX_COL5_Pin) == GPIO_PIN_RESET)
    	report.buttons1 |= 0x02;
    if (HAL_GPIO_ReadPin(MATRIX_COL6_GPIO_Port, MATRIX_COL6_Pin) == GPIO_PIN_RESET)
    	report.buttons1 |= 0x04;
    HAL_GPIO_WritePin(MATRIX_ROW0_GPIO_Port, MATRIX_ROW0_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(MATRIX_ROW1_GPIO_Port, MATRIX_ROW1_Pin, GPIO_PIN_RESET);
	if (HAL_GPIO_ReadPin(MATRIX_COL0_GPIO_Port, MATRIX_COL0_Pin) == GPIO_PIN_RESET)
		report.buttons1 |= 0x08;
	if (HAL_GPIO_ReadPin(MATRIX_COL1_GPIO_Port, MATRIX_COL1_Pin) == GPIO_PIN_RESET)
		report.buttons1 |= 0x10;
	if (HAL_GPIO_ReadPin(MATRIX_COL2_GPIO_Port, MATRIX_COL2_Pin) == GPIO_PIN_RESET)
		report.buttons1 |= 0x20;
	if (HAL_GPIO_ReadPin(MATRIX_COL3_GPIO_Port, MATRIX_COL3_Pin) == GPIO_PIN_RESET)
		report.buttons1 |= 0x40;
	if (HAL_GPIO_ReadPin(MATRIX_COL4_GPIO_Port, MATRIX_COL4_Pin) == GPIO_PIN_RESET)
		report.buttons1 |= 0x80;
	if (HAL_GPIO_ReadPin(MATRIX_COL5_GPIO_Port, MATRIX_COL5_Pin) == GPIO_PIN_RESET)
		report.buttons2 |= 0x01;
	if (HAL_GPIO_ReadPin(MATRIX_COL6_GPIO_Port, MATRIX_COL6_Pin) == GPIO_PIN_RESET)
		report.buttons2 |= 0x02;
	HAL_GPIO_WritePin(MATRIX_ROW1_GPIO_Port, MATRIX_ROW1_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(MATRIX_ROW2_GPIO_Port, MATRIX_ROW2_Pin, GPIO_PIN_RESET);
	if (HAL_GPIO_ReadPin(MATRIX_COL0_GPIO_Port, MATRIX_COL0_Pin) == GPIO_PIN_RESET)
		report.buttons2 |= 0x04;
	if (HAL_GPIO_ReadPin(MATRIX_COL1_GPIO_Port, MATRIX_COL1_Pin) == GPIO_PIN_RESET)
		report.buttons2 |= 0x08;
	if (HAL_GPIO_ReadPin(MATRIX_COL2_GPIO_Port, MATRIX_COL2_Pin) == GPIO_PIN_RESET)
		report.buttons2 |= 0x10;
	if (HAL_GPIO_ReadPin(MATRIX_COL3_GPIO_Port, MATRIX_COL3_Pin) == GPIO_PIN_RESET)
		report.buttons2 |= 0x20;
	if (HAL_GPIO_ReadPin(MATRIX_COL4_GPIO_Port, MATRIX_COL4_Pin) == GPIO_PIN_RESET)
		report.buttons2 |= 0x40;
	if (HAL_GPIO_ReadPin(MATRIX_COL5_GPIO_Port, MATRIX_COL5_Pin) == GPIO_PIN_RESET)
		report.buttons2 |= 0x80;
	if (HAL_GPIO_ReadPin(MATRIX_COL6_GPIO_Port, MATRIX_COL6_Pin) == GPIO_PIN_RESET)
		report.buttons3 |= 0x01;
	HAL_GPIO_WritePin(MATRIX_ROW2_GPIO_Port, MATRIX_ROW2_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(MATRIX_ROW3_GPIO_Port, MATRIX_ROW3_Pin, GPIO_PIN_RESET);
	if (HAL_GPIO_ReadPin(MATRIX_COL5_GPIO_Port, MATRIX_COL5_Pin) == GPIO_PIN_RESET)
		report.buttons3 |= 0x02;
	if (HAL_GPIO_ReadPin(MATRIX_COL6_GPIO_Port, MATRIX_COL6_Pin) == GPIO_PIN_RESET)
		report.buttons3 |= 0x04;
	HAL_GPIO_WritePin(MATRIX_ROW3_GPIO_Port, MATRIX_ROW3_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(MATRIX_ROW4_GPIO_Port, MATRIX_ROW4_Pin, GPIO_PIN_RESET);
	if (HAL_GPIO_ReadPin(MATRIX_COL5_GPIO_Port, MATRIX_COL5_Pin) == GPIO_PIN_RESET)
		report.buttons3 |= 0x08;
	if (HAL_GPIO_ReadPin(MATRIX_COL6_GPIO_Port, MATRIX_COL6_Pin) == GPIO_PIN_RESET)
		report.buttons3 |= 0x10;
	HAL_GPIO_WritePin(MATRIX_ROW4_GPIO_Port, MATRIX_ROW4_Pin, GPIO_PIN_SET);
	if (HAL_GPIO_ReadPin(ENC1_KEY_GPIO_Port, ENC1_KEY_Pin) == GPIO_PIN_RESET)
		report.buttons3 |= 0x20;
	if (HAL_GPIO_ReadPin(ENC2_KEY_GPIO_Port, ENC2_KEY_Pin) == GPIO_PIN_RESET)
		report.buttons3 |= 0x40;

	while (USBD_HID_GetState(&hUsbDeviceFS) != HID_IDLE) {};
    USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*) &report, sizeof(report_t));

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
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
