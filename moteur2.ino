#define Ain1 2
#define Ain2 3
#define Bin1 4
#define Bin2 5
int i;

int speed = 0;

void setup() {
pinMode(Ain1, OUTPUT);  //Ain1
pinMode(Ain2, OUTPUT);  //Ain2
pinMode(Bin1, OUTPUT);  //Bin1
pinMode(Bin2, OUTPUT);  //Bin2

}

void loop() {
    //Permet de faire tourner dans un sens ou dans l'autre au maximum de vitesse
    digitalWrite(Ain1,HIGH);
    digitalWrite(Ain2,LOW);
    // Permet de faire tourner l'autre moteur 
    digitalWrite(Bin1,HIGH);
    digitalWrite(Bin2,LOW);
    delay(2000);
    digitalWrite(Ain1,LOW);
    digitalWrite(Bin1,LOW);
    
    // Pour controler la vitesse du moteur
    for( i = 65 ; i<=255;i++){
      analogWrite(Ain1,i);
      analogWrite(Bin1,i);
      delay(100);
    }

    /*digitalWrite(Ain1,LOW);
    digitalWrite(Ain2,HIGH);
    //digitalWrite(Bin1,LOW);
    //digitalWrite(Bin2,HIGH);
    delay(1000);*/
    digitalWrite(Ain1,LOW);
    digitalWrite(Ain2,LOW);
    digitalWrite(Bin1,LOW);
    digitalWrite(Bin2,LOW);
    delay(2000);
 
  
}

//int vitesse_Moteur(v){

//}


