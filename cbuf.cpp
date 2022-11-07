#include "cbuf.h"

template <typename T>
CircularBuffer<T>::CircularBuffer(size_t size)
{
    max_size = size;
    front = 0;
    back = 0;
    buffer = std::unique_ptr<T[]>(new T[max_size]);
}

template <typename T>
CircularBuffer<T>::~CircularBuffer(void)
{
}

template <typename T>
void CircularBuffer<T>::push(T item)
{
    if (front == (back - 1) % max_size)
        throw std::runtime_error("Circular Buffer is Full!");
    buffer[front] = item;
    front = (front + 1) % max_size;;
}

template <typename T>
T CircularBuffer<T>::pop(void)
{
    if(front == back)
        throw std::runtime_error("Circular Buffer is Empty!");
    T item = buffer[back];
    buffer[back] = empty; 

    back = (back + 1) % max_size;
    return item;
}

template<typename T>
size_t CircularBuffer<T>::count()
{
    if (front >= back)
      return front - back;
    return max_size - (back - front);
}


int main() {
    CircularBuffer<double> gqlueBuf(8);
    CircularBuffer<std::string> companyBuf(32);

    printf("\n~~~~ Most Basic Circular Buffer Test ~~~~\n");

    double x = 42.0;
    gqlueBuf.push(x);
    x = gqlueBuf.pop();
    std::cout << "Popped Pushed Element: " << x << std::endl;
    std::cout << "Size afer pop and push: " << gqlueBuf.count() << std::endl;

    std::string company = "RFA";
    companyBuf.push(company);
    company = companyBuf.pop();
    std::cout << "Popped Pushed Element: " << company << std::endl;
    std::cout << "Size afer pop and push: " << companyBuf.count() << std::endl;

    return 0;
}
