#include <gui/graph_view/GraphView.hpp>

GraphView::GraphView()
{
    tickCounter = 0;
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
      dynamicGraph1.addDataPoint(static_cast<int>(m_local_data));
    }
}

void GraphView::userToModel()
{
    presenter->userToModel(count);
}

void GraphView::modelToView()
{
    presenter->modelToView();
}