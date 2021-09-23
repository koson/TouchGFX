#ifndef CONTROL_VIEW_HPP
#define CONTROL_VIEW_HPP

#include <gui_generated/control__screen/Control_ViewBase.hpp>
#include <gui/control__screen/Control_Presenter.hpp>

class Control_View : public Control_ViewBase
{
public:
    Control_View();
    virtual ~Control_View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CONTROL_VIEW_HPP
