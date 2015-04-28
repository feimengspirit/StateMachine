//
//  StateMachine.cpp
//  StateMachine
//
//  Created by mengfei.mf on 4/28/15.
//  Copyright (c) 2015 mengfei.mf. All rights reserved.
//

#include "StateMachine.h"

namespace feimengspirit
{
StateMachine::StateMachine()
:m_currentState(-1)
{
}

StateMachine::~StateMachine()
{
}
    
retval_t StateMachine::add(state from, state to, Transaction action)
{
    m_map[StateMap(from, to)] = action;
    return 0;
}

retval_t StateMachine::start(state initState)
{
    m_currentState = initState;
    return 0;
}

retval_t StateMachine::swithTo(state to, void *param, void *result)
{
    Transaction action;
    if (!(action = m_map[StateMap(m_currentState, to)])) {
        return -1;
    }
    
    retval_t rtn = -1;
    if ((rtn = action(param, result)) != 0) {
        return rtn;
    }

    m_currentState = to;
    return 0;
}

}