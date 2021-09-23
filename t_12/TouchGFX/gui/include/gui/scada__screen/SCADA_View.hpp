#ifndef SCADA_VIEW_HPP
#define SCADA_VIEW_HPP

#include <gui_generated/scada__screen/SCADA_ViewBase.hpp>
#include <gui/scada__screen/SCADA_Presenter.hpp>

class SCADA_View : public SCADA_ViewBase
{
public:
    SCADA_View();
    virtual ~SCADA_View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCADA_VIEW_HPP
