#ifndef MODEL_HPP
#define MODEL_HPP

#include <touchgfx/Utils.hpp>
#include <touchgfx/hal/Types.hpp>

#include <array>

class ModelListener;

/**
 * The Model class defines the data model in the model-view-presenter paradigm.
 * The Model is a singular object used across all presenters. The currently active
 * presenter will have a pointer to the Model through deriving from ModelListener.
 *
 * The Model will typically contain UI state information that must be kept alive
 * through screen transitions. It also usually provides the interface to the rest
 * of the system (the backend). As such, the Model can receive events and data from
 * the backend and inform the current presenter of such events through the modelListener
 * pointer, which is automatically configured to point to the current presenter.
 * Conversely, the current presenter can trigger events in the backend through the Model.
 */
class Model
{
public:
    Model();

    /**
     * Sets the modelListener to point to the currently active presenter. Called automatically
     * when switching screen.
     */
    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    /**
     * This function will be called automatically every frame. Can be used to e.g. sample hardware
     * peripherals or read events from the surrounding system and inject events to the GUI through
     * the ModelListener interface.
     */
    void tick();


    // ______________ Model to Presenter ______________
    std::array<double> getCurrentAI();
    std::array<double> getCurrentAO();
    std::array<bool> getCurrentDI();
    std::array<bool> getCurrentDO();


    // ______________ (user)Presenter to Model ______________
    void setCurrentAI(std::array<double> values);
    void setCurrentAO(std::array<double> values);
    void setCurrentDI(std::array<bool> values);
    void setCurrentDO(std::array<bool> values);

    void setCurrentStepPointsAI(std::array<double> values);

protected:
    /**
     * Pointer to the currently active presenter.
     */
    ModelListener* modelListener;

private:
    std::array<double, 4> m_AI;
    std::array<double, 4> m_AO;

    std::array<bool, 4> m_DI;
    std::array<bool, 4> m_DO;

    std::array<double, 4> m_stepPoints_AI;
};

#endif /* MODEL_HPP */
