#ifndef MAIN_VIEW_HPP
#define MAIN_VIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>

class MainView : public MainViewBase
{
public:
    MainView();
    virtual ~MainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void increaseValue();
    virtual void decreaseValue();

    virtual void updatePoolLight();

    void setLimitEffects(bool belowUpper, bool aboveLower);

    // ______________ Presenter to View ______________

    void setCount(uint8_t countValue);
    void setData(uint16_t data);    

protected:

    // ______________ View to Presenter ______________

    void userAction(int value);

private:
    uint8_t count;
    uint16_t data;
};

#endif // MAIN_VIEW_HPP
