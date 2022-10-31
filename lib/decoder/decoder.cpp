#include <decoder.h>

Decoder::Decoder(){
        this->frequency = 0;
        this->start = false;
        this->stop = false;
        serialBT.begin("Inversor");
        Serial.print("Connecting");
        while(serialBT.connected() == false){
            Serial.print(".");
            delay(500);
        }
        Serial.println("");
        Serial.println("Connected");
    }

void Decoder::decodeMessage(){
    if (this->serialBT.available()){
        for (int i = 0; i < 3; i++) {
            this->frequency = serialBT.read();
            this->start = serialBT.read();
            this->stop = serialBT.read();
        }
    }
}

bool Decoder::getStart(){
    return this->start;
}

bool Decoder::getStop(){
    return this->stop;
}

int Decoder::getFreq(){
    return this->frequency;
}

void Decoder::resetStop(){
        this->stop = false;
    }
void Decoder::resetStart(){
        this->start = false;
    }

