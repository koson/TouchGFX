#ifndef GRAPHIC_1_VIEW_HPP
#define GRAPHIC_1_VIEW_HPP

#include <gui_generated/graphic_1__screen/Graphic_1_ViewBase.hpp>
#include <gui/graphic_1__screen/Graphic_1_Presenter.hpp>

#include <array>

class Graphic_1_View : public Graphic_1_ViewBase
{
public:
  Graphic_1_View();
  virtual ~Graphic_1_View() {};

  virtual void setupScreen();
  virtual void tearDownScreen();

  // ______________ Presenter to View ______________

  void setCurrentAI(std::array<double> values);
  //void setCurrentAO(std::array<double> values);
  void setCurrentDI(std::array<bool> values);
  void setCurrentDO(std::array<bool> values);

  void setCurrentStepPointsAI(std::array<double> values);

  virtual void modelToView();

  // ______________ View to Presenter ______________

  virtual void userToModel();


protected:
  int tickCounter;
  virtual void handleTickEvent();

private:
  double m_AI;
  double m_stepPoint_AI;

  std::array<bool, 4> m_DI;
  std::array<bool, 4> m_DO;
};

#endif // GRAPHIC_1_VIEW_HPP
