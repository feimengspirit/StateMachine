####状态机工具

**说明:**一个简单的状态机模型(确定的有限状态机)，用于在状态变化自动执行副作用。

**范例:**

	StateMachine sm;
    StateMachine::state init = 0,
    state1 = 1,
    state2 = 2,
    state3 = 3;
    
    sm.add(init, state1, [](void*param, void*result)->retval_t {
        NSLog(@"init->state1");
        return 0;
    });
    
    sm.add(state1, state2, [](void*param, void*result)->retval_t {
        NSLog(@"state1->state2");
        return 0;
    });
    
    sm.add(state1, state3, [](void*param, void*result)->retval_t {
        NSLog(@"state1->state3");
        return 0;
    });
    
    sm.add(state2, state3, [](void*param, void*result)->retval_t {
        NSLog(@"state2->state3");
        return 0;
    });
    
    sm.start(init);
    sm.swithTo(state1, 0, 0);
    sm.swithTo(state3, 0, 0);

借用了C++11中的Lambda特性。