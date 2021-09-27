#ifndef ARCHIVE_PRESENTER_HPP
#define ARCHIVE_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Archive_View;

class Archive_Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Archive_Presenter(Archive_View& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Archive_Presenter() {};

private:
    Archive_Presenter();

    Archive_View& view;
};

#endif // ARCHIVE_PRESENTER_HPP
