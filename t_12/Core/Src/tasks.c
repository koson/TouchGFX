#include "tasks.h"
#include "interlayer.h"

// Analog part
extern volatile float m_data_AI_1; // analog input 1
extern volatile float m_data_AI_2;
extern volatile float m_data_AI_3;
extern volatile float m_data_AI_4;

// extern volatile float m_data_AO_1; // analog output 1
// extern volatile float m_data_AO_2;
// extern volatile float m_data_AO_3;
// extern volatile float m_data_AO_4;

// Discret part
extern volatile uint8_t m_data_DI_1; // discret input 1
extern volatile uint8_t m_data_DI_2;
extern volatile uint8_t m_data_DI_3;
extern volatile uint8_t m_data_DI_4;

extern volatile uint8_t m_data_DO_1; // discret output 1
extern volatile uint8_t m_data_DO_2;
extern volatile uint8_t m_data_DO_3;
extern volatile uint8_t m_data_DO_4;



// Step points
extern volatile float m_data_SP_AI_1; // analog input 1
extern volatile float m_data_SP_AI_2;
extern volatile float m_data_SP_AI_3;
extern volatile float m_data_SP_AI_4;

// Types AI --> 50М, 100P, Pt100, Pt1000, L, K, J, S, B, 0..20mA, 4..20mA, 0..10V
extern volatile uint8_t m_data_T_AI_1;
extern volatile uint8_t m_data_T_AI_2;
extern volatile uint8_t m_data_T_AI_3;
extern volatile uint8_t m_data_T_AI_4;



// Mode processing AI --> 0:"absolut"; 1:"difference"; 2:"average"
extern volatile uint8_t m_data_MP_AI_1;
extern volatile uint8_t m_data_MP_AI_2;
extern volatile uint8_t m_data_MP_AI_3;
extern volatile uint8_t m_data_MP_AI_4;

// Function DI --> 0:"STOP"; 1:"START/STOP"; 2:"Reset commit";
extern volatile uint8_t m_data_F_DI_1;
extern volatile uint8_t m_data_F_DI_2;
extern volatile uint8_t m_data_F_DI_3;
extern volatile uint8_t m_data_F_DI_4;

// Mode control DO --> 0:"ON/OFF"; 1:"Signaling device"; 2:"Manual control";
extern volatile uint8_t m_data_MC_DO_1;
extern volatile uint8_t m_data_MC_DO_2;
extern volatile uint8_t m_data_MC_DO_3;
extern volatile uint8_t m_data_MC_DO_4;

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
	uint8_t answer_ptr[4];	// 4 bytes

	uint16_t cnt = 4;	// 4 bytes

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
		
		// Crutches

		m_data_sensor = (*answer_ptr);
		m_data_AI_1 = (*answer_ptr) + 0.0;	//(((float)m_data_sensor) / ((float)0xFF)); // conversation(uint8_t to float) and normalization(0 => 0.0; 127 => 0.498; 255 => 1.0;)
		m_data_AI_2 = (*answer_ptr) + 10.0;
		m_data_AI_3 = (*answer_ptr) + 20.0;
		m_data_AI_4 = (*answer_ptr) + 30.0;

		m_data_DI_1 = 1;
		m_data_DI_2 = 1;
		m_data_DI_3 = 0;
		m_data_DI_4 = 1;

		m_data_DO_1 = 0;
		m_data_DO_2 = 1;
		m_data_DO_3 = 0;
		m_data_DO_4 = 0;

		m_data_SP_AI_1 = 35.0;
		m_data_SP_AI_2 = 55.0;
		m_data_SP_AI_3 = 75.0;
		m_data_SP_AI_4 = 95.0;

		uint8_t right_answer = 0x06;		
		if ((prev_answer != (*answer_ptr)) && (statusTransmitReceive == HAL_OK) )
		{
			prev_answer = (*answer_ptr);

			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
			HAL_Delay(100);
		}
		
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
		HAL_Delay(100);





// // Send to Core

// // Types AI --> 50М, 100P, Pt100, Pt1000, L, K, J, S, B, 0..20mA, 4..20mA, 0..10V
// extern volatile uint8_t m_data_type_AI_1;
// extern volatile uint8_t m_data_type_AI_2;
// extern volatile uint8_t m_data_type_AI_3;
// extern volatile uint8_t m_data_type_AI_4;

// // Mode processing AI --> 0:"absolut"; 1:"difference"; 2:"average"
// extern volatile uint8_t m_data_type_AI_1;
// extern volatile uint8_t m_data_type_AI_2;
// extern volatile uint8_t m_data_type_AI_3;
// extern volatile uint8_t m_data_type_AI_4;

// // Function DI --> 0:"STOP"; 1:"START/STOP"; 2:"Reset commit";
// extern volatile uint8_t m_data_function_DI_1;
// extern volatile uint8_t m_data_function_DI_2;
// extern volatile uint8_t m_data_function_DI_3;
// extern volatile uint8_t m_data_function_DI_4;

// // Mode control DO --> 0:"ON/OFF"; 1:"Signaling device"; 2:"Manual control";
// extern volatile uint8_t m_data_mode_DO_1;
// extern volatile uint8_t m_data_mode_DO_2;
// extern volatile uint8_t m_data_mode_DO_3;
// extern volatile uint8_t m_data_mode_DO_4;

	}
	/* USER CODE END 5 */
}