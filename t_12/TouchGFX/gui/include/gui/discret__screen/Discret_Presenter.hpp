#ifndef DISCRET_PRESENTER_HPP
#define DISCRET_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

#include <utility>
#include <string>
#include <array>


class Discret_View;

class Discret_Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Discret_Presenter(Discret_View& v);
    virtual ~Discret_Presenter() {};

    virtual void activate();
    virtual void deactivate();

    // Need for connection to ModelListener
    void valueIsChanged() override;


    // ______________ Model to View ______________

    void modelToView();

    // ______________ View to Model ______________

    void userToModel(std::array<float, COUNT_AI> m_AI,
                    std::array<uint8_t, COUNT_AI> m_U_AI,
                    std::array<uint8_t, COUNT_DI> m_DI,
                    std::array<uint8_t, COUNT_DO> m_DO,
                    std::array<std::uint16_t, 3> m_date,
                    std::array<std::uint8_t, 3> m_time);


    // __________________________________________________
    // ______________ Additional functions ______________

    // Maybe this function better place to protected modificator of access
    void updateModel(std::array<float, COUNT_AI> m_AI,
                    std::array<uint8_t, COUNT_AI> m_U_AI,
                    std::array<uint8_t, COUNT_DI> m_DI,
                    std::array<uint8_t, COUNT_DO> m_DO,
                    std::array<std::uint16_t, 3> m_date,
                    std::array<std::uint8_t, 3> m_time);
    void updateView();

private:
    Discret_Presenter();

    Discret_View& view;
};

#endif // DISCRET_PRESENTER_HPP
