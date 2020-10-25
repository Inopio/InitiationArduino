#include <Arduino.h>

//Pour connaitre le nombre d'actionnement de 
//l'interrupteur
int cpt = 1;
bool mode1 = false;
bool mode2 = false;
bool mode3 = false;
int interrupteur = 4;

//Fonction pour générer la couleur rouge,vert ou bleue
//Utilise les pins analogiques
void RGBWrite(int r, int g, int b){
  analogWrite(A1,r);
  analogWrite(A2,g);
  analogWrite(A3,b);
}

void setup() {
  Serial.begin(9600);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  //pin avec résistance 
  pinMode(interrupteur,INPUT_PULLUP);
}

void loop(){ 
  //Interrupteur fermé et première fermeture 
  if(digitalRead(interrupteur) == LOW && cpt == 1){
    Serial.println("Circuit fermé : led rouge !");
    cpt++;
    mode1 = true;
    mode3 = false;
    delay(1000);
  }
  //Interrupteur fermé et deuxième fermeture 
  else if(digitalRead(interrupteur) == LOW && cpt == 2){
    Serial.println("Circuit fermé : led verte !");
    cpt++;
    mode1 = false;
    mode2 = true;
    delay(1000);
  }
  //Interrupteur fermé et troisième fermeture 
  else if(digitalRead(interrupteur) == LOW && cpt == 3){
    Serial.println("Circuit fermé : led bleue !");
    cpt = 1;
    mode2 = false;
    mode3 = true;
    delay(1000);
  }
  //Led clignote 
  else if(mode1){
    RGBWrite(255, 0, 0);
    delay(500);
    RGBWrite(0, 0, 0);
    delay(500);
  }
  else if(mode2){
    RGBWrite(0, 255, 0);
    delay(500);
    RGBWrite(0, 0, 0);
    delay(500);
  }
  else if(mode3){
    RGBWrite(0, 0, 255);
    delay(500);
    RGBWrite(0, 0, 0);
    delay(500);
  }
  
}

/*
void loop() {
  
  if(digitalRead(4) == HIGH){
    digitalWrite(8,HIGH);
    Serial.println("Circuit fermé !");
  }else{
    digitalWrite(8,LOW);
    Serial.println("Circuit Ouvert ! ");
  }
}


void loop() {
  
  if(digitalRead(4) == HIGH && cpt == 1){
    digitalWrite(8,HIGH);
    delay(1000);
    Serial.println("Mode 1");
    cpt ++;
  }else if(digitalRead(4) == HIGH && cpt == 2){
    Serial.println("Mode 2");
    mode2 = true;
    delay(1000);
    cpt ++;
  }else if(digitalRead(4) == HIGH && cpt == 3){
    mode2 = false;
    Serial.println("Mode 3");
    digitalWrite(8,LOW);
    delay(1000);
    cpt = 1;
  }
  else if(mode2){
    digitalWrite(8,HIGH);
    delay(500);
    digitalWrite(8,LOW);
    delay(500);
  }
  
}
*/
