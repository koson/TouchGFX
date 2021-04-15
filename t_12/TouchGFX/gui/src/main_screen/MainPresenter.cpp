#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>

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

void MainPresenter::notifyValueChanged()
{
    //forward new temperature to view
    view.setData(model->getCurrentValue());
}

void MainPresenter::setCurrentValue(uint32_t val)
{
    model->setCurrentValue(val);
};