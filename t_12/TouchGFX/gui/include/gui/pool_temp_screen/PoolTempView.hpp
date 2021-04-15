#ifndef POOLTEMP_VIEW_HPP
#define POOLTEMP_VIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/pool_temp_screen/PoolTempPresenter.hpp>

class PoolTempView : public MainViewBase
{
public:
    PoolTempView();
    virtual ~PoolTempView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    //event from Presenter
    virtual void setPoolTemp(uint32_t temp);
protected:
    virtual void sliderMoved(int value);
};

#endif // POOLTEMP_VIEW_HPP
