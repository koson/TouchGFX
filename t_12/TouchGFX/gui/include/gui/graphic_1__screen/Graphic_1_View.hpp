// #ifndef GRAPHIC_1_VIEW_HPP
// #define GRAPHIC_1_VIEW_HPP

// #include <gui_generated/graphic_1__screen/Graphic_1_ViewBase.hpp>
// #include <gui/graphic_1__screen/Graphic_1_Presenter.hpp>

// class Graphic_1_View : public Graphic_1_ViewBase
// {
// public:
//   Graphic_1_View();
//   virtual ~Graphic_1_View() {};
//   virtual void setupScreen();
//   virtual void tearDownScreen();

//   virtual void increaseValue();
//   virtual void decreaseValue();

//   // ______________ Presenter to View ______________

//   void setCount(uint8_t countValue);

//   void setData(uint16_t data); // SPI

//   virtual void modelToView();


//   // ______________ View to Presenter ______________

//   virtual void userToModel();


// protected:
//   int tickCounter;
//   virtual void handleTickEvent();
// private:
//   uint8_t count;
//   uint16_t data;
//   uint8_t m_local_data_sensor;
// };

// #endif // GRAPHIC_1_VIEW_HPP



#ifndef GRAPHIC_1_VIEW_HPP
#define GRAPHIC_1_VIEW_HPP

#include <gui_generated/graphic_1__screen/Graphic_1_ViewBase.hpp>
#include <gui/graphic_1__screen/Graphic_1_Presenter.hpp>

#include <array>

#include "global_pins.h"

class Graphic_1_View : public Graphic_1_ViewBase
{
public:
    Graphic_1_View();
    virtual ~Graphic_1_View() {};

    virtual void setupScreen();
    virtual void tearDownScreen();


    // ______________ Presenter to View ______________

    virtual void modelToView();

    // ______________ View to Presenter ______________

    virtual void userToModel(uint16_t value);

    // __________________________________________________
    // ______________ Additional functions ______________

    void setCurrentAI(std::array<float, COUNT_AI> values);
    //void setCurrentAO(std::array<float, COUNT_AO> values);
    void setCurrentDI(std::array<uint8_t, COUNT_DI> values);
    void setCurrentDO(std::array<uint8_t, COUNT_DO> values);

    void setCurrentStepPointsAI(std::array<float, COUNT_AI> values);


protected:
    int tickCounter;
    virtual void handleTickEvent();

private:
    float m_AI;
    float m_SP_AI;

    std::array<uint8_t, COUNT_DI> m_DI;
    std::array<uint8_t, COUNT_DO> m_DO;
};

#endif // GRAPHIC_1_VIEW_HPP
