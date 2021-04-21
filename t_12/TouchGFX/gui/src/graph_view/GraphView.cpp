#include <gui/graph_view/GraphView.hpp>
#include <math.h>
#include <stdlib.h>

static uint16_t randomish(int32_t seed)
{
    static uint16_t last = 0;
    const uint16_t num = (seed * (1337 + last)) % 0xFFFF;
    last = num;
    return num;
}

GraphView::GraphView()
{
    dynamicGraph1MajorYAxisLabel.invalidate();
    dynamicGraph1MajorYAxisGrid.invalidate();
    tickCounter = 0;
}

void GraphView::setupScreen()
{
  MainViewBase::setupScreen();
}

void GraphView::tearDownScreen()
{
    MainViewBase::tearDownScreen();
}

void GraphView::setCurrentValue(uint8_t value)
{
  dynamicGraph1.addDataPoint(static_cast<int>(value));
}

void GraphView::handleTickEvent()
{
    tickCounter++;

    // Insert each second tick
    if (tickCounter % 2 == 0)
    {
      // Insert data point
      // dynamicGraph1.addDataPoint(static_cast<int>(m_local_data));

        float yMax = dynamicGraph1.getGraphRangeYMaxAsFloat();

        // Insert "random" points along a sine wave
        dynamicGraph1.addDataPoint((int)((sinf(tickCounter * .02f) + 1) * (yMax / 2.2f)) + randomish(tickCounter) % (int)(yMax / 10.f));
    }

    dynamicGraph1.invalidate();
}

void GraphView::userToModel()
{
    presenter->userToModel(count);
}

void GraphView::modelToView()
{
    presenter->modelToView();
}