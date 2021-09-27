#ifndef ARCHIVE_VIEW_HPP
#define ARCHIVE_VIEW_HPP

#include <gui_generated/archive__screen/Archive_ViewBase.hpp>
#include <gui/archive__screen/Archive_Presenter.hpp>

class Archive_View : public Archive_ViewBase
{
public:
    Archive_View();
    virtual ~Archive_View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ARCHIVE_VIEW_HPP
