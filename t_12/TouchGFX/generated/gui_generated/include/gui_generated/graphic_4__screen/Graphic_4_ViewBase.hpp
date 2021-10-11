/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef GRAPHIC_4_VIEWBASE_HPP
#define GRAPHIC_4_VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/graphic_4__screen/Graphic_4_Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>

class Graphic_4_ViewBase : public touchgfx::View<Graphic_4_Presenter>
{
public:
    Graphic_4_ViewBase();
    virtual ~Graphic_4_ViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }
    touchgfx::Box __background;

private:

};

#endif // GRAPHIC_4_VIEWBASE_HPP