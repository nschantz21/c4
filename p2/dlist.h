
#ifndef DLIST_H
#define DLIST_H

#include <iterator>

using std::bidirectional_iterator_tag;
namespace Project2
{
    template <typename T>
    class dlist
    {
    public:
        // Types
        class iterator;
        typedef size_t size_type;
        typedef T value_type;
        typedef const T const_reference;
        
        // Default constructor
        dlist();

        // Copy constructor
        dlist(const dlist&);

        // Iterator range constructor
        template<typename InputIterator>
        dlist(InputIterator first, InputIterator last);

        // Destructor
        ~dlist();
        
        // Copy assginment operator
        dlist &operator=(const dlist&);
        
        // empty() & size()
        bool empty() const;
        size_type size() const;
        
        // front() & back()
        T &front();
        const T &front() const;
        
        T &back();
        const T &back() const;
        
        // Modifiers
        void push_front(const T&);
        void pop_front();
        void push_back(const T&);
        void pop_back();
        
        iterator insert(iterator, const T&);
        iterator erase(iterator);
        
        // Comparision
        bool operator==(const dlist&) const;
        bool operator!=(const dlist&) const;
        bool operator<(const dlist&) const;
        bool operator<=(const dlist&) const;
        bool operator>(const dlist&) const;
        bool operator>=(const dlist&) const;
        
        // Iterators
        iterator begin();
        const iterator begin() const;
        iterator end();
        const iterator end() const;
    
    private:
        void init();
        void clear();

        struct Node
        {
            value_type data;
            Node *prev;
            Node *next;
        
            Node(
                const value_type &data,
                Node *prev = nullptr,
                Node *next = nullptr)
            : data(data), prev(prev), next(next)
            {}

            Node(
                value_type &&data,
                Node *prev = nullptr,
                Node *next = nullptr)
            : data(std::move(data)), prev(prev), next(next)
            {}

        };

    
        size_type theSize;
        // head and tail will act as sentinel nodes
        Node *head;
        Node *tail;
 
    };

    // iterator definition
    template<typename T>
    class dlist<T>::iterator
    : public std::iterator<bidirectional_iterator_tag, T>
    {
    friend class dlist<T>;
 
    public:
        typedef const T const_reference;
         
        iterator();
        explicit iterator(typename dlist<T>::Node*);
        bool operator==(const iterator&) const;
        bool operator!=(const iterator&) const;
        T &operator*();
        const T &operator*() const;
 
        T *operator->();
        const T *operator->() const;
        iterator &operator++();
        const iterator &operator++(int);
        iterator &operator--();
        const iterator &operator--(int);
    
    private:
        T& retrieve() const;
        Node *current;
    };

    // default constructor
    template <typename T>
    dlist<T>::dlist()
    {
        // initialize variables
        init();
    }


    // copy constructor
    template <typename T>
    dlist<T>::dlist(const dlist& other)
    {
        // call the range constructor
        *this = dlist<T>(other.begin(), other.end());
    }

    // Iterator range constructor
    template<typename T>
    template<typename InputIterator>
    dlist<T>::dlist(InputIterator first, InputIterator last)
    {
        // add all the nodes of the other
        init();
        while (first != last)
        {
            push_back(*first++);
        }
    }

    // Destructor
    template <typename T>
    dlist<T>::~dlist()
    {
        clear();
        delete head;
        delete tail;

    }
    
    // Copy assginment operator
    template <typename T>
    dlist<T> &
    dlist<T>::operator=(const dlist &other)
    {
       dlist copy = other;
       std::swap(*this, copy);
       return *this;
    }
    
    // empty() & size()
    template <typename T>
    bool
    dlist<T>::empty() const
    {
        return size() == 0;
    }

    template <typename T>
    typename dlist<T>::size_type
    dlist<T>::size() const
    {
        return theSize;
    }
    
    // front() & back()
    template <typename T>
    T &
    dlist<T>::front()
    {
        return *begin();
    }
    template <typename T>
    const T &
    dlist<T>::front() const
    {
        return *begin();
    }
    
    template <typename T>
    T &
    dlist<T>::back()
    {
        return *--end();
    }

    template <typename T>
    const T &
    dlist<T>::back() const
    {
        return *--end();
    }
    
    // Modifiers
    template <typename T>
    void
    dlist<T>::push_front(const T &dat)
    {
        insert(begin(), dat);
    }

    template <typename T>
    void
    dlist<T>::pop_front()
    {
        erase(begin());
    }

    template <typename T>
    void
    dlist<T>::push_back(const T &dat)
    {
        insert(end(), dat);
    }

    template <typename T>
    void
    dlist<T>::pop_back()
    {
        erase(--end());
    }
    
