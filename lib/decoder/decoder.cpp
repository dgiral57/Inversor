#include <decoder.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

Decoder::Decoder()
{
    this->frequency = 0;
    this->start = false;
    this->stop = false;
}

void Decoder::connect()
{
    SerialBT.begin("Inversor");
    Serial.println("Ready to pair");
}

void Decoder::decodeMessage()
{
    if (SerialBT.available())
    {
        for (int i = 0; i < 3; i++)
        {
            if ( i == 0){
                while (!SerialBT.available()){};
                this->start = SerialBT.parseInt();
                Serial.println(this->start);
            }
            else if (i == 1){
                while (!SerialBT.available()){};
                this->stop = SerialBT.parseInt();
                Serial.println(this->stop);
            }

            else {
                while (!SerialBT.available()){};
                this->frequency = SerialBT.parseInt();
                Serial.println(this->frequency);
            }
        }
        SerialBT.println("ok");
    }
}
void Decoder::encode(String message)
{
    SerialBT.println(message);
}

bool Decoder::getStart()
{
    return this->start;
}

bool Decoder::getStop()
{
    return this->stop;
}

int Decoder::getFreq()
{
    return this->frequency;
}

void Decoder::resetStop()
{
    this->stop = false;
}
void Decoder::resetStart()
{
    this->start = false;
}
