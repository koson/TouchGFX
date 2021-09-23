#ifndef GRAPHICS_VIEW_HPP
#define GRAPHICS_VIEW_HPP

#include <gui_generated/graphics__screen/Graphics_ViewBase.hpp>
#include <gui/graphics__screen/Graphics_Presenter.hpp>

class Graphics_View : public Graphics_ViewBase
{
public:
    Graphics_View();
    virtual ~Graphics_View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // GRAPHICS_VIEW_HPP
