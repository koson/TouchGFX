#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "tasks.h"
#include "interlayer.h"

// Аналоговая часть
extern volatile double m_data_AI_1; // аналоговый вход 1
extern volatile double m_data_AI_2;
extern volatile double m_data_AI_3;
extern volatile double m_data_AI_4;

// extern volatile double m_data_AO_1; // аналоговый выход 1
// extern volatile double m_data_AO_2;
// extern volatile double m_data_AO_3;
// extern volatile double m_data_AO_4;

// Дискретная часть
extern volatile bool m_data_DI_1; // дискретный вход 1
extern volatile bool m_data_DI_2;
extern volatile bool m_data_DI_3;
extern volatile bool m_data_DI_4;

extern volatile bool m_data_DO_1; // дискретный выход 1
extern volatile bool m_data_DO_2;
extern volatile bool m_data_DO_3;
extern volatile bool m_data_DO_4;

// Уставки
extern volatile double m_data_SP_AI_1; // аналоговый вход 1
extern volatile double m_data_SP_AI_2;
extern volatile double m_data_SP_AI_3;
extern volatile double m_data_SP_AI_4;

bool flag_setPoints = false;

Model::Model() : modelListener(0)
{
  m_AI.fill(0.0);
  m_AO.fill(0.0);
  m_DI.fill(0);
  m_DO.fill(0);

  m_stepPoints_AI.fill(0.0);
  m_stepPoints_AO.fill(0.0);
}

void Model::tick()
{
#ifndef SIMULATOR


    m_AI.at(0) = m_data_AI_1;
    m_AI.at(1) = m_data_AI_2;
    m_AI.at(2) = m_data_AI_3;
    m_AI.at(3) = m_data_AI_4;

    m_AO.at(0) = m_data_AO_1;
    m_AO.at(1) = m_data_AO_2;
    m_AO.at(2) = m_data_AO_3;
    m_AO.at(3) = m_data_AO_4;

    // m_DI.at(0) = m_data_DI_1;
    // m_DI.at(1) = m_data_DI_2;
    // m_DI.at(2) = m_data_DI_3;
    // m_DI.at(3) = m_data_DI_4;

    m_DO.at(0) = m_data_DO_1;
    m_DO.at(1) = m_data_DO_2;
    m_DO.at(2) = m_data_DO_3;
    m_DO.at(3) = m_data_DO_4;

    if (!flag_setPoints)
    {
      m_stepPoints_AI.at(0) = m_data_SP_AI_1;
      m_stepPoints_AI.at(1) = m_data_SP_AI_2;
      m_stepPoints_AI.at(2) = m_data_SP_AI_3;
      m_stepPoints_AI.at(3) = m_data_SP_AI_4;
    }
    flag_setPoints = true;  // use 1 one

    // Signal for update screen
    modelListener->valueIsChanged();

#endif
}


// _______________ Getters _______________


std::array<double, countAI> Model::getCurrentAI()
{
    return m_AI;
}

std::array<double, countAO> Model::getCurrentAO()
{
    return m_AO;
}

std::array<bool, countDI> Model::getCurrentDI()
{
    return m_DI;
}

std::array<bool, countDO> Model::getCurrentDO()
{
    return m_DO;
}


// _______________ Setters _______________


void Model::setCurrentAI(std::array<double, countAI> values)
{
    m_AI = values;
}

void Model::setCurrentAO(std::array<double, countAO> values)
{
    m_AO = values;
}

void Model::setCurrentDI(std::array<bool, countDI> values)
{
    m_DI = values;
}

void Model::setCurrentDO(std::array<bool, countDO> values)
{
    m_DO = values;
}

void setCurrentStepPointsAI(std::array<double, countAI>> values)
{
    m_stepPoints_AI = values;
}
