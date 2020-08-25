/*
 *
 * Program to test IntegerRange class
 */
#include <algorithm>
#include <iostream>
#include <iterator>

using std::copy;
using std::ostream_iterator;
using std::cout;
 
#include "IntegerRange.h"

template <class InputIterator, class T>
   T accumulate (InputIterator first, InputIterator last, T init)
{
    assert(first == last);
    cout << "accumulate" << *first << "\n";
  while (first!=last) {
    cout << init;
    init = init + *first;  // or: init=binary_op(init,*first) for the binary_op version
    ++first;
  }
  return init;
}
// find_if short
// copy int
// for_each long
// all_of long long

int main()
{
    IntegerRange<int> r1(-2, 3);
    copy(r1.begin(), r1.end(), ostream_iterator<int>(cout, " "));

    IntegerRange<unsigned> r2(0, 6);
    copy(r2.begin(), r2.end(), ostream_iterator<unsigned>(cout, " "));
    
    int sum = 0;
    accumulate(r2.begin(), r2.end(), sum);

    cout << "end\n" << sum << "\n";
    return 0;
}
