#ifndef CONTROL_PRESENTER_HPP
#define CONTROL_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Control_View;

class Control_Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Control_Presenter(Control_View& v);

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

    virtual ~Control_Presenter() {};

private:
    Control_Presenter();

    Control_View& view;
};

#endif // CONTROL_PRESENTER_HPP
