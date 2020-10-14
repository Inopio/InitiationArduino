#include <Arduino.h>

int trig = 6;
int echo = 9;
int led = 3;
long lecture_echo;
long cm; 

void setup(){
    Serial.begin(9600);
    pinMode(trig,OUTPUT);
    digitalWrite(trig,LOW);
    pinMode(echo,INPUT);
    pinMode(led,OUTPUT);
}

void loop(){
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    lecture_echo = pulseIn(echo,HIGH);
    cm = lecture_echo / 58;
    if(cm < 5 && cm != 0){
        digitalWrite(led,HIGH);
        Serial.println(cm);
    }
    else{
        digitalWrite(led,LOW);
    }
}