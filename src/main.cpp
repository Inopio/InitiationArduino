#include <Arduino.h>

int trig = 6;
int echo = 9;
int led = 3;
int motor = A0;
unsigned long lecture_echo;
long cm; 
float motorOut = 0;

void setup(){
    Serial.begin(9600);
    pinMode(trig,OUTPUT);
    digitalWrite(trig,LOW);
    pinMode(echo,INPUT);
    pinMode(motor,OUTPUT);
}

void loop(){
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    lecture_echo = pulseIn(echo,HIGH);
    cm = lecture_echo / 58;
    int res = (cm * 255) / 15;
    if(res > 255){
        res = 255;
    }
    //le sensor envoie des 0 periodiquement meme si on capte une valeur
    //donc pour éviter que ça coupe le moteur on utilise exponential moving average
    motorOut = motorOut * 0.99f + res * 0.01f;
    Serial.println(motorOut);
    Serial.println(lecture_echo);
    //analogWrite(motor,(int)motorOut);    
}