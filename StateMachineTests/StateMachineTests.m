//
//  StateMachineTests.m
//  StateMachineTests
//
//  Created by mengfei.mf on 4/28/15.
//  Copyright (c) 2015 mengfei.mf. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <XCTest/XCTest.h>
#import "StateMachine.h"

using namespace feimengspirit;

@interface StateMachineTests : XCTestCase

@end

@implementation StateMachineTests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample {
    // This is an example of a functional test case.
    XCTAssert(YES, @"Pass");
}

- (void)testStateMachine
{
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
    
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
