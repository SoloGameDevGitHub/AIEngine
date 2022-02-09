#include "StateMachine.h"
#include "MoveTo.h"
#include "Idle.h"

using namespace std;

int main()
{
    FSM::StateMachine fsm;

    fsm.TransitionTo(new FSM::Idle(), true);
    fsm.TransitionTo(new FSM::MoveTo());
    fsm.Tick();
    fsm.TransitionTo(nullptr);
    cout << endl;

    fsm.TransitionTo(nullptr);
    fsm.TransitionTo(new FSM::Idle(), true);
    fsm.TransitionTo(nullptr);
    cout << endl;

    fsm.TransitionTo(nullptr);
    fsm.TransitionTo(new FSM::MoveTo());
    fsm.Tick();
    fsm.TransitionTo(nullptr);
    
    return 0;
}
