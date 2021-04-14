#include "tasks.h"
#include "interlayer.h"

extern volatile uint8_t m_data_sensor;

void settingsAndCreateThread(const char *fnc_name, void (*fnc)(void *), void *arg_0)
{
	/* Definitions for SPITask */
	osThreadId_t SPITaskHandle;
	const osThreadAttr_t SPITask_attributes = {
	  .name = fnc_name,
	  .priority = (osPriority_t) osPriorityNormal,
	  .stack_size = configMINIMAL_STACK_SIZE * 2
	};

	osThreadNew(fnc, arg_0, &SPITask_attributes);
}

__weak void GPIO_Task(void *arg)
{
	/* USER CODE BEGIN 5 */

	/* Infinite loop */
	for(;;)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
		HAL_Delay(1000);

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
		HAL_Delay(1000);
	}
	
	/* USER CODE END 5 */
}

__weak void SPI_Task(void *arg)
{
	/* USER CODE BEGIN 5 */

	// uint8_t *data_sensor = ((uint8_t *)arg);

	uint8_t match = 0;
	
	uint8_t package = 21;
	uint8_t *request_ptr = &package;	

	uint8_t answer = 0;
	uint8_t *answer_ptr = &answer;	

	uint16_t cnt = 1;

	uint8_t prev_answer = 0;
	for(;;)
	{
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
//		HAL_Delay(1000);
//
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
//		HAL_Delay(1000);
//
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
//		HAL_Delay(1000);
//
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
//		HAL_Delay(1000);
//
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
//		HAL_Delay(1000);
//
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
//		HAL_Delay(1000);
//
//		HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);
//		HAL_Delay(1000);
//
//		HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);
//		HAL_Delay(1000);
//
//		HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);
//		HAL_Delay(1000);
//
//		HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);
//		HAL_Delay(1000);

		__HAL_RCC_SPI2_CLK_ENABLE();
				
		HAL_StatusTypeDef statusTransmit = HAL_BUSY;
		HAL_StatusTypeDef statusReceive = HAL_BUSY;
		HAL_StatusTypeDef statusTransmitReceive;

		// HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);
		// statusTransmit = HAL_SPI_Transmit(&hspi2, request_ptr, cnt, HAL_MAX_DELAY);

		// statusReceive = HAL_SPI_Receive(&hspi2, answer_ptr, cnt, HAL_MAX_DELAY);
		// HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);

		// if (statusTransmit == HAL_OK)
		// {		
		// 	if ( ((*request_ptr) == (*answer_ptr)) && (statusReceive == HAL_OK) )
		// 	{
		// 		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
		// 		HAL_Delay(100);
		// 	}
		// }	

		// HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
		// HAL_Delay(100);


		HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);
		statusTransmitReceive = HAL_SPI_TransmitReceive(&hspi2, request_ptr, answer_ptr, cnt, HAL_MAX_DELAY);
		HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);

		// OSWrappers.signalVSync();
		// (*data_sensor) = (*answer_ptr);
		m_data_sensor = (*answer_ptr);

		uint8_t right_answer = 0x06;		
		if ((prev_answer != (*answer_ptr)) && (statusTransmitReceive == HAL_OK) )
		{
			prev_answer = (*answer_ptr);

			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
			HAL_Delay(100);
		}
		
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
		HAL_Delay(100);

	}
	/* USER CODE END 5 */
}
