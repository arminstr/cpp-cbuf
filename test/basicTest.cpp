#include "cbuf.h"

#define MAX_SIZE 128

int main()
{
    int x;
    CircularBuffer<int> buf(MAX_SIZE);

    // fill buffer to MAX_SIZE with int 42
    while(buf.count() < MAX_SIZE)
    {
        buf.push(42);
    }

    // empty buffer and check contents
    while(buf.count() > 0)
    {
        buf.pop(x);
        if(x != 42) return -1;
    }

    // buffer is empty now, therefore count has to return 0 and pop has to return -1
    if (buf.count() != 0) return -1;
    if (buf.pop(x) != -1) return -1;

    // fill buffer with -1
    while(buf.count() < MAX_SIZE)
    {
        buf.push(-1);
    }
    // push the value 1 for MAX_SIZE / 2 times
    for(int i = 0; i < MAX_SIZE/2; i++)
    {
        buf.push(1);
    }
    // Due to the circular overwriting nature of CircularBuffer<T>::push(T item)
    // the sum over all buffer elements must be zero.
    // Therefore the elements are retreived from the buffer, summed and compared to 0.
    int element_sum = 0;
    while(buf.count() > 0)
    {
        buf.pop(x);
        element_sum += x;
    }
    if(element_sum != 0){
        return -1;
    }

    return 0;
}