    template <typename T>
    typename dlist<T>::iterator
    dlist<T>::insert(typename dlist<T>::iterator itr, const T& val)
    {
        Node *p = itr.current;
        theSize++;
        // create new node
        Node* q = new Node(val, p->prev, p);
        // put it in front of the current
        p->prev->next = q;
        p->prev = q;
        // return the current
        return iterator(p);
    }

    template <typename T>
    typename dlist<T>::iterator
    dlist<T>::erase(iterator itr)
    {
        Node *p = itr.current;
        iterator retVal{p->next};
        // connect adjacent nodes
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        theSize--;
        return retVal;
    }
    
    // Comparision
    template <typename T>
    bool
    dlist<T>::operator==(const dlist& rhs) const
    {
        if (theSize != rhs.theSize) {return false;}

        iterator first = begin();
        iterator rhs_first = rhs.begin();
        while (first != end())
        {
            if (!(*first == *rhs_first))
            {
                return false;
            }
            ++first; ++rhs_first;
        }
        return true;
    }
    
    template <typename T>
    bool
    dlist<T>::operator!=(const dlist& rhs) const
    {
        return !(this == rhs);
    }

    // lexicographically compare
    template <typename T>
    bool
    dlist<T>::operator<(const dlist& rhs) const
    {   
        iterator first1 = begin();
        iterator first2 = rhs.begin();
        if (first2 == rhs.end() || *first2 < *first1) 
        {
            return false;
        } else if (*first1 < *first2)
        {
            return true;
        }
        ++first1; ++first2;

        return (first2 != rhs.end());
    }

    template <typename T>
    bool
    dlist<T>::operator<=(const dlist& rhs) const
    {
        return !(rhs < this);
    }
    
    template <typename T>
    bool 
    dlist<T>::operator>(const dlist& rhs) const
    {
        return (rhs < this );
    }
    
    template <typename T>
    bool
    dlist<T>::operator>=(const dlist& rhs) const
    {
        return !(this < rhs);
    }
    
    // Iterators
    template <typename T>
    typename dlist<T>::iterator
    dlist<T>::begin()
    {
        return dlist<T>::iterator(head->next);
    }

    template <typename T>
    const typename dlist<T>::iterator 
    dlist<T>::begin() const
    {
        return dlist<T>::iterator(head->next);
    }

    template <typename T>
    typename dlist<T>::iterator
    dlist<T>::end()
    {
        return dlist<T>::iterator(tail);
    }

    template <typename T>
    const typename dlist<T>::iterator
    dlist<T>::end() const
    {
        return dlist<T>::iterator(tail);
    }
    
    template <typename T>
    void
    dlist<T>::init()
    {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->Next = tail;
        tail->prev = head;
    }

    template<typename T>
    void
    dlist<T>::clear()
    {
        while(!empty())
        {
            pop_front();
        }
    }



    // constructor
    template <typename T>
    dlist<T>::iterator::iterator()
        : current(nullptr)
    {}

    // node constructor
    template <typename T>
    dlist<T>::iterator::iterator(typename dlist<T>::Node *p)
        : current(p)
    {}

    // equality
    template <typename T>
    bool
    dlist<T>::iterator::operator==(const iterator &rhs) const
    {
        return current == rhs.current;
    }
    
    // inequality
    template <typename T>
    bool
    dlist<T>::iterator::operator!=(const iterator &rhs) const 
    {
        return !(*this == rhs);
    }

    // operators
    // dereference
    template <typename T>
    T&
    dlist<T>::iterator::operator*()
    {
        return retrieve();
    }

    // const dereference
    template <typename T>
    const T&
    dlist<T>::iterator::operator*() const
    {
        return retrieve();
    }

    // arrow
    template <typename T>
    T*
    dlist<T>::iterator::operator->()
    {
        return current;
    }

    // const arrow
    template <typename T>
    const T*
    dlist<T>::iterator::operator->() const
    {
        return current;
    }

    // increment
    template <typename T>
    typename dlist<T>::iterator&
    dlist<T>::iterator::operator++()
    {
        current = current->next;
        return *this;
    }

    // const increment
    template <typename T>
    const typename dlist<T>::iterator&
    dlist<T>::iterator::operator++(int)
    {
        const iterator old = *this;
        ++(*this);
        return old;
    }
    

    // decrement
    template <typename T>
    typename dlist<T>::iterator&
    dlist<T>::iterator::operator--()
    {
       current = current->prev; 
       return *this;
    }

    // const decrement
    template <typename T>
    const typename dlist<T>::iterator&
    dlist<T>::iterator::operator--(int)
    {
        const iterator old = *this;
        --(*this);
        return old;
    }

    template <typename T>
    T&
    dlist<T>::iterator::retrieve() const
    {
        return current->data;
    }
}

#endif
