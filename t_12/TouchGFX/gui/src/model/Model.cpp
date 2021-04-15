#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "tasks.h"

Model::Model() : modelListener(0), m_current_value_sensor(0), poolLightState(false), poolTemperature(18)
{
    updatePoolLight();
}

void Model::tick()
{
#ifndef SIMULATOR
    //poll blue push button
    static uint32_t old = 0;
    uint32_t state = BSP_PB_GetState(BUTTON_KEY);
    if (state != old)
    {
        old = state;
        if (state == 0) //released
        {
            poolTemperature++;
            if (poolTemperature>28) poolTemperature = 28;
            modelListener->poolTemperatureChanged();
        }
    }
#endif
}

void Model::userSetPoolLight(bool state)
{
    poolLightState = state;
    updatePoolLight();
}

void Model::userSetTemperature(uint32_t temp)
{
    poolTemperature = temp;
}

void Model::updatePoolLight()
{
#ifndef SIMULATOR
    if (poolLightState)
    {
        BSP_LED_On(LED_GREEN);
    }
    else
    {
        BSP_LED_Off(LED_GREEN);
    }    
#endif
}
