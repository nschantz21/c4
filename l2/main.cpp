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

}

void testPop()
{

}

void testFront()
{

}

void testFrontConst()
{

}

void testEmpty()
{

}

void testSize()
{

}

int main()
{
    // Default Constructor
    testConstructor();
    //testDestructor();
    //testCopyConstructor();
    //testAssignmentConstructor();

    // Destructor

    //

    return 0;
}
