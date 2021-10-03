#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "tasks.h"
#include "interlayer.h"

// Аналоговая часть
extern volatile uint16_t m_data_AI_1; // аналоговый вход 1
extern volatile uint16_t m_data_AI_2;
extern volatile uint16_t m_data_AI_3;
extern volatile uint16_t m_data_AI_4;

// Дискретная часть
extern volatile uint16_t m_data_DI_1; // дискретный вход 1
extern volatile uint16_t m_data_DI_2;
extern volatile uint16_t m_data_DI_3;
extern volatile uint16_t m_data_DI_4;

extern volatile uint16_t m_data_DO_1; // дискретный выход 1
extern volatile uint16_t m_data_DO_2;
extern volatile uint16_t m_data_DO_3;
extern volatile uint16_t m_data_DO_4;

Model::Model() : modelListener(0), m_local_data_sensor(0)
{
}

void Model::tick()
{
#ifndef SIMULATOR

    userToModel(m_data_AI_1);
    userToModel(m_data_AI_2);
    userToModel(m_data_AI_3);
    userToModel(m_data_AI_4);

    userToModel(m_data_DI_1);
    userToModel(m_data_DI_2);
    userToModel(m_data_DI_3);
    userToModel(m_data_DI_4);

    userToModel(m_data_DO_1);
    userToModel(m_data_DO_2);
    userToModel(m_data_DO_3);
    userToModel(m_data_DO_4);


    modelListener->valueIsChanged();

#endif
}

uint8_t Model::getCurrentValue()
{
    return m_local_data_sensor;
}

void Model::userToModel(uint16_t value)
{
    m_local_data_sensor = value;
}
