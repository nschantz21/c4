/*

*/
#include <algorithm>
#include <iostream>
#include <iterator>

using std::copy;
using std::cout;
using std::ostream_iterator;


#include "dlist.h"

using Project2::dlist;

int main()
{
    int data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }
    
    // Iterator range construction
    dlist<int> d(data, data + 10);
    // Support for begin/end iterators
    copy(d.begin(), d.end(), ostream_iterator<int> (cout));
    return 0;
}
