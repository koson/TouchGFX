#ifndef SCADA_WINDOWVIEW_HPP
#define SCADA_WINDOWVIEW_HPP

#include <gui_generated/scada_window_screen/SCADA_WindowViewBase.hpp>
#include <gui/scada_window_screen/SCADA_WindowPresenter.hpp>

class SCADA_WindowView : public SCADA_WindowViewBase
{
public:
    SCADA_WindowView();
    virtual ~SCADA_WindowView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCADA_WINDOWVIEW_HPP
