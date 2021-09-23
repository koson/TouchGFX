#ifndef DISCRET_VIEW_HPP
#define DISCRET_VIEW_HPP

#include <gui_generated/discret__screen/Discret_ViewBase.hpp>
#include <gui/discret__screen/Discret_Presenter.hpp>

class Discret_View : public Discret_ViewBase
{
public:
    Discret_View();
    virtual ~Discret_View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // DISCRET_VIEW_HPP
