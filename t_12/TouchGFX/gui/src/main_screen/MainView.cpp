#include <gui/main_screen/MainView.hpp>
#include "BitmapDatabase.hpp"


MainView::MainView()
{
    // Support of larger displays for this example
    // is handled by showing a black box in the
    // unused part of the display.
    if (HAL::DISPLAY_WIDTH > backgroundImage.getWidth() ||
            HAL::DISPLAY_HEIGHT > backgroundImage.getHeight())
    {
        backgroundBox.setVisible(true);
    }

    tickCounter = 0;
}

void MainView::setupScreen()
{
    setCount(0);
}

void MainView::tearDownScreen()
{
}

void MainView::increaseValue()
{
    if (count < 42)
    {
        count++;
        setCount(count);

        if (count == 42)
        {
            setLimitEffects(false, true);
        }
        else if (count == 1)
        {
            setLimitEffects(true, true);
        }
    }
}

void MainView::decreaseValue()
{
    if (count > 0)
    {
        count++;
        setCount(count);

        if (0 == count)
        {
            setLimitEffects(true, false);
        }
        else if (41 == count)
        {
            setLimitEffects(true, true);
        }
    }
}

void MainView::setLimitEffects(bool belowUpper, bool aboveLower)
{
    buttonUp.setTouchable(belowUpper);
    buttonDown.setTouchable(aboveLower);

    if (belowUpper)
    {
        buttonUp.setBitmaps(Bitmap(BITMAP_UP_BTN_ID), Bitmap(BITMAP_UP_BTN_PRESSED_ID));
    }
    else
    {
        buttonUp.setBitmaps(Bitmap(BITMAP_UP_BTN_DISABLED_ID), Bitmap(BITMAP_UP_BTN_DISABLED_ID));
    }

    if (aboveLower)
    {
        buttonDown.setBitmaps(Bitmap(BITMAP_DOWN_BTN_ID), Bitmap(BITMAP_DOWN_BTN_PRESSED_ID));
    }
    else
    {
        buttonDown.setBitmaps(Bitmap(BITMAP_DOWN_BTN_DISABLED_ID), Bitmap(BITMAP_DOWN_BTN_DISABLED_ID));
    }

    buttonUp.invalidate();
    buttonDown.invalidate();
}






void MainView::setCount(uint8_t countValue)
{
    Unicode::snprintf(countTxtBuffer, 3, "%d", countValue);
    // Invalidate text area, which will result in it being redrawn in next tick.
    countTxt.invalidate();
}

void MainView::setData(uint16_t data)
{
    m_local_data_sensor = data;
    Unicode::snprintf(loggerSPIBuffer, 200, "%d", static_cast<int>(data));

    // Invalidate text area, which will result in it being redrawn in next tick.
    loggerSPI.invalidate();
}




void MainView::handleTickEvent()
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


void MainView::userToModel()
{
    presenter->userToModel(count);
}

void MainView::modelToView()
{
    presenter->modelToView();
}

