#ifndef GRAPHIC_1_VIEW_HPP
#define GRAPHIC_1_VIEW_HPP

#include <gui_generated/graphic_1__screen/Graphic_1_ViewBase.hpp>
#include <gui/graphic_1__screen/Graphic_1_Presenter.hpp>

class Graphic_1_View : public Graphic_1_ViewBase
{
public:
    Graphic_1_View();
    virtual ~Graphic_1_View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // GRAPHIC_1_VIEW_HPP
