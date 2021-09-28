#include <gui/view/View.hpp>


View::View()
{
    tickCounter = 0;
}


void View::setCurrentValue(uint8_t value)
{
  Graphic_1_ViewBase::dg_AI_1.addDataPoint(static_cast<int>(value));
}

void View::handleTickEvent()
{
    tickCounter++;

    // Insert data point
    Graphic_1_ViewBase::dg_AI_1.addDataPoint(static_cast<int>(tickCounter));
    Graphic_1_ViewBase::dg_AI_1.invalidate();
}
