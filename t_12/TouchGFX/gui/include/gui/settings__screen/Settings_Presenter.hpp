#ifndef SETTINGS_PRESENTER_HPP
#define SETTINGS_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Settings_View;

class Settings_Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Settings_Presenter(Settings_View& v);

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

    virtual ~Settings_Presenter() {};

private:
    Settings_Presenter();

    Settings_View& view;
};

#endif // SETTINGS_PRESENTER_HPP
