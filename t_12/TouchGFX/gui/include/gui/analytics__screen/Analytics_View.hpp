#ifndef ANALYTICS_VIEW_HPP
#define ANALYTICS_VIEW_HPP

#include <gui_generated/analytics__screen/Analytics_ViewBase.hpp>
#include <gui/analytics__screen/Analytics_Presenter.hpp>

class Analytics_View : public Analytics_ViewBase
{
public:
    Analytics_View();
    virtual ~Analytics_View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ANALYTICS_VIEW_HPP
