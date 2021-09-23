#ifndef SCADA_PRESENTER_HPP
#define SCADA_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SCADA_View;

class SCADA_Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    SCADA_Presenter(SCADA_View& v);

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

    virtual ~SCADA_Presenter() {};

private:
    SCADA_Presenter();

    SCADA_View& view;
};

#endif // SCADA_PRESENTER_HPP
