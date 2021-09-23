#ifndef MAIN_VIEW_HPP
#define MAIN_VIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>

class MainView : public Graphics_WindowViewBase
{
public:
    MainView();
    virtual ~MainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void increaseValue();
    virtual void decreaseValue();

    virtual void chooseRB_1();
    virtual void chooseRB_2();
    virtual void chooseRB_3();
    virtual void chooseRB_4();

    // void setLimitEffects(bool belowUpper, bool aboveLower);




    // ______________ Presenter to View ______________

    void setCount(uint8_t countValue);

    void setData(uint16_t data); // SPI

    virtual void modelToView();


    // ______________ View to Presenter ______________

    virtual void userToModel();




protected:
    int tickCounter;
    virtual void handleTickEvent();
private:
    uint8_t count;
    uint16_t data;
    uint8_t m_local_data_sensor;
};

#endif // MAIN_VIEW_HPP
