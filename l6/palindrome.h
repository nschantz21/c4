#ifndef PALLINDROME_H
#define PALLINDROME_H

template <typename BidirectionalIterator>
bool 
palindrome(
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
