#ifndef GRAPH_VIEW_HPP
#define GRAPH_VIEW_HPP

#include <gui_generated/login__screen/Login_ViewBase.hpp>
#include <gui_generated/discret__screen/Discret_ViewBase.hpp>
#include <gui_generated/graphic_1__screen/Graphic_1_ViewBase.hpp>
#include <gui_generated/graphic_2__screen/Graphic_2_ViewBase.hpp>
#include <gui_generated/graphic_3__screen/Graphic_3_ViewBase.hpp>
#include <gui_generated/graphic_4__screen/Graphic_4_ViewBase.hpp>
#include <gui_generated/control__screen/Control_ViewBase.hpp>
#include <gui_generated/analytics__screen/Analytics_ViewBase.hpp>
#include <gui_generated/archive__screen/Archive_ViewBase.hpp>

#include <gui_generated/login__screen/Login_Presenter.hpp>
#include <gui_generated/discret__screen/Discret_Presenter.hpp>
#include <gui_generated/graphic_1__screen/Graphic_1_Presenter.hpp>
#include <gui_generated/graphic_2__screen/Graphic_2_Presenter.hpp>
#include <gui_generated/graphic_3__screen/Graphic_3_Presenter.hpp>
#include <gui_generated/graphic_4__screen/Graphic_4_Presenter.hpp>
#include <gui_generated/control__screen/Control_Presenter.hpp>
#include <gui_generated/analytics__screen/Analytics_Presenter.hpp>
#include <gui_generated/archive__screen/Archive_Presenter.hpp>


class View : public Login_ViewBase,
                    Discret_ViewBase,
                    Graphic_1_ViewBase,
                    Graphic_2_ViewBase,
                    Graphic_3_ViewBase,
                    Graphic_4_ViewBase,
                    Control_ViewBase,
                    Analytics_ViewBase,
                    Archive_ViewBase
{
public:
    View();
    virtual ~View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    // ______________ Presenter to View ______________

    void setCurrentValue(uint8_t value);

    virtual void modelToView();


    // ______________ View to Presenter ______________

    virtual void userToModel();

protected:
    int tickCounter;
    void handleTickEvent();
};


#endif // GRAPH_VIEW_HPP
