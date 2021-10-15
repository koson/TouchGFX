#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

//#include "tasks.h"
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

// Units analog signal --> temperature(Celsius, Kelvin, Faradey), humidity(%, ), ...
extern volatile uint8_t m_data_U_AI_1;
extern volatile uint8_t m_data_U_AI_2;
extern volatile uint8_t m_data_U_AI_3;
extern volatile uint8_t m_data_U_AI_4;

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



// Date
extern volatile uint16_t m_date_D;
extern volatile uint16_t m_date_M;
extern volatile uint16_t m_date_Y;

// Time
extern volatile uint8_t m_time_h;
extern volatile uint8_t m_time_m;
extern volatile uint8_t m_time_s;

uint8_t flag_initialState = 0;  // false

Model::Model() : modelListener(0)
{
  m_AI.fill(0.0);
  m_AO.fill(0.0);
  m_DI.fill(0);
  m_DO.fill(0);

  // Step points
  m_SP_AI.fill(0.0);

  // Units analog signal --> temperature(Celsius, Kelvin, Faradey), humidity(%, ), ...
  m_U_AI.fill(0.0);

  // Types AI --> 50М, 100P, Pt100, Pt1000, L, K, J, S, B, 0..20mA, 4..20mA, 0..10V
  m_T_AI.fill(0);

  // Mode processing AI --> 0:"absolut"; 1:"difference"; 2:"average"
  m_MP_AI.fill(0);

  // Function DI --> 0:"STOP"; 1:"START/STOP"; 2:"Reset commit";
  m_F_DI.fill(0);

  // Mode control DO --> 0:"ON/OFF"; 1:"Signaling device"; 2:"Manual control";
  m_MC_DO.fill(0);


  // Date
  m_date.insert(std::pair<std::string, uint16_t>("DD", 0));
  m_date.insert(std::pair<std::string, uint16_t>("MM", 0));
  m_date.insert(std::pair<std::string, uint16_t>("YYYY", 0));

  // Time
  m_time.insert(std::pair<std::string, uint16_t>("hh", 0));
  m_time.insert(std::pair<std::string, uint16_t>("mm", 0));
  m_time.insert(std::pair<std::string, uint16_t>("ss", 0));
}

void Model::tick()
{
#ifndef SIMULATOR

    m_AI.at(0) = m_data_AI_1;
    m_AI.at(1) = m_data_AI_2;
    m_AI.at(2) = m_data_AI_3;
    m_AI.at(3) = m_data_AI_4;

    // m_AO.at(0) = m_data_AO_1;
    // m_AO.at(1) = m_data_AO_2;
    // m_AO.at(2) = m_data_AO_3;
    // m_AO.at(3) = m_data_AO_4;

    m_DI.at(0) = m_data_DI_1;
    m_DI.at(1) = m_data_DI_2;
    m_DI.at(2) = m_data_DI_3;
    m_DI.at(3) = m_data_DI_4;

    m_DO.at(0) = m_data_DO_1;
    m_DO.at(1) = m_data_DO_2;
    m_DO.at(2) = m_data_DO_3;
    m_DO.at(3) = m_data_DO_4;

    // Date
    m_date["DD"] = m_date_D;
    m_date["MM"] = m_date_M;
    m_date["YYYY"] = m_date_Y;

    // Time
    m_time["hh"] = m_time_h;
    m_time["mm"] = m_time_m;
    m_time["ss"] = m_time_s;

    if (!flag_initialState)
    {
      m_SP_AI.at(0) = m_data_SP_AI_1;
      m_SP_AI.at(1) = m_data_SP_AI_2;
      m_SP_AI.at(2) = m_data_SP_AI_3;
      m_SP_AI.at(3) = m_data_SP_AI_4;

      m_U_AI.at(0) = m_data_U_AI_1;
      m_U_AI.at(1) = m_data_U_AI_2;
      m_U_AI.at(2) = m_data_U_AI_3;
      m_U_AI.at(3) = m_data_U_AI_4;

      m_T_AI.at(0) = m_data_T_AI_1;
      m_T_AI.at(1) = m_data_T_AI_2;
      m_T_AI.at(2) = m_data_T_AI_3;
      m_T_AI.at(3) = m_data_T_AI_4;

      m_MP_AI.at(0) = m_data_MP_AI_1;
      m_MP_AI.at(1) = m_data_MP_AI_2;
      m_MP_AI.at(2) = m_data_MP_AI_3;
      m_MP_AI.at(3) = m_data_MP_AI_4;

      m_F_DI.at(0) = m_data_F_DI_1;
      m_F_DI.at(1) = m_data_F_DI_2;
      m_F_DI.at(2) = m_data_F_DI_3;
      m_F_DI.at(3) = m_data_F_DI_4;

      m_MC_DO.at(0) = m_data_MC_DO_1;
      m_MC_DO.at(1) = m_data_MC_DO_2;
      m_MC_DO.at(2) = m_data_MC_DO_3;
      m_MC_DO.at(3) = m_data_MC_DO_4;
    }
    flag_initialState = 1;  // true. Used 1 one

    // Signal for update screen
    modelListener->valueIsChanged();

#endif
}


