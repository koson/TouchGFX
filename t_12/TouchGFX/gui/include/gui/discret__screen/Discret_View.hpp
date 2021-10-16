#ifndef DISCRET_VIEW_HPP
#define DISCRET_VIEW_HPP

#include <gui_generated/discret__screen/Discret_ViewBase.hpp>
#include <gui/discret__screen/Discret_Presenter.hpp>

#include <utility>
#include <string>
#include <array>

#include "global_pins.h"

class Discret_View : public Discret_ViewBase
{
public:
    Discret_View();
    virtual ~Discret_View() {}

    virtual void setupScreen();
    virtual void tearDownScreen();


    // ______________ Presenter to View ______________

    virtual void modelToView();

    // ______________ View to Presenter ______________

    virtual void userToModel();


    // __________________________________________________
    // ______________ Additional functions ______________

    std::array<float, COUNT_AI> getCurrentAI();
    std::array<uint8_t, COUNT_AI> getCurrentUnitsAI();
    //std::array<float, COUNT_AO> getCurrentAO();
    std::array<uint8_t, COUNT_DI> getCurrentDI();
    std::array<uint8_t, COUNT_DO> getCurrentDO();


    std::array<std::uint16_t, 3> getCurrentDate();
    std::array<std::uint8_t, 3> getCurrentTime();




    void setCurrentAI(std::array<float, COUNT_AI> values);
    void setCurrentUnitsAI(std::array<uint8_t, COUNT_AI> values);
    //void setCurrentAO(std::array<float, COUNT_AO> values);
    void setCurrentDI(std::array<uint8_t, COUNT_DI> values);
    void setCurrentDO(std::array<uint8_t, COUNT_DO> values);


    void setCurrentDate(std::array<std::uint16_t, 3> values);
    void setCurrentTime(std::array<std::uint8_t, 3> values);



protected:
    int tickCounter;
    virtual void handleTickEvent();

private:

    std::array<float, COUNT_AI> m_AI;
    std::array<uint8_t, COUNT_AI> m_U_AI;

    std::array<uint8_t, COUNT_DI> m_DI;
    std::array<uint8_t, COUNT_DO> m_DO;

    std::array<std::uint16_t, 3> m_date;
    std::array<std::uint8_t, 3> m_time;
};

#endif // DISCRET_VIEW_HPP
