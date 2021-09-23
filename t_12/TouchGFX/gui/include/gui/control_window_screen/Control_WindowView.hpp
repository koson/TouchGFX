#ifndef CONTROL_WINDOWVIEW_HPP
#define CONTROL_WINDOWVIEW_HPP

#include <gui_generated/control_window_screen/Control_WindowViewBase.hpp>
#include <gui/control_window_screen/Control_WindowPresenter.hpp>

class Control_WindowView : public Control_WindowViewBase
{
public:
    Control_WindowView();
    virtual ~Control_WindowView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CONTROL_WINDOWVIEW_HPP
