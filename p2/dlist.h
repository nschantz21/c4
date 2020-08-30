#ifndef DLIST_H
#define DLIST_H

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

    // default constructor
    template<T>
    dlist<T>::dlist()
    {
        // initialize variables
        init();
    }


    // copy constructor
    dlist::dlist(const dlist& other)
    {
        // call the range constructor
        this->dlist(other.begin(), other.end());
    }

    // Iterator range constructor
    template<typename InputIterator>
    dlist::dlist(InputIterator first, InputIterator last)
    {
        // add all the nodes of the other
        init();
        while (first != last)
        {
            push_back(first++);
        }
    }

    // Destructor
    dlist::~dlist()
    {
        clear();
        delete head;
        delete tail;

    }
    
    // Copy assginment operator
    dlist &
    dlist::operator=(const dlist &other)
    {
       dlist copy = other;
       std::swap(*this, copy);
       return *this;
    }
    
    // empty() & size()
    bool empty() const
    {
        return size() == 0;
    }
    size_type size() const
    {
        return theSize;
    }
    
    // front() & back()
    T &front()
    {
        return *begin();
    }
    const T &front() const
    {
        return *begin();
    }
    
    T &back()
    {
        return *--end();
    }
    const T &back() const
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

    void
    dlist::pop_front()
    {
        erase(begin());
    }

    void
    template <typename T>
    dlist::push_back(const T &dat)
    {
        insert(end(), dat);
    }

    void dlist::pop_back()
    {
        erase(--end());
    }
    
    iterator 
    dlist::iterator::insert(iterator itr, const T& val)
    {
        Node *p = itr.current;
        theSize++;
        // create new node
        Node* q = new Node(val, p->prev, p);
        // put it in front of the current
        p->prev->next = q;
        p->prev = p->prev->next;
        // return the current
        return p;
    }

    iterator
    dlist::erase(iterator itr)
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
    bool
    dlist::operator==(const dlist& rhs) const
    {
        if (theSize != rhs.theSize) {return false};

        iterator first = begin();
        iterator rhs_first = rhs.begin()
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
    
    bool
    dlist::operator!=(const dlist& rhs) const
    {
        return !(this == rhs);
    }
    // lexicographically compare
    bool
    dlist::operator<(const dlist& rhs) const
    {   
        iterator first1 = begin();
        iterator first2 = rhs.begin();
        if (first2 == rhs.end() || *first2<*first1) 
        {
            return false;
        } else if (*first1 < *first2)
        {
            return true;
        }
        ++firstl; ++first2;

        return (first2 != rhs.end());
    }
    bool
    dlist::operator<=(const dlist& rhs) const
    {
        return !(rhs < this);
    }
    
    bool 
    dlist::operator>(const dlist& rhs) const
    {
        return (rhs < this );
    }
    
    bool
    dlist::operator>=(const dlist&) const
    {
        return !(this < rhs);
    }
    
    // Iterators
    iterator begin()
    {
        return head->next;
    }
    const iterator begin() const
    {
        return head->next;
    }
    iterator end()
    {
        return tail;
    }
    const iterator end() const
    {
        return tail;
    }
    
    void
    dlist::init()
    {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->Next = tail;
        tail->prev = head;
    }

    void
    dlist::clear()
    {
        while(!empty())
        {
            pop_front();
        }
    }


    // iterator definition
    template<typename T>
    class dlist<T>::iterator
    : public std::iterator<bidirectional_iterator_tag, T>
    {
    friend class dlist<T>;
 
    public:
        typedef const T const_reference;
         
        iterator();
        explicit iterator(typename dlist<T>::node*);
        bool operator==(const iterator&) const;
        bool operator!=(const iterator&) const;
        T &operator*();
        const T &operator*() const;
 
        T *operator->();
        const T *operator->() const;
        iterator &operator++();
        const iterator operator++(int);
        iterator &operator--();
        const iterator operator--(int);
    
    private:
        Node *current;
    };

    // constructor
    template<T>
    dlist<T>::iterator::iterator()
        : current(nullptr)
    {}

    // node constructor
    template<T>
    const 
    dlist<T>::iterator::iterator(Node *p)
        : current(p)
    {}

    // equality
    template<T>
    bool
    dlist<T>::iterator::operator==(const iterator &rhs)
    {
        return current == rhs.current;
    }
    
    // inequality
    template<T>
    bool
    dlist<T>::iterator::operator!=(const iterator &rhs)
    {
        return !(*this == rhs);
    }

    // operators
    // dereference
    template<T>
    iterator&
    dlist<T>::iterator::operator*()
    {
        return retrieve();
    }

    // const dereference
    template<T>
    const iterator&
    dlist<T>::iterator::operator*()
    {
        return retrieve();
    }

    // arrow
    template<T>
    T*
    dlist<T>::iterator::operator->()
    {
        return current;
    }

    // const arrow
    template<T>
    const T*
    dlist<T>::iterator::operator->() const
    {
        return current;
    }

    // increment
    template<T>
    iterator&
    dlist<T>::iterator::operator++()
    {
        current = current->next;
        return *this;
    }

    // const increment
    template<T>
    const iterator&
    dlist<T>::iterator::operator++(int)
    {
        const iterator old = *this;
        ++(*this);
        return old;
    }
    

    // decrement
    template<T>
    iterator&
    dlist<T>::iterator::operator--()
    {
       current = current->prev; 
       return *this;
    }
    // const decrement
    template<T>
    const iterator&
    dlist<T>::iterator::operator--(int)
    {
        const iterator old = *this;
        --(*this);
        return old;
    }

    template<T>
    T&
    dlist<T>::iterator::retrieve() const
    {
        return current->data;
    }
}

#endif
