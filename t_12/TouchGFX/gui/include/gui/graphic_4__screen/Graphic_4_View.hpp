#ifndef GRAPHIC_4_VIEW_HPP
#define GRAPHIC_4_VIEW_HPP

#include <gui_generated/graphic_4__screen/Graphic_4_ViewBase.hpp>
#include <gui/graphic_4__screen/Graphic_4_Presenter.hpp>

class Graphic_4_View : public Graphic_4_ViewBase
{
public:
    Graphic_4_View();
    virtual ~Graphic_4_View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // GRAPHIC_4_VIEW_HPP
