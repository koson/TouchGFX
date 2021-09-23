#ifndef GRAPHICS_VIEW_HPP
#define GRAPHICS_VIEW_HPP

#include <gui_generated/graphics__screen/Graphics_ViewBase.hpp>
#include <gui/graphics__screen/Graphics_Presenter.hpp>

class Graphics_View : public Graphics_ViewBase
{
  Graphics_View();
  virtual ~Graphics_View() {}
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
};

#endif // GRAPHICS_VIEW_HPP
