#include <stdlib.h>
#include <memory>
#include <string>
#include <iostream>
template <typename T> 
class CircularBuffer {
    public:
        CircularBuffer(size_t size);
        ~CircularBuffer();
        void push(T item);
        T pop(void);
        size_t count(void);
    private:
        std::unique_ptr<T[]> buffer;
        size_t front;
        size_t back;
        size_t max_size;
        T empty;
};
