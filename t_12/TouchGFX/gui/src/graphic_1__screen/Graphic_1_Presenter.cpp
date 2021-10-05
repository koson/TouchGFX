#include <gui/graphic_1__screen/Graphic_1_View.hpp>
#include <gui/graphic_1__screen/Graphic_1_Presenter.hpp>


Graphic_1_Presenter::Graphic_1_Presenter(Graphic_1_View& v) : view(v)
{
  // 2
}

void Graphic_1_Presenter::activate()
{
    updateView();
}

void Graphic_1_Presenter::deactivate()
{
}




void Graphic_1_Presenter::valueIsChanged()
{
    updateView();
}

void Graphic_1_Presenter::userToModel(uint16_t value)
{
    //model->userToModel(value);
};

void Graphic_1_Presenter::modelToView()
{
    updateView();
};

void Graphic_1_Presenter::updateView()
{
    view.setCurrentAI(model->getCurrentAI());

    view.setCurrentDI(model->getCurrentDI());
    view.setCurrentDO(model->getCurrentDO());

    view.setCurrentStepPointsAI(model->getCurrentStepPointsAI());
}
