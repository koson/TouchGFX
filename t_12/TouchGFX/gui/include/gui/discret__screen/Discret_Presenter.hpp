#ifndef DISCRET_PRESENTER_HPP
#define DISCRET_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

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
                    std::array<uint8_t, COUNT_DI> m_DI,
                    std::array<uint8_t, COUNT_DO> m_DO);

    // __________________________________________________
    // ______________ Additional functions ______________

    void updateModel(std::array<float, COUNT_AI> m_AI,
                    std::array<uint8_t, COUNT_DI> m_DI,
                    std::array<uint8_t, COUNT_DO> m_DO);
    void updateView();

private:
    Discret_Presenter();

    Discret_View& view;
};

#endif // DISCRET_PRESENTER_HPP
