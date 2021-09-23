#ifndef GRAPHICS_WINDOWPRESENTER_HPP
#define GRAPHICS_WINDOWPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Graphics_WindowView;

class Graphics_WindowPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Graphics_WindowPresenter(Graphics_WindowView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Graphics_WindowPresenter() {};

private:
    Graphics_WindowPresenter();

    Graphics_WindowView& view;
};

#endif // GRAPHICS_WINDOWPRESENTER_HPP
