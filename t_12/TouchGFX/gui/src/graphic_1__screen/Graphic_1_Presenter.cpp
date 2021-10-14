#include <gui/graphic_1__screen/Graphic_1_View.hpp>
#include <gui/graphic_1__screen/Graphic_1_Presenter.hpp>


Graphic_1_Presenter::Graphic_1_Presenter(Graphic_1_View& v) : view(v)
{
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


void Graphic_1_Presenter::userToModel(float m_AI, float m_SP_AI,
                                      std::array<uint8_t, COUNT_DI> m_DI,
                                      std::array<uint8_t, COUNT_DO> m_DO)
{
    updateModel(m_AI, m_SP_AI, m_DI, m_DO);
};


void Graphic_1_Presenter::modelToView()
{
    updateView();
};



// __________________________________________________
// ______________ Additional functions ______________

void Graphic_1_Presenter::updateView()
{
    view.setCurrentAI(model->getCurrentAI());

    view.setCurrentDI(model->getCurrentDI());
    view.setCurrentDO(model->getCurrentDO());

    view.setCurrentStepPointsAI(model->getCurrentStepPointsAI());
}

void Graphic_1_Presenter::updateModel(float m_AI, float m_SP_AI,
                                      std::array<uint8_t, COUNT_DI> m_DI,
                                      std::array<uint8_t, COUNT_DO> m_DO)
{
    std::array<float, COUNT_AI> newAI_1;
    std::array<float, COUNT_AI> newSP_AI_1;

    newAI_1.at(0) = m_AI;
    newSP_AI_1.at(0) = m_SP_AI;

    model->setCurrentAI(newAI_1);

    model->setCurrentDI(m_DI);
    model->setCurrentDO(m_DO);

    model->setCurrentStepPointsAI(newSP_AI_1);
}
