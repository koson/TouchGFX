#include <gui/graphics__screen/Graphics_View.hpp>
#include <gui/graphics__screen/Graphics_Presenter.hpp>

void Graphics_Presenter::activate()
{
    view.setData(model->getCurrentValue());
}

void Graphics_Presenter::deactivate()
{
}




void Graphics_Presenter::valueIsChanged()
{
    modelToView();
}

void Graphics_Presenter::userToModel(uint8_t value)
{
    model->userToModel(value);
};

void Graphics_Presenter::modelToView()
{
    view.setData(model->getCurrentValue());
};
