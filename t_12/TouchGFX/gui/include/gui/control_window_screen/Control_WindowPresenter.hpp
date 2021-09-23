#ifndef CONTROL_WINDOWPRESENTER_HPP
#define CONTROL_WINDOWPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Control_WindowView;

class Control_WindowPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Control_WindowPresenter(Control_WindowView& v);

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

    virtual ~Control_WindowPresenter() {};

private:
    Control_WindowPresenter();

    Control_WindowView& view;
};

#endif // CONTROL_WINDOWPRESENTER_HPP
