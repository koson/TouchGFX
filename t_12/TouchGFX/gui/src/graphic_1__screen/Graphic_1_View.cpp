#include <gui/graphic_1__screen/Graphic_1_View.hpp>
#include "BitmapDatabase.hpp"

uint16_t decimalsX = 0, decimalsY = 2;

float yMin = 0.0, yMax = 100.0;
int xMin = 0, xMax = 6; // 60 sec = 1 min
float intervalX = 1, intervalY = 20; // 13 - item time's ; 5 item values to graphic


enum freqUpdate {sec, min1, min5, min15, min30, hour1, hour4, day1, day7, mon1};
freqUpdate currentFreqUpdateGraph(sec);
// struct tm {
//    int tm_sec;   // seconds of minutes from 0 to 61
//    int tm_min;   // minutes of hour from 0 to 59
//    int tm_hour;  // hours of day from 0 to 24
//    int tm_mday;  // day of month from 1 to 31
//    int tm_mon;   // month of year from 0 to 11
//    int tm_year;  // year since 1900
//    int tm_wday;  // days since sunday
//    int tm_yday;  // days since January 1st
//    int tm_isdst; // hours of daylight savings time
// }

// current date/time based on current system
 time_t now = time(0);
 tm *ltm = localtime(&now);

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

    // Graphic
    dg_AI_1.setGraphRange(xMin, xMax, yMin, yMax);

    dg_AI_1MajorXAxisLabel.setInterval(intervalX);
    dg_AI_1MajorYAxisLabel.setInterval(intervalY);

    dg_AI_1MajorXAxisLabel.setLabelDecimals(decimalsX);
    dg_AI_1MajorYAxisLabel.setLabelDecimals(decimalsY);
    //dg_AI_1.setLabelDecimalPoint(decimalPoint);

    dg_AI_1MajorXAxisGrid.setInterval(intervalX);
    dg_AI_1MajorYAxisGrid.setInterval(intervalY / 2);

    // Between label and graph
    dg_AI_1.setGraphAreaPadding(0, 5, 0, 0); // top, left, right, bottom

    dg_AI_1.setGraphAreaMargin(10, 35, 20, 30); // top, left, right, bottom

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

    // Indicators. SD, RS, PRG
    rb_SD.setTouchable(false);
    rb_RS.setTouchable(false);
    rb_PRG.setTouchable(false);

    // Analog values
    Unicode::snprintfFloat(t_AI_1Buffer, 100, "%3.2f", m_AI);

    // Step points values
    Unicode::snprintfFloat(t_SP_AI_1Buffer, 100, "%3.2f", m_SP_AI);

    sw_unitsAI_1.setTouchable(false);

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

  if (static_cast<int>(m_AI) > (yMax - 10))
  {
    float dy = 5.0;
    yMin += dy; yMax += dy;

    dg_AI_1.setGraphRange(xMin, xMax, yMin, yMax);
  }
  else if (static_cast<int>(m_AI) < (yMin + 10))
  {
    float dy = 5.0;
    yMin -= dy; yMax -= dy;

    dg_AI_1.setGraphRange(xMin, xMax, yMin, yMax);
  }


  // if (static_cast<uint16_t>(dg_AI_1MajorXAxisLabel.getLabelDecimals()) > (xMax - 10))
  // {
  //   int dx = 50;
  //   xMin += dx; xMax += dx;
  //
  //   dg_AI_1.setGraphRange(xMin, xMax, yMin, yMax);
  // }

  if ( (currentFreqUpdateGraph == sec) )
  {
    if (tickCounter % 60000)
    {
      //dg_AI_1.clear();

      if (dg_AI_1.addDataPoint(m_AI) >= 200)
        dg_AI_1.clear();

      // TypedText typedText;
      // dg_AI_1MajorXAxisLabel.setLabelTypedText(typedText);
      tickCounter = 0;

      // xMin = 0; xMax = 60;
      // dg_AI_1.setGraphRange(xMin, xMax, yMin, yMax);
    }

  }



  // Graphic

  //Unicode::UnicodeChar decimalPoint;



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
                     std::to_string(static_cast<unsigned>(1952 + ltm->tm_year));//m_date.at("YYYY")));


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
