#include <gui/main_screen/MainPresenter.hpp>
#include <gui/main_screen/MainView.hpp>

MainPresenter::MainPresenter(MainView& v)
    : view(v)
{
}

void MainPresenter::activate()
{
    view.setData(model->getCurrentValue());
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
};


