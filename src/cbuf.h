#include <stdlib.h>
#include <memory>
#include <mutex>

/*
Template class accepts different data types and is therefore a good fit for the
circular buffer which has to accept arbitrary type.
This is a minimal implementation featuring only the requested functions.
*/ 
template <typename T> 
class CircularBuffer {
    public:
        CircularBuffer(size_t size);
        ~CircularBuffer();
        int push(T item);
        int pop(T& item);
        size_t count(void);
    private:
        std::unique_ptr<T[]> buffer;
        size_t push_index;
        size_t max_size;
        size_t current_size;
        std::mutex cbuf_mutex;
};

/*
Constructor of CircularBuffer template class. 
Intitializing buffer as an std::unique_ptr of size max_size.
*/
template <typename T>
CircularBuffer<T>::CircularBuffer(size_t size)
{
    max_size = size;
    push_index = 0;
    current_size = 0;
    buffer = std::unique_ptr<T[]>(new T[max_size]);
}

template <typename T>
CircularBuffer<T>::~CircularBuffer(void) {}

/*
Function for pushing data into the circular buffer. 
Uses a mutex to enable deterministic behaviour on access by threaded applications.

In case data pushing fails, the return value is -1;
*/
template <typename T>
int CircularBuffer<T>::push(T item)
{
    if(cbuf_mutex.try_lock())
    {
        buffer[push_index] = item;
        push_index = (push_index + 1) % max_size;
        if (current_size < max_size) current_size += 1;
        cbuf_mutex.unlock();
        return 0;
    }
    return -1;
}

/*
Function for retreiving data from the circular buffer. 
Uses a mutex to enable deterministic behaviour on access by threaded applications.
The popped value is stored by reference in the parameter T& item.

If the mutex is is still locked or no data is available, the return value is -1;
*/
template <typename T>
int CircularBuffer<T>::pop(T& item)
{
    if(current_size == 0)
        return -1;
    if(cbuf_mutex.try_lock()){
        int pop_index = (push_index - current_size);
        if (pop_index < 0) pop_index = max_size + pop_index;
        item = buffer[pop_index];
        current_size -= 1;
        cbuf_mutex.unlock();
        return 0;
    }
    return -1;
}

/*
Returns the amount of elements currently stored in the CircularBuffer
*/
template<typename T>
size_t CircularBuffer<T>::count()
{
    return current_size;
}