// _______________ Getters _______________


std::array<float, COUNT_AI> Model::getCurrentAI()
{
    return m_AI;
}

std::array<float, COUNT_AO> Model::getCurrentAO()
{
    return m_AO;
}

std::array<uint8_t, COUNT_DI> Model::getCurrentDI()
{
    return m_DI;
}

std::array<uint8_t, COUNT_DO> Model::getCurrentDO()
{
    return m_DO;
}

std::array<float, COUNT_AI> Model::getCurrentStepPointsAI()
{
    return m_SP_AI;
}

std::array<uint8_t, COUNT_AI> Model::getCurrentUnitsAI()
{
    return m_U_AI;
}

std::array<uint8_t, COUNT_AI> Model::getCurrentTypeAI()
{
    return m_T_AI;
}

std::array<uint8_t, COUNT_AI> Model::getCurrentModeProcessingAI()
{
    return m_MP_AI;
}

std::array<uint8_t, COUNT_DI> Model::getCurrentFunctionDI()
{
    return m_F_DI;
}

std::array<uint8_t, COUNT_DO> Model::getCurrentModeControlDO()
{
    return m_MC_DO;
}




std::map<std::string, uint16_t> Model::getCurrentDate()
{
    return m_date;
}

std::map<std::string, uint8_t> Model::getCurrentTime()
{
    return m_time;
}



// _______________ Setters _______________




void Model::setCurrentAI(std::array<float, COUNT_AI> values)
{
    m_AI = values;
}

void Model::setCurrentAO(std::array<float, COUNT_AO> values)
{
    m_AO = values;
}

void Model::setCurrentDI(std::array<uint8_t, COUNT_DI> values)
{
    m_DI = values;
}

void Model::setCurrentDO(std::array<uint8_t, COUNT_DO> values)
{
    m_DO = values;
}

void Model::setCurrentStepPointsAI(std::array<float, COUNT_AI> values)
{
    m_SP_AI = values;
}

void Model::setCurrentUnitsAI(std::array<uint8_t, COUNT_AI> values)
{
    m_U_AI = values;
}

void Model::setCurrentTypeAI(std::array<uint8_t, COUNT_AI> values)
{
    m_T_AI = values;
}

void Model::setCurrentModeProcessingAI(std::array<uint8_t, COUNT_AI> values)
{
    m_MP_AI = values;
}

void Model::setCurrentFunctionDI(std::array<uint8_t, COUNT_DI> values)
{
    m_F_DI = values;
}

void Model::setCurrentModeControlDO(std::array<uint8_t, COUNT_DO> values)
{
    m_MC_DO = values;
}



void Model::setCurrentDate(std::map<std::string, uint16_t> values)
{
    m_date = values;
}

void Model::setCurrentTime(std::map<std::string, uint8_t> values)
{
    m_time = values;
}
