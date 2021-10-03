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

  void setCurrentAI(std::array<double, countAI>values);
  //void setCurrentAO(std::array<double, countAO> values);
  void setCurrentDI(std::array<bool, countDI> values);
  void setCurrentDO(std::array<bool, countDO> values);

  void setCurrentStepPointsAI(std::array<double, countAI> values);

  virtual void modelToView();

  // ______________ View to Presenter ______________

  virtual void userToModel();


protected:
  int tickCounter;
  virtual void handleTickEvent();

private:
  double m_AI;
  double m_stepPoint_AI;

  std::array<bool, countDI> m_DI;
  std::array<bool, countDO> m_DO;
};

#endif // GRAPHIC_1_VIEW_HPP
