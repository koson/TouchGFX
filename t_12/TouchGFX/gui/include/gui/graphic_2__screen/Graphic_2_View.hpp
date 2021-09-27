#ifndef GRAPHIC_2_VIEW_HPP
#define GRAPHIC_2_VIEW_HPP

#include <gui_generated/graphic_2__screen/Graphic_2_ViewBase.hpp>
#include <gui/graphic_2__screen/Graphic_2_Presenter.hpp>

class Graphic_2_View : public Graphic_2_ViewBase
{
public:
    Graphic_2_View();
    virtual ~Graphic_2_View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // GRAPHIC_2_VIEW_HPP
