#ifndef GRAPHICS_PRESENTER_HPP
#define GRAPHICS_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Graphics_View;

class Graphics_Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Graphics_Presenter(Graphics_View& v);

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

    virtual ~Graphics_Presenter() {};

private:
    Graphics_Presenter();

    Graphics_View& view;
};

#endif // GRAPHICS_PRESENTER_HPP
