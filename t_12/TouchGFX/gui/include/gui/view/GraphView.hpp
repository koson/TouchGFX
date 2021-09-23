#ifndef GRAPH_VIEW_HPP
#define GRAPH_VIEW_HPP

#include <gui_generated/graphics__screen/Graphics_ViewBase.hpp>
#include <gui/view_grap/GraphPresenter.hpp>

class GraphView : public Graphics_ViewBase
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
