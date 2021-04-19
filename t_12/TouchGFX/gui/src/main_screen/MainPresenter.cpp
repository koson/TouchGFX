#include <gui/main_screen/MainPresenter.hpp>
#include <gui/main_screen/MainView.hpp>
#include <gui/graph_view/GraphView.hpp>

MainPresenter::MainPresenter(MainView& v, GraphView& g)
    : view(v), graph(g)
{
}

void MainPresenter::activate()
{
    view.setData(model->getCurrentValue());

    graph.setCurrentValue(model->getCurrentValue());
}

void MainPresenter::deactivate()
{
}




void MainPresenter::valueIsChanged()
{
    modelToView();
}

void MainPresenter::userToModel(uint8_t value)
{
    model->userToModel(value);
};

void MainPresenter::modelToView()
{
    view.setData(model->getCurrentValue());

    graph.setCurrentValue(model->getCurrentValue());
};


