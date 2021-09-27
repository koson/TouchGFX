#ifndef GRAPHIC_3_VIEW_HPP
#define GRAPHIC_3_VIEW_HPP

#include <gui_generated/graphic_3__screen/Graphic_3_ViewBase.hpp>
#include <gui/graphic_3__screen/Graphic_3_Presenter.hpp>

class Graphic_3_View : public Graphic_3_ViewBase
{
public:
    Graphic_3_View();
    virtual ~Graphic_3_View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // GRAPHIC_3_VIEW_HPP
