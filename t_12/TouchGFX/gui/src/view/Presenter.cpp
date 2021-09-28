#include <gui/view/Presenter.hpp>
#include <gui/view/View.hpp>

Presenter::Presenter(View& g)
    : mainView(g)
{
}

void Presenter::activate()
{
    //Set view to match pool temperature in Model
    graph.setCurrentValue(model->getCurrentValue());
}

void Presenter::deactivate()
{
}


void Presenter::valueIsChanged()
{
    modelToView();
}

void Presenter::userToModel(uint8_t value)
{
    model->userToModel(value);
};

void Presenter::modelToView()
{
    graph.setCurrentValue(model->getCurrentValue());
};
