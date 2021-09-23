#ifndef LOGIN_VIEW_HPP
#define LOGIN_VIEW_HPP

#include <gui_generated/login__screen/Login_ViewBase.hpp>
#include <gui/login__screen/Login_Presenter.hpp>

class Login_View : public Login_ViewBase
{
public:
    Login_View();
    virtual ~Login_View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // LOGIN_VIEW_HPP
