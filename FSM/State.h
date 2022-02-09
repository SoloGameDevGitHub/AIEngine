#pragma once

#include <typeinfo>

namespace FSM
{
    class State
    {
    public:
        virtual ~State() = 0;
        const char* name() const
        {
            return typeid(*this).name();
        }
        virtual void OnEnter() = 0;
        virtual void OnUpdate() = 0;
        virtual void OnExit() = 0;
    };

    State::~State()
    {
        //
    }
}
