/*
 * Nicholas Schantz
 * Assignment 2
 * 2020-07-21
 * queue.h
 *
 * Define Queue class
 */

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
};
