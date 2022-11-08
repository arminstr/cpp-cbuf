#include "cbuf.h"
#include <thread>
#include <iostream>

#define MAX_SIZE 8
#define NUMBER_OF_ACCESS 2048

CircularBuffer<double> buf(MAX_SIZE);

/*
Function pushing NUMBER_OF_ACCESS elements with the value passed as argument.
*/
void pushElements(int value)
{
    for(int i = 0; i < NUMBER_OF_ACCESS; i++)
    {
        buf.push(value);
    }
}

/*
Function removing elements and comparing them to the passed value.
*/
void popElements(int value)
{
    double x;
    for(int i = 0; i < NUMBER_OF_ACCESS; i++)
    {
        int ret = buf.pop(x);
        if(ret == 0 && x != value)
        {
            std::cout << "x: " << x << " expected value: " << value << " return: " << ret << std::endl;
            throw std::runtime_error("error");
        }
    }
}

int main() 
{
    /*
    start threaded pushing 1 into the buffer
    */
    std::thread t1(pushElements, 1);
    /*
    The buffer is filled with 1 by the push elements thread.
    Therefore pop should return only 1.
    */
    std::thread t2(popElements, 1);

    t1.join();
    t2.join();

    /*
    The number of elements after Threaded pushing and popping is non deterministig and dependant on the sceduling of the threads.
    We might end up getting a NUMBER_OF_ACCESS elements pushed first and popped afterwards and therefore have no elements at all. 
    If the pushing and popping happens in parallel the operations might collide while accessing the mutex and a 
    random amount of elements is left in the buffer after end of execution. 

    Therefore the only reliable test is writing a known value and checking if we get only this exact value back.
    */
    
    std::cout << "Number of Elements after Threaded pushing and popping of MAX_SIZE: " << buf.count() << std::endl;
    return 0;
}
