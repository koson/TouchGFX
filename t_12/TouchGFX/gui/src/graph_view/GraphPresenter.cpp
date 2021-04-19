#include <gui/graph_view/GraphPresenter.hpp>
#include <gui/graph_view/GraphView.hpp>

GraphPresenter::GraphPresenter(GraphView& g)
    : graph(g)
{
}

void GraphPresenter::activate()
{
    //Set view to match pool temperature in Model
    graph.setCurrentValue(model->getCurrentValue());
}

void GraphPresenter::deactivate()
{
}


void GraphPresenter::valueIsChanged()
{
    modelToView();
}

void GraphPresenter::userToModel(uint8_t value)
{
    model->userToModel(value);
};

void GraphPresenter::modelToView()
{
    graph.setCurrentValue(model->getCurrentValue());
};


