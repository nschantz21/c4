/*
 *
 * Program to test IntegerRange class
 */
#include <algorithm>
#include <iostream>
#include <iterator>

using std::ostream_iterator;
using std::cout;
 
#include "IntegerRange.h"

// find_if short
// copy int
// for_each long
// all_of long long
bool IsOddAndPositive (int i) {
  return ((i%2)==1);
}

void print(int i)
{
    cout << i << "\t";
}

bool greaterThanFive(int i)
{
    return i > 5;
}

int main()
{
    IntegerRange<int> intRange(-2, 3);
    std::copy(
        intRange.begin(),
        intRange.end(),
        ostream_iterator<int>(cout, " "));
    cout << "\n";

    IntegerRange<short> shortRange(-5, 20);
    IntegerRange<short>::iterator it = std::find_if(
        shortRange.begin(),
        shortRange.end(),
        IsOddAndPositive
    );
    cout << *it << "\n";

    IntegerRange<long> longRange(-500000010, -500000000);
    std::for_each(longRange.begin(), longRange.end(), print);
    cout << "\n";

    IntegerRange<long long> longLongRange(100000000000000000, 100000000020000000);
    bool allGtFive = std::all_of(longLongRange.begin(), longLongRange.end(), greaterThanFive);
    cout << allGtFive << "\n";


    return 0;
}
