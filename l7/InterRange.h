/*
 *
 * implement an iterator for class template IntegerRange.
 * It will be the job of the iterator to produce the numbers in the range
 * during iteration.
 */

#ifndef INTEGERRANGE_H
#define INTEGERRANGE_H

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
template <typename T>
class IntegerRange<T>::iterator: 
    public  std::iterator<random_access_iterator_tag, T>
{
public:
    // default constructor

    
};


#endif
