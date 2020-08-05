/*
 * Nicholas Schantz
 * 2020-08-11
 * auto_ptr.h
 * Define auto_ptr class
 */

#ifndef AUTO_PTR_H
#define AUTO_PTR_H

template <typename X>
class auto_ptr
{
public:
    // Constructors
    // guarantee no throw
    explicit auto_ptr (X * = 0) throw();
    auto_ptr(auto_ptr &) throw();
    template <typename Y> auto_ptr(auto_ptr<Y> &) throw();

    // Destructor
    ~auto_ptr() throw();

    // Access
    X *get() const throw();
    X &operator*() const throw();
    X *operator->() const throw();
    
    // Assignment
    auto_ptr &operator=(auto_ptr &) throw();
    template <typename Y> auto_ptr &operator=(auto_ptr<Y> &) throw();
    
    // Release & Reset
    X *release() throw();
    void reset(X * = 0) throw();
private:
    X* ptr_;
};


// all template functions need to be defined in header
template <typename X>
auto_ptr<X>::auto_ptr(X* p = 0) throw() : ptr_(p)
{}

template<typename X>
auto_ptr<X>::auto_ptr(auto_prt &ap) throw() : ptr_(ap.release()) {}

template<typename X, typename Y>
auto_ptr<X>::auto_ptr(auto_ptr<Y>& ap) throw(): ptr_(ap.release()) {}

auto_prt::~auto_prt() throw()
{
    delete ptr_;
}

template<X>
auto_ptr<X>::auto_ptr<X>&
operator=(auto_prt<X> &p) throw()
{
    reset(p.release);
    return *this;
}

// convertible assignment operator
template <typename X, typename Y>
auto_ptr<X>&
operator=(auto_prt<Y>& p) throw()
{
    reset(p.release());
    return *this;
}

X&
operator*() const throw()
{
    assert(ptr_ != 0);
    return *ptr_;
}

X*
auto_prt::operator->() const throw()
{
    assert(ptr_ != 0);
    return ptr_;
}

template<X>
X*
auto_ptr::get() const thorw()
{
    return ptr_;
}

template<X>
X*
auto_prt::release() throw()
{
    X* tmp = ptr_;
    ptr_ = 0;
    return tmp;
}

template<X>
void
auto_ptr::reset(X* p = 0) throw()
{
    if (p != ptr_)
    {
        delete ptr_;
        ptr_ = p;
    }
}



#endif
