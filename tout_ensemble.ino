#include <Wire.h>
#include "Adafruit_DRV2605.h"

//---------- init coeur ----------
unsigned long previousMillisCoeur = 0 ;
const uint8_t effect = 4;
int lance = 0;
long ecart_battement = 1000;
long ecart_battement2 = 100;
Adafruit_DRV2605 drv;

//---------- init urine -----------
unsigned long previousMillisSon = 0;
const int speakerPin = 12;
const int ton = 311;
const long duree_son = 1000;
int sound = 0;

//----------init moteur------------
#define Ain1 2
#define Ain2 3
int vit = 255; //A choisir entre 65-255

// ============================ SETUP ======================================
void setup() {
  Serial.begin(9600);
  //------------ setup coeur ----------------
  drv.begin(); // Demarrage du driver du coeur
  drv.selectLibrary(1);
  drv.setMode(DRV2605_MODE_INTTRIG);
  drv.setWaveform(0, effect);  // play effect
  drv.setWaveform(1, 0);       // end waveform*/

  //------------ setup poumon ----------------
  pinMode(Ain1, OUTPUT);  //Ain1
  pinMode(Ain2, OUTPUT);  //Ain2
}

// ================================= MAIN LOOP =============================
void loop() {
  unsigned long currentMillis = millis();

  analogWrite(Ain1,vit);

  if (Serial.available() > 0) {
    if (Serial.read() - '0' == 1) {
      Serial.println("On allume le son");
      sound = 1;
      previousMillisSon = currentMillis;
    }
  }

  if (sound == 1) {
    if (currentMillis - previousMillisSon < duree_son) {
      tone(speakerPin, ton);
    }
    else {
      Serial.println("On eteint le son");
      noTone(speakerPin);
      sound = 0;
    }
  }

  if (lance == 0 && (currentMillis - previousMillisCoeur >= ecart_battement)) {
    drv.go();
    lance = 1;
    previousMillisCoeur = currentMillis;
    Serial.println("Lance 1");
  }
  if (lance == 1 && (currentMillis - previousMillisCoeur >= ecart_battement2)) {
    drv.go();
    lance = 0;
    Serial.println("Lance 2");
  }

  



}




