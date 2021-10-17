#ifndef DISCRET_VIEW_HPP
#define DISCRET_VIEW_HPP

#include <gui_generated/discret__screen/Discret_ViewBase.hpp>
#include <gui/discret__screen/Discret_Presenter.hpp>

#include <string>
#include <array>
#include <map>

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


    std::map<std::string, uint16_t> getCurrentDate();
    std::map<std::string, uint8_t> getCurrentTime();



    void setCurrentAI(std::array<float, COUNT_AI> values);
    void setCurrentUnitsAI(std::array<uint8_t, COUNT_AI> values);
    //void setCurrentAO(std::array<float, COUNT_AO> values);
    void setCurrentDI(std::array<uint8_t, COUNT_DI> values);
    void setCurrentDO(std::array<uint8_t, COUNT_DO> values);


    void setCurrentDate(std::map<std::string, uint16_t> values);
    void setCurrentTime(std::map<std::string, uint8_t> values);



protected:
    int tickCounter;
    virtual void handleTickEvent();

private:

    std::array<float, COUNT_AI> m_AI;
    std::array<uint8_t, COUNT_AI> m_U_AI;

    std::array<uint8_t, COUNT_DI> m_DI;
    std::array<uint8_t, COUNT_DO> m_DO;

    std::map<std::string, uint16_t> m_date;
    std::map<std::string, uint8_t> m_time;
};

#endif // DISCRET_VIEW_HPP
