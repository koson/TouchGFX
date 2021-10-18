/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/settings__screen/Settings_ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

Settings_ViewBase::Settings_ViewBase() :
    updateItemCallback(this, &Settings_ViewBase::updateItemCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));

    slideMenu1.setState(touchgfx::SlideMenu::EXPANDED);
    slideMenu1.setVisiblePixelsWhenCollapsed(0);
    slideMenu1.setHiddenPixelsWhenExpanded(0);
    slideMenu1.setAnimationEasingEquation(touchgfx::EasingEquations::cubicEaseInOut);
    slideMenu1.setAnimationDuration(18);
    slideMenu1.setExpandedStateTimeout(180);
    slideMenu1.setXY(0, 0);

    background.setBitmap(touchgfx::Bitmap(BITMAP_COUNTER_BOX_ID));
    background.setPosition(0, 0, 480, 272);
    background.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    digitalClock.setPosition(9, 12, 60, 27);
    digitalClock.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    digitalClock.setTypedText(touchgfx::TypedText(T_SINGLEUSEID85));
    digitalClock.displayLeadingZeroForHourIndicator(true);
    digitalClock.setDisplayMode(touchgfx::DigitalClock::DISPLAY_24_HOUR);
    digitalClock.setTime24Hour(10, 10, 0);

    logo.setBitmap(touchgfx::Bitmap(BITMAP_DIR4069_BRAND6_ID));
    logo.setPosition(170, 15, 147, 20);
    logo.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    b_toControlScreen.setXY(137, 225);
    b_toControlScreen.setBitmaps(touchgfx::Bitmap(BITMAP_B_CONTROL_0_ID), touchgfx::Bitmap(BITMAP_B_CONTROL_1_ID), touchgfx::Bitmap(BITMAP_EMPTY_ICON_BUTTON_0_ID), touchgfx::Bitmap(BITMAP_EMPTY_ICON_BUTTON_1_ID));
    b_toControlScreen.setIconXY(0, 0);

    b_toLoginScreen.setXY(66, 225);
    b_toLoginScreen.setBitmaps(touchgfx::Bitmap(BITMAP_B_LOGIN_0_ID), touchgfx::Bitmap(BITMAP_B_LOGIN_1_ID), touchgfx::Bitmap(BITMAP_EMPTY_ICON_BUTTON_0_ID), touchgfx::Bitmap(BITMAP_EMPTY_ICON_BUTTON_1_ID));
    b_toLoginScreen.setIconXY(0, 0);

    b_toGraphicScreen.setXY(213, 225);
    b_toGraphicScreen.setBitmaps(touchgfx::Bitmap(BITMAP_B_GRAPHICS_0_ID), touchgfx::Bitmap(BITMAP_B_GRAPHICS_1_ID), touchgfx::Bitmap(BITMAP_EMPTY_ICON_BUTTON_0_ID), touchgfx::Bitmap(BITMAP_EMPTY_ICON_BUTTON_1_ID));
    b_toGraphicScreen.setIconXY(0, 0);

    b_toAnalyticScreen.setXY(288, 225);
    b_toAnalyticScreen.setBitmaps(touchgfx::Bitmap(BITMAP_B_ANALYTICS_0_ID), touchgfx::Bitmap(BITMAP_B_ANALYTICS_1_ID), touchgfx::Bitmap(BITMAP_EMPTY_ICON_BUTTON_0_ID), touchgfx::Bitmap(BITMAP_EMPTY_ICON_BUTTON_1_ID));
    b_toAnalyticScreen.setIconXY(0, 0);

    b_toArchiveScreen.setXY(358, 225);
    b_toArchiveScreen.setBitmaps(touchgfx::Bitmap(BITMAP_B_ARHIVE_0_ID), touchgfx::Bitmap(BITMAP_B_ARHIVE_1_ID), touchgfx::Bitmap(BITMAP_EMPTY_ICON_BUTTON_0_ID), touchgfx::Bitmap(BITMAP_EMPTY_ICON_BUTTON_1_ID));
    b_toArchiveScreen.setIconXY(0, 0);

    sw_unit_AI_1.setPosition(347, 123, 60, 65);
    sw_unit_AI_1.setHorizontal(false);
    sw_unit_AI_1.setCircular(false);
    sw_unit_AI_1.setEasingEquation(touchgfx::EasingEquations::backEaseOut);
    sw_unit_AI_1.setSwipeAcceleration(10);
    sw_unit_AI_1.setDragAcceleration(10);
    sw_unit_AI_1.setNumberOfItems(10);
    sw_unit_AI_1.setSelectedItemOffset(0);
    sw_unit_AI_1.setDrawableSize(105, 0);
    sw_unit_AI_1.setDrawables(sw_unit_AI_1ListItems, updateItemCallback);
    sw_unit_AI_1.animateToItem(0, 0);

    si_AI_1.setBitmap(touchgfx::Bitmap(BITMAP_T_AI_1_ID));
    si_AI_1.setPosition(79, 69, 69, 16);
    si_AI_1.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    si_AI_2.setBitmap(touchgfx::Bitmap(BITMAP_T_AI_2_ID));
    si_AI_2.setPosition(79, 108, 69, 16);
    si_AI_2.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    si_AI_3.setBitmap(touchgfx::Bitmap(BITMAP_T_AI_3_ID));
    si_AI_3.setPosition(79, 146, 69, 16);
    si_AI_3.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    si_AI_4.setBitmap(touchgfx::Bitmap(BITMAP_T_AI_4_ID));
    si_AI_4.setPosition(79, 186, 69, 16);
    si_AI_4.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    b_DI_1.setXY(9, 59);
    b_DI_1.setBitmaps(touchgfx::Bitmap(BITMAP_DI1_0_ID), touchgfx::Bitmap(BITMAP_DI1_1_ID));

    b_DI_2.setXY(9, 98);
    b_DI_2.setBitmaps(touchgfx::Bitmap(BITMAP_DI2_0_ID), touchgfx::Bitmap(BITMAP_DI2_1_ID));

    b_DI_3.setXY(9, 138);
    b_DI_3.setBitmaps(touchgfx::Bitmap(BITMAP_DI3_0_ID), touchgfx::Bitmap(BITMAP_DI3_1_ID));

    b_DI_4.setXY(9, 178);
    b_DI_4.setBitmaps(touchgfx::Bitmap(BITMAP_DI4_0_ID), touchgfx::Bitmap(BITMAP_DI4_1_ID));

    b_DO_1.setXY(410, 59);
    b_DO_1.setBitmaps(touchgfx::Bitmap(BITMAP_DO1_0_ID), touchgfx::Bitmap(BITMAP_DO1_1_ID));

    b_DO_2.setXY(410, 98);
    b_DO_2.setBitmaps(touchgfx::Bitmap(BITMAP_DO2_0_ID), touchgfx::Bitmap(BITMAP_DO2_1_ID));

    b_DO_3.setXY(410, 138);
    b_DO_3.setBitmaps(touchgfx::Bitmap(BITMAP_DO3_0_ID), touchgfx::Bitmap(BITMAP_DO3_1_ID));

    b_DO_4.setXY(410, 178);
    b_DO_4.setBitmaps(touchgfx::Bitmap(BITMAP_DO4_0_ID), touchgfx::Bitmap(BITMAP_DO4_1_ID));

    lb_date.setPosition(79, 13, 75, 24);
    lb_date.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    lb_date.setLinespacing(0);
    Unicode::snprintf(lb_dateBuffer, LB_DATE_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID97).getText());
    lb_date.setWildcard(lb_dateBuffer);
    lb_date.setTypedText(touchgfx::TypedText(T_SINGLEUSEID96));

    cc_typeAI1.setXY(167, 59);

    add(__background);
    add(slideMenu1);
    add(background);
    add(digitalClock);
    add(logo);
    add(b_toControlScreen);
    add(b_toLoginScreen);
    add(b_toGraphicScreen);
    add(b_toAnalyticScreen);
    add(b_toArchiveScreen);
    add(sw_unit_AI_1);
    add(si_AI_1);
    add(si_AI_2);
    add(si_AI_3);
    add(si_AI_4);
    add(b_DI_1);
    add(b_DI_2);
    add(b_DI_3);
    add(b_DI_4);
    add(b_DO_1);
    add(b_DO_2);
    add(b_DO_3);
    add(b_DO_4);
    add(lb_date);
    add(cc_typeAI1);
}

void Settings_ViewBase::setupScreen()
{
    sw_unit_AI_1.initialize();
    for (int i = 0; i < sw_unit_AI_1ListItems.getNumberOfDrawables(); i++)
    {
        sw_unit_AI_1ListItems[i].initialize();
    }
    cc_typeAI1.initialize();
}

void Settings_ViewBase::updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex)
{
    if (items == &sw_unit_AI_1ListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        cc_units* cc = (cc_units*)d;
        sw_unit_AI_1UpdateItem(*cc, itemIndex);
    }
}