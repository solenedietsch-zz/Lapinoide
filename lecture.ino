String lu = "{results:[{statement_id:0,series:[{name:pression,columns:[time,timey,valeur],values:[[2019-02-11T10:14:39.4165658Z,-603114727,11]]}]}]}";
String tempsy;
int valeur;

void setup() {
  
  Serial.begin(9600);
  Serial.println(lu);

  String retenu = recupVal(lu);
  Serial.print("On enleve ce qui nous intéresse pas : ");
  Serial.println(retenu);
  
  String temps = supFinVirg(retenu);
  Serial.print("Time : ");
  Serial.println(temps);
  
  retenu = supDebVirg(retenu);
 
  
  tempsy = supFinVirg(retenu);
  valeur = supDebVirg(retenu).toInt();
  
  Serial.print("Temps y : ");
  Serial.println(tempsy);
  Serial.print("Valeur : ");
  Serial.println(valeur);
  
 
}

void loop() {
 
}

// Fonction qui enlèvent ce qui nous intéresse pas dans la requête
String recupVal(String str){
  int index1 = lu.indexOf("values");
  int index2 = lu.indexOf("]]}]}]}");
  return str.substring(index1+9,index2);
}
//Fonction qui permet de garder ce qu'il y a après la virgule
String supDebVirg(String str){
  int iVir = str.indexOf(",");
  return str.substring(iVir+1);
}
//Fonction qui permet de garder ce qu'il y a avant la virgule
String supFinVirg(String str){
  int iVir = str.indexOf(",");
  return str.substring(0,iVir);
}

