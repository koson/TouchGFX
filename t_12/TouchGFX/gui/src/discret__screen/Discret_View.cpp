#include <gui/discret__screen/Discret_View.hpp>
#include "BitmapDatabase.hpp"

Discret_View::Discret_View()
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

void Discret_View::setupScreen()
{
    // Default values
    m_AI.fill(0.0);
    m_U_AI.fill(0);

    m_DI.fill(0);
    m_DO.fill(0);

    // Analog values
    Unicode::snprintfFloat(t_AI_1Buffer, 100, "%3.2f", m_AI.at(0));
    Unicode::snprintfFloat(t_AI_2Buffer, 100, "%3.2f", m_AI.at(1));
    Unicode::snprintfFloat(t_AI_3Buffer, 100, "%3.2f", m_AI.at(2));
    Unicode::snprintfFloat(t_AI_4Buffer, 100, "%3.2f", m_AI.at(3));

    // Step points values
    Unicode::snprintfFloat(t_SP_AI_1Buffer, 100, "%3.2f", m_SP_AI.at(0));
    Unicode::snprintfFloat(t_SP_AI_2Buffer, 100, "%3.2f", m_SP_AI.at(1));
    Unicode::snprintfFloat(t_SP_AI_3Buffer, 100, "%3.2f", m_SP_AI.at(2));
    Unicode::snprintfFloat(t_SP_AI_4Buffer, 100, "%3.2f", m_SP_AI.at(3));


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


    sw_unitsAI_1.setTouchable(false);
    sw_unitsAI_2.setTouchable(false);
    sw_unitsAI_3.setTouchable(false);
    sw_unitsAI_4.setTouchable(false);
    sw_unitsSP_AI_1.setTouchable(false);
    sw_unitsSP_AI_2.setTouchable(false);
    sw_unitsSP_AI_3.setTouchable(false);
    sw_unitsSP_AI_4.setTouchable(false);

    // Date
    m_date.insert(std::pair<std::string, uint16_t>("DD", 0));
    m_date.insert(std::pair<std::string, uint16_t>("MM", 0));
    m_date.insert(std::pair<std::string, uint16_t>("YYYY", 0));

    // Time
    m_time.insert(std::pair<std::string, uint8_t>("hh", 0));
    m_time.insert(std::pair<std::string, uint8_t>("mm", 0));
    m_time.insert(std::pair<std::string, uint8_t>("ss", 0));


    // Execution ----->
    t_AI_1.invalidate();
    t_AI_2.invalidate();
    t_AI_3.invalidate();
    t_AI_4.invalidate();

    t_SP_AI_1.invalidate();
    t_SP_AI_2.invalidate();
    t_SP_AI_3.invalidate();
    t_SP_AI_4.invalidate();

    b_DI_1.invalidate();
    b_DI_2.invalidate();
    b_DI_3.invalidate();
    b_DI_4.invalidate();

    b_DO_1.invalidate();
    b_DO_2.invalidate();
    b_DO_3.invalidate();
    b_DO_4.invalidate();

    sw_unitsAI_1.invalidate();
    sw_unitsAI_2.invalidate();
    sw_unitsAI_3.invalidate();
    sw_unitsAI_4.invalidate();

    sw_unitsSP_AI_1.invalidate();
    sw_unitsSP_AI_2.invalidate();
    sw_unitsSP_AI_3.invalidate();
    sw_unitsSP_AI_4.invalidate();
}

void Discret_View::tearDownScreen()
{
}

