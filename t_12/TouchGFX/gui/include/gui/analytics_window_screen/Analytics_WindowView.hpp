#ifndef ANALYTICS_WINDOWVIEW_HPP
#define ANALYTICS_WINDOWVIEW_HPP

#include <gui_generated/analytics_window_screen/Analytics_WindowViewBase.hpp>
#include <gui/analytics_window_screen/Analytics_WindowPresenter.hpp>

class Analytics_WindowView : public Analytics_WindowViewBase
{
public:
    Analytics_WindowView();
    virtual ~Analytics_WindowView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ANALYTICS_WINDOWVIEW_HPP
