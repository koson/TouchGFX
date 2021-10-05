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

  void setCurrentAI(std::array<float, COUNT_AI> values);
  //void setCurrentAO(std::array<float, COUNT_AO> values);
  void setCurrentDI(std::array<bool, COUNT_DI> values);
  void setCurrentDO(std::array<bool, COUNT_DO> values);

  void setCurrentStepPointsAI(std::array<float, COUNT_AI> values);

  virtual void modelToView();

  // ______________ View to Presenter ______________

  virtual void userToModel(uint16_t value);


protected:
  int tickCounter;
  virtual void handleTickEvent();

private:
  float m_AI;
  float m_SP_AI;

  std::array<bool, COUNT_DI> m_DI;
  std::array<bool, COUNT_DO> m_DO;
};

#endif // GRAPHIC_1_VIEW_HPP
