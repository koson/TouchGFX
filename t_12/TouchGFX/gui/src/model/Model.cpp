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

    userToModel(m_data_sensor);
    
    modelListener->valueIsChanged();

#endif
}

uint8_t Model::getCurrentValue()
{
    return m_local_data_sensor;
}

void Model::userToModel(uint8_t value)
{
    m_local_data_sensor = value;
}
