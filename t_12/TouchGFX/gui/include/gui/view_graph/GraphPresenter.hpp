#ifndef GRAPH_PRESENTER_HPP
#define GRAPH_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class GraphView;

class GraphPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    GraphPresenter(GraphView& v);
    virtual ~GraphPresenter() {};

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();




    virtual void valueIsChanged();

    void userToModel(uint8_t value);
    void modelToView();




private:
    GraphPresenter();

    GraphView& graph;
};


#endif // GRAPH_PRESENTER_HPP
