#ifndef LOGIN_PRESENTER_HPP
#define LOGIN_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Login_View;

class Login_Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Login_Presenter(Login_View& v);

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

    virtual ~Login_Presenter() {};

private:
    Login_Presenter();

    Login_View& view;
};

#endif // LOGIN_PRESENTER_HPP
