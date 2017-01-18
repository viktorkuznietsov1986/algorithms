//
//  HeapSortTest.m
//  Sorting
//
//  Created by Viktor Kuznietsov on 7/15/16.
//  Copyright © 2016 Viktor Kuznietsov. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <HeapSort.h>
#include <vector>

@interface HeapSortTest : XCTestCase

@end

@implementation HeapSortTest

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
    // Use XCTAssert and related functions to verify your tests produce the correct results.
    std::vector<int> arr;
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(5);
    arr.push_back(4);
    
    CHeapSort::sort(arr);
    
    
    
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
