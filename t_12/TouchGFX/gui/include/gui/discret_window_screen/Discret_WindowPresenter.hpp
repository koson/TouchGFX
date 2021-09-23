#ifndef DISCRET_WINDOWPRESENTER_HPP
#define DISCRET_WINDOWPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Discret_WindowView;

class Discret_WindowPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Discret_WindowPresenter(Discret_WindowView& v);

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

    virtual ~Discret_WindowPresenter() {};

private:
    Discret_WindowPresenter();

    Discret_WindowView& view;
};

#endif // DISCRET_WINDOWPRESENTER_HPP
