#include <gui/graphic_1__screen/Graphic_1_View.hpp>
#include "BitmapDatabase.hpp"

Graphic_1_View::Graphic_1_View()
{
  // Support of larger displays for this example
  // is handled by showing a black box in the
  // unused part of the display.
  // if (HAL::DISPLAY_WIDTH > backgroundImage.getWidth() ||
  //         HAL::DISPLAY_HEIGHT > backgroundImage.getHeight())
  // {
  //     backgroundBox.setVisible(true);
  // }

  tickCounter = 0;
}

void Graphic_1_View::setupScreen()
{
    m_AI = 0.0;
    m_SP_AI = 0.0;
    m_U_AI = 0;

    m_DI.fill(0);
    m_DO.fill(0);

    // Date
    m_date.insert(std::pair<std::string, uint16_t>("DD", 0));
    m_date.insert(std::pair<std::string, uint16_t>("MM", 0));
    m_date.insert(std::pair<std::string, uint16_t>("YYYY", 0));

    // Time
    m_time.insert(std::pair<std::string, uint8_t>("hh", 0));
    m_time.insert(std::pair<std::string, uint8_t>("mm", 0));
    m_time.insert(std::pair<std::string, uint8_t>("ss", 0));


    // Indicators . State
    b_DI_1.forceState(m_DI.at(0));
    b_DI_2.forceState(m_DI.at(1));
    b_DI_3.forceState(m_DI.at(2));
    b_DI_4.forceState(m_DI.at(3));

    b_DO_1.forceState(m_DO.at(0));
    b_DO_2.forceState(m_DO.at(1));
    b_DO_3.forceState(m_DO.at(2));
    b_DO_4.forceState(m_DO.at(3));

    b_DI_1.setTouchable(false);
    b_DI_2.setTouchable(false);
    b_DI_3.setTouchable(false);
    b_DI_4.setTouchable(false);

    b_DO_1.setTouchable(false);
    b_DO_2.setTouchable(false);
    b_DO_3.setTouchable(false);
    b_DO_4.setTouchable(false);


    // Analog values
    Unicode::snprintfFloat(t_AI_1Buffer, 100, "%3.2f", m_AI);

    // Step points values
    Unicode::snprintfFloat(t_SP_AI_1Buffer, 100, "%3.2f", m_SP_AI);

    sw_unitsAI_1.setTouchable(false);

    // Execution ----->
    t_AI_1.invalidate();

    t_SP_AI_1.invalidate();

    b_DI_1.invalidate();
    b_DI_2.invalidate();
    b_DI_3.invalidate();
    b_DI_4.invalidate();

    b_DO_1.invalidate();
    b_DO_2.invalidate();
    b_DO_3.invalidate();
    b_DO_4.invalidate();

    sw_unitsAI_1.invalidate();
}

void Graphic_1_View::tearDownScreen()
{
}

