#include <gui/graphic_1__screen/Graphic_1_View.hpp>
#include <gui/graphic_1__screen/Graphic_1_Presenter.hpp>


Graphic_1_Presenter::Graphic_1_Presenter(Graphic_1_View& v) : view(v)
{
}

void Graphic_1_Presenter::activate()
{
    view.setData(model->getCurrentValue());
}

void Graphic_1_Presenter::deactivate()
{
}




void Graphic_1_Presenter::valueIsChanged()
{
    modelToView();
}

void Graphic_1_Presenter::userToModel(uint8_t value)
{
    model->userToModel(value);
};

void Graphic_1_Presenter::modelToView()
{
    view.setData(model->getCurrentValue());
};
