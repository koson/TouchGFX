#ifndef ANALYTICS_WINDOWPRESENTER_HPP
#define ANALYTICS_WINDOWPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Analytics_WindowView;

class Analytics_WindowPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Analytics_WindowPresenter(Analytics_WindowView& v);

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

    virtual ~Analytics_WindowPresenter() {};

private:
    Analytics_WindowPresenter();

    Analytics_WindowView& view;
};

#endif // ANALYTICS_WINDOWPRESENTER_HPP