void Discret_View::handleTickEvent()
{
  tickCounter++;

  // Analog values
  Unicode::snprintfFloat(t_AI_1Buffer, 100, "%3.2f", m_AI.at(0));
  Unicode::snprintfFloat(t_AI_2Buffer, 100, "%3.2f", m_AI.at(1));
  Unicode::snprintfFloat(t_AI_3Buffer, 100, "%3.2f", m_AI.at(2));
  Unicode::snprintfFloat(t_AI_4Buffer, 100, "%3.2f", m_AI.at(3));

  // Step points values
  if (m_SP_AI.at(0) > 0.0)
  {
    Unicode::snprintfFloat(t_SP_AI_1Buffer, 100, "%3.2f", m_SP_AI.at(0));
  }
  else
  {
    t_SP_AI_1.setVisible(false);
  }

  if (m_SP_AI.at(1) > 0.0)
  {
    Unicode::snprintfFloat(t_SP_AI_2Buffer, 100, "%3.2f", m_SP_AI.at(1));
  }
  else
  {
    t_SP_AI_2.setVisible(false);
  }

  if (m_SP_AI.at(2) > 0.0)
  {
    Unicode::snprintfFloat(t_SP_AI_3Buffer, 100, "%3.2f", m_SP_AI.at(2));
  }
  else
  {
    t_SP_AI_3.setVisible(false);
  }

  if (m_SP_AI.at(3) > 0.0)
  {
    Unicode::snprintfFloat(t_SP_AI_4Buffer, 100, "%3.2f", m_SP_AI.at(3));
  }
  else
  {
    t_SP_AI_4.setVisible(false);
  }

  int16_t l_offset = 0;
  sw_unitsAI_1.setSelectedItemOffset(l_offset);
  sw_unitsAI_2.setSelectedItemOffset(l_offset + 28);
  sw_unitsAI_3.setSelectedItemOffset(l_offset + 62);
  sw_unitsAI_4.setSelectedItemOffset(l_offset + 95);
  sw_unitsSP_AI_1.setSelectedItemOffset(l_offset);
  sw_unitsSP_AI_2.setSelectedItemOffset(l_offset + 28);
  sw_unitsSP_AI_3.setSelectedItemOffset(l_offset + 62);
  sw_unitsSP_AI_4.setSelectedItemOffset(l_offset + 95);

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
  // Unicode::UnicodeChar buffer[20];

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
  t_AI_2.invalidate();
  t_AI_3.invalidate();
  t_AI_4.invalidate();

  t_SP_AI_1.invalidate();
  t_SP_AI_2.invalidate();
  t_SP_AI_3.invalidate();
  t_SP_AI_4.invalidate();

  b_DI_1.invalidate();
  b_DI_2.invalidate();
  b_DI_3.invalidate();
  b_DI_4.invalidate();

  b_DO_1.invalidate();
  b_DO_2.invalidate();
  b_DO_3.invalidate();
  b_DO_4.invalidate();

  sw_unitsAI_1.invalidate();
  sw_unitsAI_2.invalidate();
  sw_unitsAI_3.invalidate();
  sw_unitsAI_4.invalidate();

  sw_unitsSP_AI_1.invalidate();
  sw_unitsSP_AI_2.invalidate();
  sw_unitsSP_AI_3.invalidate();
  sw_unitsSP_AI_4.invalidate();

  lb_date.invalidate();
  lb_time.invalidate();
}

void Discret_View::modelToView()
{
  presenter->modelToView();
}

// But for this screen control function is not exist
void Discret_View::userToModel()
{
  presenter->userToModel(m_AI, m_SP_AI, m_U_AI, m_DI, m_DO, m_date, m_time);
}





// __________________________________________________
// ______________ Additional functions ______________

void Discret_View::setCurrentAI(std::array<float, COUNT_AI> values)
{
    m_AI = values;
}

void Discret_View::setCurrentStepPointsAI(std::array<float, COUNT_AI> values)
{
    m_SP_AI = values;
}

void Discret_View::setCurrentUnitsAI(std::array<uint8_t, COUNT_AI> values)
{
    m_U_AI = values;
}

void Discret_View::setCurrentDI(std::array<uint8_t, COUNT_DI> values)
{
    m_DI = values;
}

void Discret_View::setCurrentDO(std::array<uint8_t, COUNT_DO> values)
{
    m_DO = values;
}



void Discret_View::setCurrentDate(std::map<std::string, uint16_t> values)
{
    m_date = values;
}

void Discret_View::setCurrentTime(std::map<std::string, uint8_t> values)
{
    m_time = values;
}




std::array<float, COUNT_AI> Discret_View::getCurrentAI()
{

}

std::array<float, COUNT_AI> Discret_View::getCurrentStepPointsAI()
{

}

std::array<uint8_t, COUNT_AI> Discret_View::getCurrentUnitsAI()
{

}

//std::array<float, COUNT_AO> getCurrentAO();

std::array<uint8_t, COUNT_DI> Discret_View::getCurrentDI()
{

}

std::array<uint8_t, COUNT_DO> Discret_View::getCurrentDO()
{

}



std::map<std::string, uint16_t> Discret_View::getCurrentDate()
{

}

std::map<std::string, uint8_t> Discret_View::getCurrentTime()
{

}
