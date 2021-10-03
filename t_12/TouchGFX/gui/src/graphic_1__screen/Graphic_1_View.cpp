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
  setData(0);
}

void Graphic_1_View::tearDownScreen()
{
}


void Graphic_1_View::setData(uint16_t data)
{
  m_local_data_sensor = data;

  // Unicode::snprintf(loggerSPI_1Buffer, 200, "%d", static_cast<int>(m_local_data_sensor));
  // loggerSPI_1.invalidate();
}



void Graphic_1_View::handleTickEvent()
{
  tickCounter++;

  // Insert data point
  dg_AI_1.addDataPoint(static_cast<int>(m_local_data_sensor));
  dg_setPoint_1.addDataPoint(75);

  dg_AI_1.invalidate();
  dg_setPoint_1.invalidate();
}


void Graphic_1_View::userToModel()
{
  presenter->userToModel(static_cast<uint8_t>(data));
}

void Graphic_1_View::modelToView()
{
  presenter->modelToView();
}