void Graphic_1_View::handleTickEvent()
{
  tickCounter++;


  // Analog values
  Unicode::snprintfFloat(t_AI_1Buffer, 100, "%3.2f", m_AI);

  // Step points values
  if (m_SP_AI > 0.0)
  {
    Unicode::snprintfFloat(t_SP_AI_1Buffer, 100, "%3.2f", m_SP_AI);
  }
  else
  {
    t_SP_AI_1.setVisible(false);
  }

  // Graphic
  if ( (tickCounter % 500) == 0 )
  {
      dg_AI_1.setScale(1);
      tickCounter = 0;
  }

  dg_AI_1.addDataPoint(static_cast<int>(m_AI));



  int16_t l_offset = 0;
  sw_unitsAI_1.setSelectedItemOffset(l_offset);

  // Indicators . State
  b_DI_1.forceState(m_DI.at(0));
  b_DI_2.forceState(m_DI.at(1));
  b_DI_3.forceState(m_DI.at(2));
  b_DI_4.forceState(m_DI.at(3));

  b_DO_1.forceState(m_DO.at(0));
  b_DO_2.forceState(m_DO.at(1));
  b_DO_3.forceState(m_DO.at(2));
  b_DO_4.forceState(m_DO.at(3));


  size_t l_sizeBuffer = 20;
  Unicode::UnicodeChar* buffer = new Unicode::UnicodeChar(l_sizeBuffer);

  // Date
  std::string date = std::to_string(static_cast<unsigned>(m_date.at("DD"))) + "/" +
                     std::to_string(static_cast<unsigned>(m_date.at("MM"))) + "/" +
                     std::to_string(static_cast<unsigned>(m_date.at("YYYY")));


  Unicode::strncpy(buffer, date.c_str(), l_sizeBuffer);
  Unicode::snprintf(lb_dateBuffer, l_sizeBuffer, "%s", buffer);

  // Time
  std::string time = std::to_string(static_cast<unsigned>(m_time.at("hh"))) + ":" +
                     std::to_string(static_cast<unsigned>(m_time.at("mm"))) + ":" +
                     std::to_string(static_cast<unsigned>(m_time.at("ss")));

  memset(buffer, 0, l_sizeBuffer);
  Unicode::strncpy(buffer, time.c_str(), l_sizeBuffer);
  Unicode::snprintf(lb_timeBuffer, l_sizeBuffer, "%s", buffer);

  // Execution ----->
  t_AI_1.invalidate();

  t_SP_AI_1.invalidate();

  dg_AI_1.invalidate();

  b_DI_1.invalidate();
  b_DI_2.invalidate();
  b_DI_3.invalidate();
  b_DI_4.invalidate();

  b_DO_1.invalidate();
  b_DO_2.invalidate();
  b_DO_3.invalidate();
  b_DO_4.invalidate();

  sw_unitsAI_1.invalidate();

  lb_date.invalidate();
  lb_time.invalidate();
}

void Graphic_1_View::modelToView()
{
  presenter->modelToView();
}

void Graphic_1_View::userToModel()
{
  presenter->userToModel(m_AI, m_SP_AI, m_U_AI, m_DI, m_DO, m_date, m_time);
}





// __________________________________________________
// ______________ Additional functions ______________

void Graphic_1_View::setCurrentAI(std::array<float, COUNT_AI> values)
{
    m_AI = values.at(0);
}

void Graphic_1_View::setCurrentStepPointsAI(std::array<float, COUNT_AI> values)
{
    m_SP_AI = values.at(0);
}

void Graphic_1_View::setCurrentUnitsAI(std::array<uint8_t, COUNT_AI> values)
{
    m_U_AI = values.at(0);
}

void Graphic_1_View::setCurrentDI(std::array<uint8_t, COUNT_DI> values)
{
    m_DI = values;
}

void Graphic_1_View::setCurrentDO(std::array<uint8_t, COUNT_DO> values)
{
    m_DO = values;
}



void Graphic_1_View::setCurrentDate(std::map<std::string, uint16_t> values)
{
    m_date = values;
}

void Graphic_1_View::setCurrentTime(std::map<std::string, uint8_t> values)
{
    m_time = values;
}




std::array<float, COUNT_AI> Graphic_1_View::getCurrentAI()
{

}

std::array<float, COUNT_AI> Graphic_1_View::getCurrentStepPointsAI()
{

}

std::array<uint8_t, COUNT_AI> Graphic_1_View::getCurrentUnitsAI()
{

}

//std::array<float, COUNT_AO> getCurrentAO();

std::array<uint8_t, COUNT_DI> Graphic_1_View::getCurrentDI()
{

}

std::array<uint8_t, COUNT_DO> Graphic_1_View::getCurrentDO()
{

}



std::map<std::string, uint16_t> Graphic_1_View::getCurrentDate()
{

}

std::map<std::string, uint8_t> Graphic_1_View::getCurrentTime()
{

}
