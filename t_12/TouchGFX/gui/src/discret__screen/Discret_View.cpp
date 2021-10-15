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
    m_unitsAI.fill(0);

    m_DI.fill(0);
    m_DO.fill(0);

    m_date.insert("DD", 15);
    m_date.insert("MM", 10);
    m_date.insert("YYYY", 2021);

    m_time.insert("hh", 7);
    m_time.insert("mm", 44);
    m_time.insert("ss", 8);

    b_DI_1.setTouchable(false);
    b_DI_2.setTouchable(false);
    b_DI_3.setTouchable(false);
    b_DI_4.setTouchable(false);

    b_DO_1.setTouchable(false);
    b_DO_2.setTouchable(false);
    b_DO_3.setTouchable(false);
    b_DO_4.setTouchable(false);
}

void Discret_View::tearDownScreen()
{
}

void Discret_View::handleTickEvent()
{
  tickCounter++;

  // Graphic


  // Unicode::snprintf(loggerSPI_1Buffer, 200, "%d", static_cast<int>(m_AI));
  // loggerSPI_1.invalidate();
  //
  // dg_setPoint_1.invalidate();

  //  Indicators . State
  // b_DI_1.setVisible(m_DI.at(0));
  // b_DI_2.setVisible(m_DI.at(1));
  // b_DI_3.setVisible(m_DI.at(2));
  // b_DI_4.setVisible(m_DI.at(3));
  //
  // b_DO_1.setVisible(m_DO.at(0));
  // b_DO_2.setVisible(m_DO.at(1));
  // b_DO_3.setVisible(m_DO.at(2));
  // b_DO_4.setVisible(m_DO.at(3));
}

void Discret_View::modelToView()
{
  presenter->modelToView();
}

// But for this screen control function is not exist
void Discret_View::userToModel()
{
  presenter->userToModel(m_AI, m_DI, m_DO);
}





// __________________________________________________
// ______________ Additional functions ______________

void Discret_View::setCurrentAI(std::array<float, COUNT_AI> values)
{
    m_AI = values;
}

void Discret_View::setCurrentDI(std::array<uint8_t, COUNT_DI> values)
{
    m_DI = values;
}

void Discret_View::setCurrentDO(std::array<uint8_t, COUNT_DO> values)
{
    m_DO = values;
}


void Discret_View::getCurrentAI()
{

}

//void Discret_View::getCurrentAO();
void Discret_View::getCurrentDI()
{

}

void Discret_View::getCurrentDO()
{

}
