#pragma once

#include <memory>
#include <assert.h>
#include <iostream>
#include "State.h"

namespace FSM
{
    class StateMachine
    {
    private:
        State* _deferredNextState;
        std::unique_ptr<State> _currentState;

        void inline ApplyStateTransition()
        {
            if (!_deferredNextState)
            {
                return;
            }
            if (_currentState)
            {
#ifdef ENABLE_FSM_DEBUG
                std::cout << _currentState->name() << ": OnExit()" << std::endl;
#endif
                _currentState->OnExit();
            }
            _currentState.reset(_deferredNextState);
#ifdef ENABLE_FSM_DEBUG
            std::cout << _currentState->name() << ": OnEnter()" << std::endl;
#endif
            _currentState->OnEnter();
            _deferredNextState = nullptr;
        }

    public:
        ~StateMachine()
        {
            if (_deferredNextState)
            {
                delete _deferredNextState;
            }
        }

        void Tick()
        {
            ApplyStateTransition();
            if (_currentState)
            {
#ifdef ENABLE_FSM_DEBUG
                std::cout << _currentState->name() << ": OnUpdate()" << std::endl;
#endif
                _currentState->OnUpdate();
            }
        }

        void TransitionTo(State* const pNewState, bool immediate = false)
        {
            if (pNewState == nullptr)
            {
                _currentState = nullptr;
                return;
            }
            if (pNewState == _currentState.get())
            {
#ifdef ENABLE_FSM_DEBUG
                std::cout << "Trying transitioning to same state! " << pNewState->name() << std::endl;
#endif
                return;
            }
#ifdef ENABLE_FSM_DEBUG
            std::cout << "FSM - Transitioning to '" << pNewState->name() << "' / immediate = " << std::boolalpha << immediate << std::endl;
#endif
            _deferredNextState = pNewState;
            if (immediate)
            {
                Tick();
            }
        }
    };
}
