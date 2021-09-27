#include <gui/view/GraphView.hpp>


GraphView::GraphView()
{
    tickCounter = 0;
}


void GraphView::setCurrentValue(uint8_t value)
{
  Graphic_1_ViewBase::dg_AI_1.addDataPoint(static_cast<int>(value));
}

void GraphView::handleTickEvent()
{
    tickCounter++;

    // Insert data point
    Graphic_1_ViewBase::dg_AI_1.addDataPoint(static_cast<int>(tickCounter));
    Graphic_1_ViewBase::dg_AI_1.invalidate();
}
