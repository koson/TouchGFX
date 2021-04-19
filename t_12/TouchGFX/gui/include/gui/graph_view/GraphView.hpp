#ifndef GRAPH_VIEW_HPP
#define GRAPH_VIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>

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

private:
    uint8_t count;
    uint8_t m_local_data;
};


#endif // GRAPH_VIEW_HPP