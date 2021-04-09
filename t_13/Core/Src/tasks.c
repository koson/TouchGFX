# include "tasks.h"


void settingsAndCreateTread(const char *fnc_name, void (*fnc)(), void *arg_0)
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
	// uint8_t *tx_data;
	// uint8_t *rx_data;

	/* Infinite loop */	
//	SPI_Init();
//
//	uint16_t data = 5;
//	SPI_Send(data);

//	 SPI2->CR1 |= SPI_CR1_BR;                //Baud rate = Fpclk/256
//	 SPI2->CR1 &= ~SPI_CR1_CPOL;             //Polarity cls signal CPOL = 0;
//	 SPI2->CR1 &= ~SPI_CR1_CPHA;             //Phase cls signal    CPHA = 0;
//	 SPI2->CR1 &= ~SPI_CR1_LSBFIRST;         //MSB will be first
//	 SPI2->CR1 |= SPI_CR1_SSM | SPI_CR1_SSI;  //Software slave management & Internal slave select

	uint8_t match = 0;
	// char request[] = "1";
	uint8_t request[1] = {21};
	char answer[13] = "";

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

		HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);
		HAL_Delay(100);

		__HAL_RCC_SPI2_CLK_ENABLE();


		HAL_StatusTypeDef statusTransmit;
		statusTransmit = HAL_SPI_Transmit(&hspi2, (uint8_t *)request, strlen(request), HAL_MAX_DELAY);

		if (statusTransmit == HAL_OK)
		{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
			HAL_Delay(50);
		}

		HAL_StatusTypeDef statusReceive;
		statusReceive = HAL_SPI_Receive(&hspi2, (uint8_t *)answer, strlen(answer), HAL_MAX_DELAY);

		if (statusReceive == HAL_OK)
		{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
			HAL_Delay(50);
		}
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
		HAL_Delay(50);


		 HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);
		 HAL_Delay(100);
//
//	 	uint16_t data = 5;
//	 	SPI_Send(data);

	}
	/* USER CODE END 5 */
}

void SPI_Init()
{
	//включаем тактирование порта B и альтернативных функций 
	__HAL_RCC_SPI2_CLK_ENABLE();   

	// //13(SCK) и 15(MOSI) вывод - альтернативная функция  push pull,
	// //14(MISO) вывод - Input floating,
	// //10(CS) вывод - выход, push-pull
	// GPIOB->CRH &= ~(GPIO_CRH_CNF13_0 | GPIO_CRH_CNF15_0 | GPIO_CRH_CNF10_0);  
	// GPIOB->CRH |= GPIO_CRH_CNF13_1 | GPIO_CRH_CNF15_1;  	
	// GPIOB->CRH |= GPIO_CRH_MODE10_0 | GPIO_CRH_MODE13_1 |	GPIO_CRH_MODE15_1;

	// //включаем тактирование SPI2
	// RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;   

	// SPI2->CR1 |= SPI_CR1_BR;                //Baud rate = Fpclk/256
	// SPI2->CR1 &= ~SPI_CR1_CPOL;             //Polarity cls signal CPOL = 0;
	// SPI2->CR1 &= ~SPI_CR1_CPHA;             //Phase cls signal    CPHA = 0;
	// SPI2->CR1 |= SPI_CR1_DFF;               //16 bit data
	// SPI2->CR1 &= ~SPI_CR1_MSBFIRST;         //MSB will be first
	// SPI2->CR1 |= SPI_CR1_SSM | SPI_CR1_SSI;  //Software slave management & Internal slave select


	//Configure GPIO for SPI
	__HAL_RCC_GPIOB_CLK_ENABLE();

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	// GPIO_PIN_14: MISO
	GPIO_InitStruct.Pin = GPIO_PIN_14;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	// GPIO_PIN_15: MOSI
	GPIO_InitStruct.Pin = GPIO_PIN_15;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	// GPIO_PIN_0: NSS; GPIO_PIN_1: SCK
	__HAL_RCC_GPIOI_CLK_ENABLE();
	GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);
}

void SPI_Send(uint16_t data)
{
//  //Ждем, пока не освободится буфер передатчика
//  while(!(SPI2->SR & SPI_SR_TXE))
//    ;
//
//  //заполняем буфер передатчика
//  SPI2->DR = data;
	char message[] = "1";
  while (__HAL_SPI_GET_IT_SOURCE(&hspi2, SPI_FLAG_TXE) == RESET); // ���, ������������ SPI_DR
  	  HAL_SPI_Transmit(&hspi2, (uint8_t *)message, strlen(message), HAL_MAX_DELAY);
}
