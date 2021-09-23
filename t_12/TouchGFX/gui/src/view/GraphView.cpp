#include <gui/view/GraphView.hpp>


GraphView::GraphView()
{
    tickCounter = 0;
}


void GraphView::setCurrentValue(uint8_t value)
{
  MainViewBase::dynamicGraph1.addDataPoint(static_cast<int>(value));
}

void GraphView::handleTickEvent()
{
    tickCounter++;

    // Insert data point
    MainViewBase::dynamicGraph1.addDataPoint(static_cast<int>(tickCounter));
    MainViewBase::dynamicGraph1.invalidate();
}
