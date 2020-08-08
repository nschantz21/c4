/*
 * Nicholas Schantz
 * 2020-08-11
 * main.cpp
 * Program to test auto_ptr class
 */

#include <iostream> // clog
#include <cassert> // assert
#include "auto_ptr.h"

using std::clog;

// constructors
void testDefaultConstructor()
{
    clog << "testDefaultConstructor\n";
    auto_ptr<int> myPointer;
    assert(sizeof(myPointer));
}

void testConstructor()
{
    clog << "testConstructor\n";
    int *myIntPointer = new int(1);
    auto_ptr<int> myAutoInt(myIntPointer);
    // not sure if way to test without using dereference operator
    assert(*myAutoInt == *myIntPointer);
}

void testCopyConstructor()
{
    clog << "testCopyConstructor\n";
    auto_ptr<int> autoInt(new int(2));
    auto_ptr<int> anotherAutoInt(autoInt);
    assert(*anotherAutoInt == 2);
    assert(autoInt.get() == 0);
}

void testConversionConstructor()
{
    clog << "testConversionConstructor\n";
    auto_ptr<short> autoShort(new short(5));
    auto_ptr<int> autoInt(autoShort);
    assert(*autoInt == 5);
    assert(autoShort.get() == 0);
}

// accessors
void testDereference()
{
    clog << "testDereference\n";
    auto_ptr<int> autoInt(new int(6));
    assert(*autoInt == 6);
}

void testGet()
{
    clog << "testGet\n";
    auto_ptr<int> autoInt(new int(7));
    assert(*(autoInt.get()) == 7);
}

// assignment
void testAssignment()
{
    clog << "testAssignment\n";
    auto_ptr<int> autoInt(new int(8));
    auto_ptr<int> anotherInt;
    anotherInt = autoInt;
    assert(*anotherInt == 8);
    assert(autoInt.get() == 0);
}

void testConvertibleAssignment()
{
    clog << "testConvertibleAssignment\n";
    auto_ptr<short> autoShort(new short(9));
    auto_ptr<int> autoInt;
    autoInt = autoShort;
    assert(*autoInt == 9);
    assert(autoShort.get() == 0);
}

// release & reset
void testRelease()
{
    clog << "testRelease\n";
    auto_ptr<int> autoInt(new int(10));
    int* anotherInt = autoInt.release();
    assert(*anotherInt == 10);
    assert(autoInt.get() == 0);
}

void testReset()
{
    clog << "testReset\n";
    auto_ptr<int> autoInt(new int(10));
    int* anotherInt = new int(11);
    autoInt.reset(anotherInt);
    assert(*autoInt == 11);
}

int main()
{
    // constructors
    testDefaultConstructor();
    testConstructor();
    testCopyConstructor();
    testConversionConstructor();

    // accessors
    testDereference();
    testGet();

    // assignment
    testAssignment();
    testConvertibleAssignment();

    // release & reset
    testRelease();
    testReset();
    
    return 0;
}
