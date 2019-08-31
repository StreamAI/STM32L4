/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, LED_R_Pin|LED_G_Pin|LED_B_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : PEPin PEPin PEPin */
  GPIO_InitStruct.Pin = LED_R_Pin|LED_G_Pin|LED_B_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */

void RGB_ON(RGB_Color RGB_LED)
{
	switch(RGB_LED % MAX_NUM)
		{
			case RED:
				HAL_GPIO_WritePin(GPIOE, LED_R_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOE, LED_G_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOE, LED_B_Pin, GPIO_PIN_SET);
				break;
			case GREEN:
				HAL_GPIO_WritePin(GPIOE, LED_R_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOE, LED_G_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOE, LED_B_Pin, GPIO_PIN_SET);
				break;
			case BLUE:
				HAL_GPIO_WritePin(GPIOE, LED_R_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOE, LED_G_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOE, LED_B_Pin, GPIO_PIN_RESET);
				break;
			case YELLOW:
				HAL_GPIO_WritePin(GPIOE, LED_R_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOE, LED_G_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOE, LED_B_Pin, GPIO_PIN_SET);
				break;
			case PURPLE:
				HAL_GPIO_WritePin(GPIOE, LED_R_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOE, LED_G_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOE, LED_B_Pin, GPIO_PIN_RESET);
				break;
			case CYAN:
				HAL_GPIO_WritePin(GPIOE, LED_R_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOE, LED_G_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOE, LED_B_Pin, GPIO_PIN_RESET);
				break;
			case WHITE:
				HAL_GPIO_WritePin(GPIOE, LED_R_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOE, LED_G_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOE, LED_B_Pin, GPIO_PIN_RESET);
				break;
			default:
				HAL_GPIO_WritePin(GPIOE, LED_R_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOE, LED_G_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOE, LED_B_Pin, GPIO_PIN_SET);
				break;
		}
}

/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
