#ifndef ANALYTICS_PRESENTER_HPP
#define ANALYTICS_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Analytics_View;

class Analytics_Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Analytics_Presenter(Analytics_View& v);

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

    virtual ~Analytics_Presenter() {};

private:
    Analytics_Presenter();

    Analytics_View& view;
};

#endif // ANALYTICS_PRESENTER_HPP
