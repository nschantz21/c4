/*
 * Nicholas Schantz
 * 2020-08-18
 * main.cpp
 * Program to test pallindrome and compress algorithms
 */
#include <list>
#include <iostream>
#include <cassert>

#include <algorithm>

using std::list;
using std::clog;

#include "pallindrome.h"
#include "compress.h"

// pallindrome unit tests
void testEmptyPallindrome()
{
    std::clog << "testEmptyPallindrome\n";
    list<int> ls1;
    assert(pallindrome(ls1.begin(), ls1.end()));
}

void testEvenPallindrome()
{
    std::clog << "testEvenPallindrome\n";
    int data[] = {0, 1, 2, 2, 1, 0};
    list<int> ls1(data, data + 6);
    assert(pallindrome(ls1.begin(), ls1.end()));
}

void testOddPallindrome()
{
    std::clog << "testOddPallindrome\n";
    int data[] = {0, 1, 2, 3, 2, 1, 0};
    list<int> ls1(data, data + 7);
    assert(pallindrome(ls1.begin(), ls1.end()));
}

void testEvenNonPallindrome()
{
    std::clog << "testEvenNonPallindrome\n";
    int data[] = {0, 1, 2, 4, 1, 0};
    list<int> ls1(data, data + 6);
    assert(!pallindrome(ls1.begin(), ls1.end()));

}

void testOddNonPallindrome()
{
    std::clog << "testOddNonPallindrome\n";
    int data[] = {0, 1, 2, 3, 3, 1, 0};
    list<int> ls1(data, data + 7);
    assert(!pallindrome(ls1.begin(), ls1.end()));
}




void testEmptyCompress()
{
    std::clog << "testEmptyCompress" << "\n";
    list<int> ls1, ls2, expected;
    compress(ls1.begin(), ls1.end(), back_inserter(ls2));
    assert(ls2 == expected);
}

void testNoConsecutiveDuplicates()
{
    std::clog << "testNoConsecutiveDuplicates" << "\n";
    int data[] = {1, 2, 3, 1 ,2, 3};
    list<int> ls1(data, data + 6), ls2;
    list<int> expected(ls1);
    compress(ls1.begin(), ls1.end(), back_inserter(ls2));

    //std::for_each(expected.begin(), expected.end(), print);
    //clog << "\n\n";
    //std::for_each(ls2.begin(), ls2.end(), print);
    assert(ls2 == expected);
}

void testConsecutiveDuplicates()
{
    std::clog << "testConsecutiveDuplicates" << "\n";
    int data[] = {1, 1, 2, 2, 1, 1};
    list<int> ls1(data, data + 6), ls2;
    compress(ls1.begin(), ls1.end(), back_inserter(ls2));
    list<int> expected = {1, 2, 1};
    //std::for_each(expected.begin(), expected.end(), print);
    //clog << "\n\n";
    //std::for_each(ls2.begin(), ls2.end(), print);

    assert(ls2 == expected);
}

int main()
{
    // pallindrome
    testEmptyPallindrome();
    testEvenPallindrome();
    testOddPallindrome();
    testEvenNonPallindrome();
    testOddNonPallindrome();

    // compress
    testEmptyCompress();
    testNoConsecutiveDuplicates();
    testConsecutiveDuplicates();
    return 0;
}
