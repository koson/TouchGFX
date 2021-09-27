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
  setCount(0);
}

void Graphic_1_View::tearDownScreen()
{
}

void Graphic_1_View::increaseValue()
{
  if (count < 42)
  {
      count++;
      setCount(count);

      // if (count == 42)
      // {
      //     setLimitEffects(false, true);
      // }
      // else if (count == 1)
      // {
      //     setLimitEffects(true, true);
      // }
  }
}

void Graphic_1_View::decreaseValue()
{
  if (count > 0)
  {
      count++;
      setCount(count);

      // if (0 == count)
      // {
      //     setLimitEffects(true, false);
      // }
      // else if (41 == count)
      // {
      //     setLimitEffects(true, true);
      // }
  }
}

// void MainView::setLimitEffects(bool belowUpper, bool aboveLower)
// {
//     buttonUp.setTouchable(belowUpper);
//     buttonDown.setTouchable(aboveLower);

//     if (belowUpper)
//     {
//         buttonUp.setBitmaps(Bitmap(BITMAP_UP_BTN_ID), Bitmap(BITMAP_UP_BTN_PRESSED_ID));
//     }
//     else
//     {
//         buttonUp.setBitmaps(Bitmap(BITMAP_UP_BTN_DISABLED_ID), Bitmap(BITMAP_UP_BTN_DISABLED_ID));
//     }

//     if (aboveLower)
//     {
//         buttonDown.setBitmaps(Bitmap(BITMAP_DOWN_BTN_ID), Bitmap(BITMAP_DOWN_BTN_PRESSED_ID));
//     }
//     else
//     {
//         buttonDown.setBitmaps(Bitmap(BITMAP_DOWN_BTN_DISABLED_ID), Bitmap(BITMAP_DOWN_BTN_DISABLED_ID));
//     }

//     buttonUp.invalidate();
//     buttonDown.invalidate();
// }



void Graphic_1_View::setCount(uint8_t countValue)
{
  // Unicode::snprintf(countTxtBuffer, 3, "%d", countValue);
  // // Invalidate text area, which will result in it being redrawn in next tick.
  // countTxt.invalidate();

  setData(static_cast<uint16_t>(countValue));
}

void Graphic_1_View::setData(uint16_t data)
{
  m_local_data_sensor = data;

  Unicode::snprintf(loggerSPI_1Buffer, 200, "%d", static_cast<int>(m_local_data_sensor));
  loggerSPI_1.invalidate();

  Unicode::snprintf(loggerSPI_2Buffer, 200, "%d", static_cast<int>(m_local_data_sensor) + 7);
  loggerSPI_2.invalidate();

  Unicode::snprintf(loggerSPI_3Buffer, 200, "%d", static_cast<int>(m_local_data_sensor)  + 9);
  loggerSPI_3.invalidate();

  Unicode::snprintf(loggerSPI_4Buffer, 200, "%d", static_cast<int>(m_local_data_sensor) + 11);
  loggerSPI_4.invalidate();
}




void Graphic_1_View::handleTickEvent()
{
  tickCounter++;

  // Insert data point
  dynamicGraph1.addDataPoint(static_cast<int>(m_local_data_sensor));

  dynamicGraph2.addDataPoint(static_cast<int>(m_local_data_sensor) + 7);

  dynamicGraph3.addDataPoint(static_cast<int>(m_local_data_sensor) + 9);

  dynamicGraph4.addDataPoint(static_cast<int>(m_local_data_sensor) + 11);


  dynamicGraph1.invalidate();
  dynamicGraph2.invalidate();
  dynamicGraph3.invalidate();
  dynamicGraph4.invalidate();
}


void Graphic_1_View::userToModel()
{
  presenter->userToModel(count);
}

void Graphic_1_View::modelToView()
{
  presenter->modelToView();
}
