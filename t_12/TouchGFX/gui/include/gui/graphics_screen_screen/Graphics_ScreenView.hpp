#ifndef GRAPHICS_SCREENVIEW_HPP
#define GRAPHICS_SCREENVIEW_HPP

#include <gui_generated/graphics_screen_screen/Graphics_ScreenViewBase.hpp>
#include <gui/graphics_screen_screen/Graphics_ScreenPresenter.hpp>

class Graphics_ScreenView : public Graphics_ScreenViewBase
{
public:
    Graphics_ScreenView();
    virtual ~Graphics_ScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // GRAPHICS_SCREENVIEW_HPP
