#ifndef PALLINDROME_H
#define PALLINDROME_H

#include <iterator> 
using namespace std;

template <typename BidirectionalIterator>
bool 
pallindrome(
    BidirectionalIterator first,
    BidirectionalIterator last)
{
    // special case of empty container
    if (first == last) return true;
    while (first != --last)
    {
        if (*first != *last)
        {
            return false;
        }
        ++first;
    }
    return true;
}

#endif
