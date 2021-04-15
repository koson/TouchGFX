#ifndef TASKS_H
#define TASKS_H

#include <stdint.h>
#include <string.h>

#include "cmsis_os.h"
#include "stm32f7xx_hal.h"


void settingsAndCreateThread(const char *fnc_name, void (*fnc)(void *), void *arg_0);

void GPIO_Task(void *arg);
void SPI_Task(void *arg);




#endif // TASKS_H