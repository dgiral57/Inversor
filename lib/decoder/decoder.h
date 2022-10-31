#ifndef DECODER
#define DECODER
#include <Arduino.h>
#include <BluetoothSerial.h>

class Decoder{
private:
    int frequency;
    bool start;
    bool stop;
    BluetoothSerial serialBT;
public:
    Decoder();
    int getFreq();
    bool getStart();
    bool getStop();
    void decodeMessage();
    void resetStop();
    void resetStart();
};
#endif