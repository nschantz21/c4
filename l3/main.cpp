/*
 * Nicholas Schantz
 * Assignment 3
 * 2020-07-28
 * main.cpp
 *
 * Program to test the following classes: StreamProcessorAlgorithm, 
 * UppercasingSPA, DigitStrippingSPA
 */

#include <iostream>  
#include <sstream>
#include <cassert>
#include "spa.h"
#include "dsspa.h"
#include "ucspa.h"

using std::cout;
using std::string;
// unit tests
// I have used newlines instead of spaces in the test strings to emulate a file
// with a single word per line
void testUCSPAProcess1()
{
    cout << "testUCSPAProcess1\n";
    string expectedString = "TESTING\nSTRING\n";

    std::stringstream ss;
    ss << "testing\nstring";
    std::stringstream os;
    UppercasingSPA myUC(ss, os);
    myUC.process();
    assert(os.str() == expectedString);
}

void testUCSPAProcess2()
{
    cout << "testUCSPAProcess2\n";
    string expectedString = "ANOTHER\nTESTING\nSTRING\n";

    std::stringstream ss;
    ss << "anOtHeR tEStINg STRING";
    std::stringstream os;
    UppercasingSPA myUC(ss, os);
    myUC.process();
    assert(os.str() == expectedString);
}

void testDSSPAProcess1()
{
    cout << "testDSSPAProcess1\n";
    string expectedString = "tst\ntrng\n";

    std::stringstream ss;
    ss << "t3st\n5tr1ng\n";
    std::stringstream os;
    DigitStrippingSPA myDS(ss, os);
    myDS.process();
    assert(os.str() == expectedString);
}

void testDSSPAProcess2()
{
    cout << "testDSSPAProcess2\n";
    string expectedString = "test\ndsspa\ntwo\n";

    std::stringstream ss;
    ss << "t3est\nanother\nds55spa\ntwo0\n";
    std::stringstream os;
    DigitStrippingSPA myDS(ss, os);
    myDS.process();
    assert(os.str() == expectedString);
}

int main()
{
    testUCSPAProcess1();
    testUCSPAProcess2();
    testDSSPAProcess1();
    testDSSPAProcess2();
    return 0;
}
