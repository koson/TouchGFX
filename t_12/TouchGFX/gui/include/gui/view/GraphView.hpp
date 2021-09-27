#ifndef GRAPH_VIEW_HPP
#define GRAPH_VIEW_HPP

#include <gui_generated/graphic_1__screen/Graphic_1_ViewBase.hpp>
#include <gui/graphic_1__screen/Graphic_1_Presenter.hpp>

class GraphView : public Graphic_1_ViewBase
{
public:
    GraphView();
    virtual ~GraphView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    // ______________ Presenter to View ______________

    void setCurrentValue(uint8_t value);

    virtual void modelToView();


    // ______________ View to Presenter ______________

    virtual void userToModel();

protected:
    int tickCounter;
    void handleTickEvent();
};


#endif // GRAPH_VIEW_HPP
