// #ifndef GRAPHIC_1_PRESENTER_HPP
// #define GRAPHIC_1_PRESENTER_HPP

// #include <gui/model/ModelListener.hpp>
// #include <mvp/Presenter.hpp>

// using namespace touchgfx;

// class Graphic_1_View;

// class Graphic_1_Presenter : public touchgfx::Presenter, public ModelListener
// {
// public:
//     Graphic_1_Presenter(Graphic_1_View& v);
//     virtual ~Graphic_1_Presenter() {};

//     *
//      * The activate function is called automatically when this screen is "switched in"
//      * (ie. made active). Initialization logic can be placed here.
     
//     virtual void activate();

//     /**
//      * The deactivate function is called automatically when this screen is "switched out"
//      * (ie. made inactive). Teardown functionality can be placed here.
//      */
//     virtual void deactivate();

//     virtual void valueIsChanged();

//     void userToModel(uint8_t value);
//     void modelToView();


// private:
//     Graphic_1_Presenter();

//     Graphic_1_View& view;
// };

// #endif // GRAPHICS_PRESENTER_HPP


#ifndef GRAPHIC_1_PRESENTER_HPP
#define GRAPHIC_1_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Graphic_1_View;

class Graphic_1_Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Graphic_1_Presenter(Graphic_1_View& v);
    virtual ~Graphic_1_Presenter() {};

    virtual void activate();
    virtual void deactivate();


    // Hz...
    void valueIsChanged() override;


    // ______________ Model to View ______________

    void modelToView();

    // ______________ View to Model ______________

    void userToModel(uint16_t value); // not used

    // __________________________________________________
    // ______________ Additional functions ______________

    void updateView();

private:
    Graphic_1_Presenter();

    Graphic_1_View& view;
};

#endif // GRAPHICS_PRESENTER_HPP
