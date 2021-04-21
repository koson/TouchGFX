#ifndef GRAPH_VIEW_HPP
#define GRAPH_VIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/graph_view/GraphPresenter.hpp>

class GraphView : public MainViewBase
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