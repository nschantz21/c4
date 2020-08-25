/*
 *
 * implement an iterator for class template IntegerRange.
 * It will be the job of the iterator to produce the numbers in the range
 * during iteration.
 */

#ifndef INTEGERRANGE_H
#define INTEGERRANGE_H

#include <iterator>
#include <cassert>
#include <iostream>

using std::clog;

using std::input_iterator_tag;

// Represents all integer values in the range [low, high).
// low must be <= high.
template <typename T>
class IntegerRange
{
public:
    // forward declare iterator class
    class iterator;

    IntegerRange(T low, T high) : low_(low), high_(high)
    {
        assert(low <= high);
    }

    const iterator begin() const
    {
        return iterator(low_);
    }

    const iterator end() const
    {
        return iterator(high_);
    }

private:
    const T low_, high_;
};

// probably only needs to be a input iterator
// define input iterator operations
template <typename T>
class IntegerRange<T>::iterator: 
    public  std::iterator<input_iterator_tag, T>
{
public:
    // constructor
    iterator(T pData)
        : pData_(&pData)
    {}

    // pre-increment
    iterator &operator++()
    {
        clog << "pre-increment\n";
        ++pData_;
        return *this;
    }

    // post-increment
    iterator operator++(int)
    {
        clog << "post-increment\n";
        iterator tmp(*this);
        operator++();
        return tmp;
    }

    // equality
    bool operator==(const iterator& rhs) const
    {
        clog << "equality" << *pData_ << *(rhs.pData_) << "\n";
        return pData_ == rhs.pData_;
    }

    // inequality
    bool operator!=(const iterator& rhs) const
    {
        clog << "inequality\n";
        return pData_ != rhs.pData_;
    }

    // dereference - rvalue
    const T &operator*() const
    {
        clog << "dereference\n";
        return *pData_;
    }
    
    // arrow - rvalue
    const T *operator->() const
    {
        clog << "arrow\n";
        return pData_;
    }
    
private:
    T *pData_;
};


#endif
