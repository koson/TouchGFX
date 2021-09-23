#ifndef DISCRET_WINDOWVIEW_HPP
#define DISCRET_WINDOWVIEW_HPP

#include <gui_generated/discret_window_screen/Discret_WindowViewBase.hpp>
#include <gui/discret_window_screen/Discret_WindowPresenter.hpp>

class Discret_WindowView : public Discret_WindowViewBase
{
public:
    Discret_WindowView();
    virtual ~Discret_WindowView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // DISCRET_WINDOWVIEW_HPP
