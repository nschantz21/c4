/*
 * Nicholas Schantz
 * Assignment 2
 * 2020-07-21
 * queue.h
 *
 * Define Queue class
 */

#include <cstdlib>  // size_t
#include <cassert>
#include <algorithm>

template <typename T>
class Queue
{
public:
    Queue(); // Construct empty queue
    ~Queue(); // Destructor
    Queue(const Queue &); // Copy constructor
    Queue &operator=(const Queue &); // Copy assignment operator
    void push(const T &); // Add elem to back of queue
    void pop(); // Remove front elem from queue
    T &front(); // Return ref to front elem in queue
    const T &front() const; // Return ref to front elem in queue
    bool empty() const; // Return whether queue is empty
    size_t size() const; // Return # of elems in queue
private:
    T *v_; // Elems in queue
    /* Any other private members you need */
    size_t vsize_;
    size_t vused_;
};

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
T* NewCopy(
    const T* src,
    size_t srcsize,
    size_t destsize)
{
    assert(destsize >= srcsize);
    T* dest = new T[destsize];
    try
    {
        std::copy(src, src+srcsize, dest);
    } catch (...) {
        delete[] dest;
        throw;
    }
    return dest;
}


// copy constructor
template<class T>
Queue<T>::Queue(const Queue<T>& other):
    v_(
        NewCopy(
            other.v_,
            other.vsize_,
            other.vsize_
        )
    ),
    vsize_(other.vsize_),
    vused_(other.vused_)
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
        vused_ = other.vused_;
    }
    return *this;
}

template<class T>
void
Queue<T>::push(const T &t)
{
    if (vused_ == vsize_)
    {
        size_t vsize_new = vsize_ * 2 + 1;
        T* v_new = NewCopy(v_, vsize_, vsize_new);        
        delete[] v_;
        v_ = v_new;
        vsize_ = vsize_new;
   } 
   v_[vused_] = t;
   ++vused_;
}



template<class T>
void
Queue<T>::pop()
{
    if(vused_ == 0)
    {
        throw "pop from empty queue";
    } else {
        --vused_;
    }
}

template<class T>
T&
Queue<T>::front()
{
    if (vused_ == 0)
    {
        throw "empty queue";
    }
    return v_[vused_ - 1];
}

template<class T>
const T&
Queue<T>::front()
const
{
    if (vused_ == 0)
    {
        throw "empty queue";
    } else {
        return v_[vused_ - 1];
    }
}

template<class T>
size_t
Queue<T>::size()
const
{
    return vused_;
}

template<class T>
bool
Queue<T>::empty()
const
{
    return vused_ == 0;
}
