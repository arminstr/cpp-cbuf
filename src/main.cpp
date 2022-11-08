#include "cbuf.h"
#include <iostream>

int main() 
{
    CircularBuffer<char> char_buf(3);

    char_buf.push('R');
    char_buf.push('F');
    char_buf.push('A');

    std::cout << "~~~ CircularBuffer Demo ~~~" << std::endl;
    std::cout << "Buffer Element Count: " << char_buf.count() << std::endl;
    std::cout << "Values from buffer: ";

    char x;
    while(char_buf.count() > 0)
    {   
        char_buf.pop(x);
        std::cout << x;
    }

    std::cout << std::endl;
    std::cout << "Buffer Element Count: " << char_buf.count() << std::endl;

    char_buf.push('~');
    char_buf.push('~');
    char_buf.push('~');

    return 0;
}