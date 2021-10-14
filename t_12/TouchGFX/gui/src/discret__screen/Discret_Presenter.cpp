#include <gui/discret__screen/Discret_View.hpp>
#include <gui/discret__screen/Discret_Presenter.hpp>

Discret_Presenter::Discret_Presenter(Discret_View& v)
    : view(v)
{
}

void Discret_Presenter::activate()
{
  updateView();
}

void Discret_Presenter::deactivate()
{
}

void Discret_Presenter::valueIsChanged()
{
    updateView();
}


void Discret_Presenter::userToModel(std::array<float, COUNT_AI> m_AI,
                                    std::array<uint8_t, COUNT_DI> m_DI,
                                    std::array<uint8_t, COUNT_DO> m_DO)
{
    updateModel(m_AI, m_DI, m_DO);
};


void Discret_Presenter::modelToView()
{
    updateView();
};



// __________________________________________________
// ______________ Additional functions ______________

void Discret_Presenter::updateView()
{
    view.setCurrentAI(model->getCurrentAI());

    view.setCurrentDI(model->getCurrentDI());
    view.setCurrentDO(model->getCurrentDO());
}

void Discret_Presenter::updateModel(std::array<float, COUNT_AI> m_AI,
                                    std::array<uint8_t, COUNT_DI> m_DI,
                                    std::array<uint8_t, COUNT_DO> m_DO)
{
    model->setCurrentAI(m_AI);

    model->setCurrentDI(m_DI);
    model->setCurrentDO(m_DO);
}
