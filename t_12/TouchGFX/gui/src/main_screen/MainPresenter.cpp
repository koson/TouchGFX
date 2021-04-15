#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>

MainPresenter::MainPresenter(MainView& v)
    : view(v)
{
}

void MainPresenter::activate()
{
    view.setData(model->getPoolTemperature());
}

void MainPresenter::deactivate()
{
}

void MainPresenter::poolTemperatureChanged()
{
    //forward new temperature to view
    view.setData(model->getPoolTemperature());
}
