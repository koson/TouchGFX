#include <gui/view/MasterPresenter.hpp>
#include <gui/view/MasterView.hpp>

MasterPresenter::MasterPresenter(MasterView& g)
    : mainView(g)
{
}

void MasterPresenter::activate()
{
    //Set view to match pool temperature in Model
    mainView.setCurrentValue(model->getCurrentValue());
}

void MasterPresenter::deactivate()
{
}


void MasterPresenter::valueIsChanged()
{
    modelToView();
}

void MasterPresenter::userToModel(uint8_t value)
{
    model->userToModel(value);
};

void MasterPresenter::modelToView()
{
    mainView.setCurrentValue(model->getCurrentValue());
};
