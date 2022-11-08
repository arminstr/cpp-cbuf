#include "cbuf.h"

template <typename T>
CircularBuffer<T>::CircularBuffer(size_t size)
{
    max_size = size;
    push_index = 0;
    current_size = 0;
    buffer = std::unique_ptr<T[]>(new T[max_size]);
}

template <typename T>
CircularBuffer<T>::~CircularBuffer(void)
{
}

template <typename T>
void CircularBuffer<T>::push(T item)
{
    buffer[push_index] = item;
    push_index = (push_index + 1) % max_size;
    if (current_size < max_size) current_size += 1;
}

template <typename T>
T CircularBuffer<T>::pop(void)
{
    if(current_size == 0)
        throw std::runtime_error("Circular Buffer is Empty!");
    int pop_index = (push_index - current_size);
    if (pop_index < 0) pop_index = max_size + pop_index;
    T item = buffer[pop_index];
    current_size -= 1;
    return item;
}

template<typename T>
size_t CircularBuffer<T>::count()
{
    return current_size;
}


int main() {
    CircularBuffer<double> number_buf(8);
    CircularBuffer<std::string> name_buf(32);

    printf("\n~~~~ Most Basic Circular Buffer Test ~~~~\n");
    std::cout << "Initial size: " << number_buf.count() << std::endl;

    double x = 42.0;
    for (int i = 0; i < 10; i++){
        number_buf.push(x);
        std::cout << "Size: " << number_buf.count() << std::endl;
        x += 1;
    }
    x = number_buf.pop();
    std::cout << "Popped Pushed Element: " << x << std::endl;
    std::cout << "Size afer pop and push: " << number_buf.count() << std::endl;
    number_buf.push(x);
    x = number_buf.pop();
    std::cout << "Popped Pushed Element: " << x << std::endl;
    std::cout << "Size afer pop and push: " << number_buf.count() << std::endl;
    
    std::string company = "RFA";
    name_buf.push(company);
    company = name_buf.pop();
    std::cout << "Popped Pushed Element: " << company << std::endl;
    std::cout << "Size afer pop and push: " << name_buf.count() << std::endl;

    return 0;
}
