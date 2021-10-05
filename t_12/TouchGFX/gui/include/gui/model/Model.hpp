#ifndef MODEL_HPP
#define MODEL_HPP

#include <touchgfx/Utils.hpp>
#include <touchgfx/hal/Types.hpp>

#include "global_pins.h"

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
    std::array<float, COUNT_AI> getCurrentAI();
    std::array<float, COUNT_AO> getCurrentAO();
    std::array<uint8_t, COUNT_DI> getCurrentDI();
    std::array<uint8_t, COUNT_DO> getCurrentDO();

    std::array<float, COUNT_AI> getCurrentStepPointsAI();

    std::array<uint8_t, COUNT_AI> getCurrentTypeAI();

    std::array<uint8_t, COUNT_AI> getCurrentModeProcessingAI();

    std::array<uint8_t, COUNT_DI> getCurrentFunctionDI();

    std::array<uint8_t, COUNT_DO> getCurrentModeControlDO();

    // ______________ (user)Presenter to Model ______________
    void setCurrentAI(std::array<float, COUNT_AI> values);
    void setCurrentAO(std::array<float, COUNT_AO> values);
    void setCurrentDI(std::array<uint8_t, COUNT_DI> values);
    void setCurrentDO(std::array<uint8_t, COUNT_DO> values);

    void setCurrentStepPointsAI(std::array<float, COUNT_AI> values);

    void setCurrentTypeAI(std::array<uint8_t, COUNT_AI> values);

    void setCurrentModeProcessingAI(std::array<uint8_t, COUNT_AI> values);

    void setCurrentFunctionDI(std::array<uint8_t, COUNT_DI> values);

    void setCurrentModeControlDO(std::array<uint8_t, COUNT_DO> values);

protected:
    /**
     * Pointer to the currently active presenter.
     */
    ModelListener* modelListener;

private:
    std::array<float, COUNT_AI> m_AI;
    std::array<float, COUNT_AO> m_AO;

    std::array<uint8_t, COUNT_DI> m_DI;
    std::array<uint8_t, COUNT_DO> m_DO;

    // Step points
    std::array<float, COUNT_AI> m_SP_AI;

    // Types AI --> 50М, 100P, Pt100, Pt1000, L, K, J, S, B, 0..20mA, 4..20mA, 0..10V
    std::array<uint8_t, COUNT_AI> m_T_AI;

    // Mode processing AI --> 0:"absolut"; 1:"difference"; 2:"average"
    std::array<uint8_t, COUNT_AI> m_MP_AI;

    // Function DI --> 0:"STOP"; 1:"START/STOP"; 2:"Reset commit";
    std::array<uint8_t, COUNT_DI> m_F_DI;

    // Mode control DO --> 0:"ON/OFF"; 1:"Signaling device"; 2:"Manual control";
    std::array<uint8_t, COUNT_DO> m_MC_DO;
};

#endif /* MODEL_HPP */
