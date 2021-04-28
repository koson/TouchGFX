#ifndef GRAPHICS_SCREENPRESENTER_HPP
#define GRAPHICS_SCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Graphics_ScreenView;

class Graphics_ScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Graphics_ScreenPresenter(Graphics_ScreenView& v);

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

    virtual ~Graphics_ScreenPresenter() {};

private:
    Graphics_ScreenPresenter();

    Graphics_ScreenView& view;
};

#endif // GRAPHICS_SCREENPRESENTER_HPP
