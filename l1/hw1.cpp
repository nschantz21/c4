/*
 * Nicholas Schantz
 * hw1.cpp
 * 2020-07-14
 */
// imports
#include <algorithm>  // generate_n, transform
#include <deque>
#include <numeric>  // accumulate
#include <iostream>  // clog
#include <string>
#include <cctype>  // toupper
#include <vector>
#include <sstream>   // ostringstream
#include <iterator>  // ostream_iterator

// helper functions
int count = 1;
int myGenerator() {
    return count++;
}

bool isEven(int num) {return (num % 2) == 0;}

// unit tests
void testDeque()
{
    const int expectedCumSum = 55;
    // deque and algo functionality uint test
    std::deque<int> myDeque;

    // populate deque with generate_n 1-10
    std::generate_n(std::back_inserter(myDeque), 10, myGenerator);

    // use accumulate on deque
    int cumSum = std::accumulate(myDeque.begin(), myDeque.end(), 0);
    
    // assert sum is 55
    if (cumSum != expectedCumSum) {
        std::clog << "testDeque FAILED: Expected cumulative sum of " <<
        expectedCumSum << ". Got " << cumSum << "\n";
    } else {
        std::clog << "testDeque PASSED\n";
    }
}

void testString()
{
    // unit test for string and algo
    // create lowercase alphabet
    std::string lowerCase = "abcdefghijklmnopqrstuvwxyz";
    std::string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // convert to uppercase with transform
    std::transform(lowerCase.begin(), lowerCase.end(), lowerCase.begin(),
        toupper);

    // assert all uppercase
    if (lowerCase.compare(upperCase) != 0) {
        std::clog << "testString FAILED: Expected " << upperCase << ". Got "
        << lowerCase << "\n";
    } else {
        std::clog << "testString PASSED\n";
    }
}

void testVector()
{
    // unit test vector
    const std::string expectedString = "24681013579";
    // create array 10-1
    int myArray[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arraySize = sizeof(myArray) / sizeof(myArray[0]);
    
    // create vector from array
    std::vector<int> myVector(myArray, myArray + arraySize);

    // partition values
    std::vector<int>::iterator bound;
    bound = std::partition(myVector.begin(), myVector.end(), isEven);
    
    // sort each partition
    std::sort(myVector.begin(), bound);
    std::sort(bound, myVector.end());
    //for_each(myVector.begin(), myVector.end(), print);
    
    // copy to ostream
    std::ostringstream myStream;
    std::ostream_iterator<int> oIter(myStream);
    std::copy(myVector.begin(), myVector.end(), oIter);

    // assert ostream matches expected output
    if (myStream.str().compare(expectedString) != 0)
    {
        std::clog << "testVector FAILED: Expected: " << expectedString <<
        ". Got: " << myStream.str() << "\n";
    } else {
        std::clog << "testVector PASSED\n";
    }
}

int main()
{
    // 1
    testDeque();
    // 2
    testString();
    // 3
    testVector();
    return 0;
}
