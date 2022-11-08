#include "cbuf.h"

#define MAX_SIZE 128

int main()
{
    /*
    Testing INT
    */
    int x_i;
    CircularBuffer<int> buf_i(MAX_SIZE);

    // fill buffer to MAX_SIZE with int 42
    while(buf_i.count() < MAX_SIZE)
    {
        buf_i.push(42);
    }
    // empty buffer and check contents
    while(buf_i.count() > 0)
    {
        buf_i.pop(x_i);
        if(x_i != 42) return -1;
    }
    // buffer is empty now, therefore count has to return 0 and pop has to return -1
    if (buf_i.count() != 0) return -1;
    if (buf_i.pop(x_i) != -1) return -1;

    /*
    Testing DOUBLE
    */
    double x_d;
    CircularBuffer<double> buf_d(MAX_SIZE);

    // fill buffer to MAX_SIZE with double 42.0
    while(buf_d.count() < MAX_SIZE)
    {
        buf_d.push(42.0);
    }
    // empty buffer and check contents
    while(buf_d.count() > 0)
    {
        buf_d.pop(x_d);
        if(x_d != 42.0) return -1;
    }
    // buffer is empty now, therefore count has to return 0 and pop has to return -1
    if (buf_d.count() != 0) return -1;
    if (buf_d.pop(x_d) != -1) return -1;

    /*
    Testing STRING
    */
    std::string vision = "RFA - MAKING SPACE ACCESSIBLE FOR EVERY BUSINESS MODEL!";
    std::string x_s;
    CircularBuffer<std::string> buf_s(MAX_SIZE);

    // fill buffer to MAX_SIZE with string vision
    while(buf_s.count() < MAX_SIZE)
    {
        buf_s.push(vision);
    }
    // empty buffer and check contents using std::string compare()
    while(buf_s.count() > 0)
    {
        buf_s.pop(x_s);
        if(vision.compare(x_s) != 0) return -1;
    }
    // buffer is empty now, therefore count has to return 0 and pop has to return -1
    if (buf_s.count() != 0) return -1;
    if (buf_s.pop(x_s) != -1) return -1;

    /*
    Testing CLASS
    Local Class Type is allowed in C++ 11
    */
    class RadioData {
        public:
            uint8_t payload[8];
            uint8_t length;
            uint8_t RSSI;
    };
    RadioData x_rd;
    x_rd.length = 1;
    x_rd.payload[0] = 0x42;
    x_rd.RSSI = 80;

    CircularBuffer<RadioData> buf_rd(MAX_SIZE);
    // fill buffer to MAX_SIZE with custom class RadioData
    while(buf_rd.count() < MAX_SIZE)
    {
        buf_rd.push(x_rd);
    }
    // empty buffer and check contents
    while(buf_rd.count() > 0)
    {
        buf_rd.pop(x_rd);
        if(x_rd.payload[0] != 0x42) return -1;
        if(x_rd.RSSI != 80) return -1;
        if(x_rd.length != 1) return -1;
    }
    // buffer is empty now, therefore count has to return 0 and pop has to return -1
    if (buf_rd.count() != 0) return -1;
    if (buf_rd.pop(x_rd) != -1) return -1;

    return 0;
}