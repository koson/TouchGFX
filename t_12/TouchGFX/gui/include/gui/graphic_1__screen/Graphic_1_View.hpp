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

    virtual void userToModel();



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

    uint8_t m_local_data_sensor;

    float m_AI;
    float m_SP_AI;

    std::array<uint8_t, COUNT_DI> m_DI;
    std::array<uint8_t, COUNT_DO> m_DO;
};


#endif // GRAPHIC_1_VIEW_HPP
