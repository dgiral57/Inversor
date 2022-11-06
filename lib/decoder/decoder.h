#ifndef DECODER
#define DECODER
#include <Arduino.h>


class Decoder{
private:
    int frequency;
    bool start;
    bool stop;
public:
    Decoder();
    int getFreq();
    bool getStart();
    bool getStop();
    void decodeMessage();
    void resetStop();
    void resetStart();
    void connect();
    void encode(String message);
};
#endif