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
    m_SP_AI = 0;

    m_DI.fill(0);
    m_DO.fill(0);

    b_DI_1.setTouchable(false);
    b_DI_2.setTouchable(false);
    b_DI_3.setTouchable(false);
    b_DI_4.setTouchable(false);

    b_DO_1.setTouchable(false);
    b_DO_2.setTouchable(false);
    b_DO_3.setTouchable(false);
    b_DO_4.setTouchable(false);
}

void Graphic_1_View::tearDownScreen()
{
}

void Graphic_1_View::handleTickEvent()
{
    tickCounter++;

    // Graphic
    dg_AI_1.addDataPoint(static_cast<int>(m_AI));
    dg_setPoint_1.addDataPoint(m_SP_AI);

    dg_AI_1.invalidate();
    dg_setPoint_1.invalidate();

    //  Indicators . State
    b_DI_1.setVisible(m_DI.at(0));
    b_DI_2.setVisible(m_DI.at(1));
    b_DI_3.setVisible(m_DI.at(2));
    b_DI_4.setVisible(m_DI.at(3));

    b_DO_1.setVisible(m_DO.at(0));
    b_DO_2.setVisible(m_DO.at(1));
    b_DO_3.setVisible(m_DO.at(2));
    b_DO_4.setVisible(m_DO.at(3));

}


void Graphic_1_View::userToModel(uint16_t value)
{
  //presenter->userToModel(static_cast<uint8_t>(data));
}

void Graphic_1_View::modelToView()
{
    presenter->modelToView();
}


// __________________________________________________
// ______________ Additional functions ______________

void Graphic_1_View::setCurrentAI(std::array<float, COUNT_AI> values)
{
    m_AI = values.at(0);
}

void Graphic_1_View::setCurrentDI(std::array<uint8_t, COUNT_DI> values)
{
    m_DI = values;
}

void Graphic_1_View::setCurrentDO(std::array<uint8_t, COUNT_DO> values)
{
    m_DO = values;
}

void Graphic_1_View::setCurrentStepPointsAI(std::array<float, COUNT_AI> values)
{
    m_SP_AI = values.at(0);
}
