#ifndef SCADA_WINDOWPRESENTER_HPP
#define SCADA_WINDOWPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SCADA_WindowView;

class SCADA_WindowPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SCADA_WindowPresenter(SCADA_WindowView& v);

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

    virtual ~SCADA_WindowPresenter() {};

private:
    SCADA_WindowPresenter();

    SCADA_WindowView& view;
};

#endif // SCADA_WINDOWPRESENTER_HPP
