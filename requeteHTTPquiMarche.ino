// Ces deux bibliothèques sont indispensables pour le shield
#include <SPI.h>
#include <Ethernet.h>
#include <String.h>

char c;
// L'adresse MAC du shield
byte mac[] = {0x90, 0xA2 ,0xDA, 0x10, 0x7A, 0x45};
// L'adresse IP que prendra le shield
IPAddress ip(192,168,1,47);
// L'objet qui nous servira à la communication
EthernetClient client;
// Le serveur à interroger
//char serveur[] = "192.168.1.42"; // A la maison
char serveur[] = "172.17.2.56"; // A l'école
int erreur;

void setup() {
  Serial.begin(9600);
  Serial.println("init");
  Ethernet.begin(mac);
  delay(10000);
  Serial.println("ethernet begin...");
  // On connecte notre Arduino sur "perdu.com" et le port 80 (defaut pour l'http)
  erreur = client.connect(serveur, 8086);


  if(erreur == 1) {
      // Pas d'erreur ? on continue !
      Serial.println("Connexion OK, envoi en cours...");

      // On construit l'en-tête de la requête
      //client.println("GET /query?db=PressionA&q=SELECT * FROM pression order by time desc limit 5 HTTP/1.1");
      //delay(1000);
      client.println("GET /query?db=PressionA&q=SELECT%20*%20FROM%20pression%20order%20by%20time%20desc%20limit%201 HTTP/1.1");
      client.println("Host: 172.17.2.56");
      client.println("Connection: close");
      client.println();
  } else {
    // La connexion a échoué :(
    Serial.println(erreur);
    Serial.println("Echec de la connexion");
    switch(erreur) {
      case(-1):
        Serial.println("Time out");
        break;
      case(-2):
        Serial.println("Serveur invalide");
        break;
      case(-3):
        Serial.println("Tronque");
        break;
      case(-4):
        Serial.println("Reponse invalide");
        break;
    }
    while(1); // Problème = on bloque
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // if there are incoming bytes available
  // from the server, read them and print them:
  if (client.available()) {
    c = client.read();
    Serial.print(c);
  }
 
  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();

    // do nothing forevermore:
    while (true);
  }
}
