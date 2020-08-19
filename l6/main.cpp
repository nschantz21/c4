/*
 * Nicholas Schantz
 * 2020-08-18
 * main.cpp
 * Program to test palindrome and compress algorithms
 */
#include <list>
#include <iostream>
#include <cassert>

using std::list;
using std::clog;

#include "palindrome.h"
#include "compress.h"

// palindrome unit tests
void testEmptyPalindrome()
{
    std::clog << "testEmptyPalindrome\n";
    list<int> ls1;
    assert(palindrome(ls1.begin(), ls1.end()));
}

void testEvenPalindrome()
{
    std::clog << "testEvenPalindrome\n";
    int data[] = {0, 1, 2, 2, 1, 0};
    list<int> ls1(data, data + 6);
    assert(palindrome(ls1.begin(), ls1.end()));
}

void testOddPalindrome()
{
    std::clog << "testOddPalindrome\n";
    int data[] = {0, 1, 2, 3, 2, 1, 0};
    list<int> ls1(data, data + 7);
    assert(palindrome(ls1.begin(), ls1.end()));
}

void testEvenNonPalindrome()
{
    std::clog << "testEvenNonPalindrome\n";
    int data[] = {0, 1, 2, 4, 1, 0};
    list<int> ls1(data, data + 6);
    assert(!palindrome(ls1.begin(), ls1.end()));

}

void testOddNonPalindrome()
{
    std::clog << "testOddNonPalindrome\n";
    int data[] = {0, 1, 2, 3, 3, 1, 0};
    list<int> ls1(data, data + 7);
    assert(!palindrome(ls1.begin(), ls1.end()));
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
    assert(ls2 == expected);
}

void testConsecutiveDuplicates()
{
    std::clog << "testConsecutiveDuplicates" << "\n";
    int data[] = {1, 1, 2, 2, 1, 1};
    list<int> ls1(data, data + 6), ls2;
    compress(ls1.begin(), ls1.end(), back_inserter(ls2));
    list<int> expected = {1, 2, 1};
    assert(ls2 == expected);
}

int main()
{
    // palindrome
    testEmptyPalindrome();
    testEvenPalindrome();
    testOddPalindrome();
    testEvenNonPalindrome();
    testOddNonPalindrome();

    // compress
    testEmptyCompress();
    testNoConsecutiveDuplicates();
    testConsecutiveDuplicates();
    return 0;
}
