#ifndef GRAPHIC_1_PRESENTER_HPP
#define GRAPHIC_1_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Graphic_1_View;

class Graphic_1_Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Graphic_1_Presenter(Graphic_1_View& v);
    virtual ~Graphic_1_Presenter() {};

    virtual void activate();
    virtual void deactivate();


    // Need for connection to ModelListener
    void valueIsChanged() override;


    // ______________ Model to View ______________

    void modelToView();

    // ______________ View to Model ______________

    void userToModel(float m_AI, float m_SP_AI,
                    std::array<uint8_t, COUNT_DI> m_DI,
                    std::array<uint8_t, COUNT_DO> m_DO);

    // __________________________________________________
    // ______________ Additional functions ______________

    void updateModel(float m_AI, float m_SP_AI,
                    std::array<uint8_t, COUNT_DI> m_DI,
                    std::array<uint8_t, COUNT_DO> m_DO);
    void updateView();

private:
    Graphic_1_Presenter();

    Graphic_1_View& view;
};

#endif // GRAPHICS_PRESENTER_HPP
