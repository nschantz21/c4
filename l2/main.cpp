/*
 * Nicholas Schantz
 * Assignment 2
 * 2020-07-21
 * main.cpp
 *
 * Unit tests for Queue
 */
#include <iostream>  // clog
#include <string>
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
    Queue<int>* myQueue = new Queue<int>;
    delete myQueue;
}

void testCopyConstructor()
{
    std::clog << "testCopyConstructor\n";
    Queue<int> myQueue;
    myQueue.push(5);
    myQueue.push(6);
    Queue<int> anotherQueue(myQueue);
    assert(myQueue.front() == anotherQueue.front());
}

void testAssignmentConstructor()
{
    std::clog << "testAssignmentConstructor\n";
    Queue<int> myQueue;
    myQueue.push(5);
    myQueue.push(6);
    Queue<int> assignmentQueue;
    assignmentQueue = myQueue;
    assert(myQueue.front() == assignmentQueue.front());
}

void testPush()
{
    std::clog << "testPush\n";
    const int testInt = 10;
    Queue<int> myQueue;
    myQueue.push(testInt);
    assert(myQueue.size() == 1);
    assert(myQueue.front() == testInt);
}

void testPop()
{
    const int testInt = 5;
    Queue<int> myQueue;
    myQueue.push(testInt);
    myQueue.pop();
    // test pop
    assert(myQueue.size() == 0);

    // test exception
    try
    {
        myQueue.pop();
    } catch (const char* exceptionString)
    {
        assert(exceptionString == "pop from empty queue");
    }
}

void testFront()
{
    std::clog << "testFront\n";
    Queue<int> myQueue;
    try
    {
        myQueue.front();
    } catch (const char* exceptionString)
    {
        assert(exceptionString == "empty queue");
    }

    myQueue.push(1);
    int someInt = myQueue.front();
    assert(someInt == 1);
}

void testFrontConst()
{
    std::clog << "testFrontConst\n";
    Queue<int> myQueue;
    try
    {
        myQueue.front();
    } catch (const char* exceptionString)
    {
        assert(exceptionString == "empty queue");
    } 

    myQueue.push(5);
    const int constInt = myQueue.front();
    assert(constInt == 5);
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
