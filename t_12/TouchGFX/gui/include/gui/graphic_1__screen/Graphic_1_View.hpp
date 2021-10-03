#ifndef GRAPHIC_1_VIEW_HPP
#define GRAPHIC_1_VIEW_HPP

#include <gui_generated/graphic_1__screen/Graphic_1_ViewBase.hpp>
#include <gui/graphic_1__screen/Graphic_1_Presenter.hpp>

class Graphic_1_View : public Graphic_1_ViewBase
{
public:
  Graphic_1_View();
  virtual ~Graphic_1_View() {};

  virtual void setupScreen();
  virtual void tearDownScreen();

  // ______________ Presenter to View ______________

  void setData(uint16_t data); // SPI

  virtual void modelToView();


  // ______________ View to Presenter ______________

  virtual void userToModel();


protected:
  int tickCounter;
  virtual void handleTickEvent();

private:
  uint16_t data;
  uint16_t m_local_data_sensor;
};

#endif // GRAPHIC_1_VIEW_HPP
