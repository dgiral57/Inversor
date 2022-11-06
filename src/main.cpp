#include <Arduino.h>
#include <decoder.h>

#define transistor3 13
#define transistor2 25
#define transistor1 14
#define transistor6 12
#define transistor5 26
#define transistor4 27

int estado = 0;
Decoder decoder;


void setup() {
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(27,OUTPUT);
  Serial.begin(115200);
  decoder.connect();
  
}

void timerMicros(float setupTime) {
  int initialTime = micros();
  while (micros() - initialTime < setupTime)
  {}
}

void MEF(){
  switch (estado){
  case 0:
    decoder.encode("0");
    digitalWrite(transistor1,0);
    digitalWrite(transistor2,0);
    digitalWrite(transistor3,0);
    digitalWrite(transistor4,0);
    digitalWrite(transistor5,0);
    digitalWrite(transistor6,0);
    delay(2000);
    decoder.decodeMessage();
    while (!decoder.getStart()){
      decoder.decodeMessage();
    }
      decoder.resetStart();
      estado = 1;
    break;
  case 1:
    decoder.encode("1");
    digitalWrite(transistor1,1);
    digitalWrite(transistor2,1);
    digitalWrite(transistor3,1);
    digitalWrite(transistor4,0);
    digitalWrite(transistor5,0);
    digitalWrite(transistor6,0);
    decoder.decodeMessage();
    if (decoder.getStop() || decoder.getFreq() == 0){
      decoder.resetStop();
      estado = 0;
    }
    else{
      timerMicros(166666.59375 / decoder.getFreq());
      estado = 2;
    }
    break;
  case 2:
    decoder.encode("2");
    digitalWrite(transistor1,0);
    digitalWrite(transistor2,1);
    digitalWrite(transistor3,1);
    digitalWrite(transistor4,0);
    digitalWrite(transistor5,0);
    digitalWrite(transistor6,0);
    timerMicros(10);
    decoder.decodeMessage();
    if (decoder.getStop() || decoder.getFreq() == 0){
      decoder.resetStop();
      estado = 0;
    }
    else{
      estado = 3;
    }
    break;
  case 3:
    decoder.encode("3");
    digitalWrite(transistor1,0);
    digitalWrite(transistor2,1);
    digitalWrite(transistor3,1);
    digitalWrite(transistor4,1);
    digitalWrite(transistor5,0);
    digitalWrite(transistor6,0);
    decoder.decodeMessage();
    if (decoder.getStop() || decoder.getFreq() == 0){
      decoder.resetStop();
      estado = 0;
    }
    else{
      timerMicros(166666.59375 / decoder.getFreq());
      estado = 4;
    }
    break;
  case 4:
    decoder.encode("4");
    digitalWrite(transistor1,0);
    digitalWrite(transistor2,0);
    digitalWrite(transistor3,1);
    digitalWrite(transistor4,1);
    digitalWrite(transistor5,0);
    digitalWrite(transistor6,0);
    timerMicros(10);
    decoder.decodeMessage();
    if (decoder.getStop() || decoder.getFreq() == 0){
      decoder.resetStop();
      estado = 0;
    }
    else{
      estado = 5;
    }
    break;
  case 5:
    decoder.encode("5");
    digitalWrite(transistor1,0);
    digitalWrite(transistor2,0);
    digitalWrite(transistor3,1);
    digitalWrite(transistor4,1);
    digitalWrite(transistor5,1);
    digitalWrite(transistor6,0);
    decoder.decodeMessage();
    if (decoder.getStop() || decoder.getFreq() == 0){
      decoder.resetStop();
      estado = 0;
    }
    else{
      timerMicros(166666.59375 / decoder.getFreq());
      estado = 6;
    }
    break;
  case 6:
    decoder.encode("6");
    digitalWrite(transistor1,0);
    digitalWrite(transistor2,0);
    digitalWrite(transistor3,0);
    digitalWrite(transistor4,1);
    digitalWrite(transistor5,1);
    digitalWrite(transistor6,0);
    timerMicros(10);
    decoder.decodeMessage();
    if (decoder.getStop() || decoder.getFreq() == 0){
      decoder.resetStop();
      estado = 0;
    }
    else{
      estado = 7;
    }
    break;
  case 7:
    decoder.encode("7");
    digitalWrite(transistor1,0);
    digitalWrite(transistor2,0);
    digitalWrite(transistor3,0);
    digitalWrite(transistor4,1);
    digitalWrite(transistor5,1);
    digitalWrite(transistor6,1);
    decoder.decodeMessage();
    if (decoder.getStop() || decoder.getFreq() == 0){
      decoder.resetStop();
      estado = 0;
    }
    else{
      timerMicros(166666.59375 / decoder.getFreq());
      estado = 8;
    }
    break;
  case 8:
    decoder.encode("8");
    digitalWrite(transistor1,0);
    digitalWrite(transistor2,0);
    digitalWrite(transistor3,0);
    digitalWrite(transistor4,0);
    digitalWrite(transistor5,1);
    digitalWrite(transistor6,1);
    timerMicros(10);
    decoder.decodeMessage();
    if (decoder.getStop() || decoder.getFreq() == 0){
      decoder.resetStop();
      estado = 0;
    }
    else{
      estado = 9;
    }
    break;
  case 9:
    decoder.encode("9");
    digitalWrite(transistor1,1);
    digitalWrite(transistor2,0);
    digitalWrite(transistor3,0);
    digitalWrite(transistor4,0);
    digitalWrite(transistor5,1);
    digitalWrite(transistor6,1);
    decoder.decodeMessage();
    if (decoder.getStop() || decoder.getFreq() == 0){
      decoder.resetStop();
      estado = 0;
    }
    else{
      timerMicros(166666.59375 / decoder.getFreq());
      estado = 10;
    }
    break;
  case 10:
    decoder.encode("10");
    digitalWrite(transistor1,1);
    digitalWrite(transistor2,0);
    digitalWrite(transistor3,0);
    digitalWrite(transistor4,0);
    digitalWrite(transistor5,0);
    digitalWrite(transistor6,1);
    timerMicros(10);
    decoder.decodeMessage();
    if (decoder.getStop() || decoder.getFreq() == 0){
      decoder.resetStop();
      estado = 0;
    }
    else{
      estado = 11;
    }
    break;
  case 11:
    decoder.encode("11");
    digitalWrite(transistor1,1);
    digitalWrite(transistor2,1);
    digitalWrite(transistor3,0);
    digitalWrite(transistor4,0);
    digitalWrite(transistor5,0);
    digitalWrite(transistor6,1);
    decoder.decodeMessage();
    if (decoder.getStop() || decoder.getFreq() == 0){
      decoder.resetStop();
      estado = 0;
    }
    else{
      timerMicros(166666.59375 / decoder.getFreq());
      estado = 12;
    }
    break;
  case 12:
    decoder.encode("12");
    digitalWrite(transistor1,1);
    digitalWrite(transistor2,1);
    digitalWrite(transistor3,0);
    digitalWrite(transistor4,0);
    digitalWrite(transistor5,0);
    digitalWrite(transistor6,0);
    timerMicros(10);
    decoder.decodeMessage();
    if (decoder.getStop() || decoder.getFreq() == 0){
      decoder.resetStop();
      estado = 0;
    }
    else{
      estado = 1;
    }
    break;
  }
}

void loop() {
  MEF();
}