#ifndef SETTINGS_VIEW_HPP
#define SETTINGS_VIEW_HPP

#include <gui_generated/settings__screen/Settings_ViewBase.hpp>
#include <gui/settings__screen/Settings_Presenter.hpp>

class Settings_View : public Settings_ViewBase
{
public:
    Settings_View();
    virtual ~Settings_View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_VIEW_HPP
