/*
 * Nicholas Schantz
 * Assignment 2
 * 2020-07-21
 * queue.cpp
 *
 * Implement Queue class
 */
#include "queue.h"
#include <cassert>

// default constructor
template<class T>
Queue<T>::Queue():
    v_(new T[10]),
    vsize_(10),
    vused_(0)
{

}

// destructor
template<class T>
Queue<T>::~Queue()
{
    delete[] v_;
}

// helper function
template<class T>
T* NewCopy(const T* src, size_t srcsize, size_t destsize)
{
    assert(destsize >= srcsize);
    T* dest = new T[destsize];
    try
    {
        copy(src, src+srcsize, dest);
    } catch (...) {
        delete[] dest;
        throw;
    }
    return dest;
}


// copy constructor
template<class T>
Queue<T>::Queue(const Queue<T>& other):
    v_(NewCopy(other.v_, other.vsize_, other.vsize_)),
    vsize_(other.vsize),
    vused_(other.vsize)
{
}

// assignment constructor
template<class T>
Queue<T>&
Queue<T>::operator=(const Queue<T>& other)
{
    if (this != &other)
    {
        T* v_new = NewCopy(
            other.v_,
            other.vsize_,
            other.vsize_
        );
        delete[] v_;
        v_ = v_new;
        vsize_ = other.vsize_;
        vused_ = other.vused;
    }
    return *this;
}
