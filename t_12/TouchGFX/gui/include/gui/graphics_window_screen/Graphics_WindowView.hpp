#ifndef GRAPHICS_WINDOWVIEW_HPP
#define GRAPHICS_WINDOWVIEW_HPP

#include <gui_generated/graphics_window_screen/Graphics_WindowViewBase.hpp>
#include <gui/graphics_window_screen/Graphics_WindowPresenter.hpp>

class Graphics_WindowView : public Graphics_WindowViewBase
{
public:
    Graphics_WindowView();
    virtual ~Graphics_WindowView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // GRAPHICS_WINDOWVIEW_HPP
