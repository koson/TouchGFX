#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "tasks.h"

extern volatile uint8_t m_data_sensor;

Model::Model() : modelListener(0), m_local_data_sensor(0)
{
}

void Model::tick()
{
#ifndef SIMULATOR

    setCurrentValue(m_data_sensor);
    
    modelListener->notifyValueChanged(getCurrentValue());

#endif
}

uint8_t Model::getCurrentValue() const
{
    return m_local_data_sensor;
}

void Model::setCurrentValue(uint8_t val)
{
    m_local_data_sensor = val;
}
