//
//  StateMachine.h
//  StateMachine
//
//  Created by mengfei.mf on 4/28/15.
//  Copyright (c) 2015 mengfei.mf. All rights reserved.
//

#ifndef __StateMachine__StateMachine__
#define __StateMachine__StateMachine__

#include <stdio.h>
#include <functional>
#include <map>

namespace feimengspirit
{
    
typedef int32_t retval_t;

class StateMachine
{
public:
    typedef uint32_t state;
    typedef std::function<retval_t(void*,void*)> Transaction;
    typedef std::pair<state, state> StateMap;
    typedef std::map<StateMap, Transaction> ActionMap;
    
public:
    StateMachine();
    ~StateMachine();
    retval_t add(state from, state to, Transaction action);
    retval_t start(state initState);
    retval_t swithTo(state to, void *parm, void *result);

private:
    state m_currentState;
    ActionMap m_map;
};
}

#endif /* defined(__StateMachine__StateMachine__) */
