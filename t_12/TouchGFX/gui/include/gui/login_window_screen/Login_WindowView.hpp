#ifndef LOGIN_WINDOWVIEW_HPP
#define LOGIN_WINDOWVIEW_HPP

#include <gui_generated/login_window_screen/Login_WindowViewBase.hpp>
#include <gui/login_window_screen/Login_WindowPresenter.hpp>

class Login_WindowView : public Login_WindowViewBase
{
public:
    Login_WindowView();
    virtual ~Login_WindowView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // LOGIN_WINDOWVIEW_HPP
