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
                                    std::array<uint8_t, COUNT_AI> m_U_AI,
                                    std::array<uint8_t, COUNT_DI> m_DI,
                                    std::array<uint8_t, COUNT_DO> m_DO,
                                    std::map<std::string, uint16_t> m_date,
                                    std::map<std::string, uint8_t> m_time)
{
    updateModel(m_AI, m_U_AI, m_DI, m_DO, m_date, m_time);
}


void Discret_Presenter::modelToView()
{
    updateView();
}



// __________________________________________________
// ______________ Additional functions ______________

void Discret_Presenter::updateView()
{
    view.setCurrentAI(model->getCurrentAI());
    view.setCurrentUnitsAI(model->getCurrentUnitsAI());

    view.setCurrentDI(model->getCurrentDI());
    view.setCurrentDO(model->getCurrentDO());


    view.setCurrentDate(model->getCurrentDate());
    view.setCurrentTime(model->getCurrentTime());
}

void Discret_Presenter::updateModel(std::array<float, COUNT_AI> m_AI,
                                    std::array<uint8_t, COUNT_AI> m_U_AI,
                                    std::array<uint8_t, COUNT_DI> m_DI,
                                    std::array<uint8_t, COUNT_DO> m_DO,
                                    std::map<std::string, uint16_t> m_date,
                                    std::map<std::string, uint8_t> m_time)
{
    model->setCurrentAI(m_AI);
    model->setCurrentUnitsAI(m_U_AI);

    model->setCurrentDI(m_DI);
    model->setCurrentDO(m_DO);


    model->setCurrentDate(m_date);
    model->setCurrentTime(m_time);
}
