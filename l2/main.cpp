/*
 * Nicholas Schantz
 * Assignment 2
 * 2020-07-21
 * main.cpp
 *
 * Unit tests for Queue
 */
#include <iostream>  // clog
#include "queue.h"

// unittests
void testConstructor()
{
    std::clog << "testConstructor\n";
    Queue<int> myQueue;
}

void testDestructor()
{
    std::clog << "testDestructor\n";
    Queue<int> myQueue;
}

void testCopyConstructor()
{
    std::clog << "testCopyConstructor\n";
    Queue<int> myQueue;
    Queue<int> anotherQueue(myQueue);
}

void testAssignmentConstructor()
{
    std::clog << "testAssignmentConstructor\n";
    Queue<int> myQueue;
    Queue<int> assignmentQueue;
    assignmentQueue = myQueue;
}

void testPush()
{
    std::clog << "testPush\n";
    Queue<int> myQueue;
    myQueue.push(10);
}

void testPop()
{
    Queue<int> myQueue;
    myQueue.push(5);

}

void testFront()
{
    std::clog << "testFront\n";
    Queue<int> myQueue;
    myQueue.push(1);
    int someInt = myQueue.front();
    assert(someInt == 1);
}

void testFrontConst()
{
    std::clog << "testFrontConst\n";
    Queue<int> myQueue;
    myQueue.push(1);
    const int constInt = myQueue.front();
}

void testEmpty()
{
    std::clog << "testEmpty\n";
    Queue<int> myQueue;
    assert(myQueue.empty());
}

void testSize()
{
    std::clog << "testSize\n";
    Queue<int> myQueue;
    myQueue.push(1);
    assert(myQueue.size() == 1);
}

int main()
{
    // unit tests
    testConstructor();
    testDestructor();
    testCopyConstructor();
    testAssignmentConstructor();
    testPush(); 
    testFront();
    testFrontConst();
    testEmpty();
    testSize();

    return 0;
}
