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

// only needs to be an input iterator
template <typename T>
class IntegerRange<T>::iterator: 
    public  std::iterator<input_iterator_tag, T>
{
public:
    // constructor
    iterator(const T &pData)
        : pData_(pData)
    {}

    // pre-increment
    iterator &operator++()
    {
        ++pData_;
        return *this;
    }

    // post-increment
    iterator operator++(int)
    {
        iterator tmp(*this);
        operator++();
        return tmp;
    }

    // equality
    bool operator==(const iterator& rhs) const
    {
        return pData_ == rhs.pData_;
    }

    // inequality
    bool operator!=(const iterator& rhs) const
    {
        return pData_ != rhs.pData_;
    }

    // dereference - rvalue
    const T &operator*() const
    {
        return pData_;
    }
    
    // arrow - rvalue
    const T *operator->() const
    {
        static T tmp = pData_;
        const T* tmpPtr = &tmp;
        return tmpPtr;
    }

    void print()
    {
        clog << "Testfunc"<< pData_ << "\n";
    }
    
private:
    T pData_;
};


#endif
