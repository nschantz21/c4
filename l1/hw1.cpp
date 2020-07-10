/*
 * Nicholas Schantz
 * hw1.cpp
 * 2020-07-14
 */
// imports
#include <algorithm>  // generate_n
#include <deque>
#include <numeric>  // accumulate
#include <iostream>

int count = 1;
int myGenerator() {
    return count++;
}

void print(int n) {
    std::cout << n << "\n";
}

int main()
{ 
    // deque and algo functionality uint test
    // populate deque with generate_n 1-10
    std::deque<int> myDeque;//(10, 0);

    std::generate_n(std::back_inserter(myDeque), 10, myGenerator);
    for_each(myDeque.begin(), myDeque.end(), print);

    
    // use accumulate on deque
    int cumSum = std::accumulate(myDeque.begin(), myDeque.end(), 0);
    
    // assert sum is 55
    std::cout << cumSum << "\n";
    
    // unit test for string and algo
    // create lowercase alphabet
    
    // convert to uppercase with transform
    
    // assert all uppercase
    
    
    // unit test vector
    // create array 10-1
    
    // create vector from array
    
    // partition values
    
    // sort each partition
    
    // copy to ostream
    
    // assert ostream matches expected output
    return 0;
}
