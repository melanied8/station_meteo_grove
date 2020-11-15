unsigned long tempsDebut;  // passage précédent de l'aimant

int etatPrecedent;  // lors de du dernier passage dans le loop,
                    // l'aimant était là, ou pas? 

void setup() {
  pinMode(8, INPUT);   // interrupteur Reed à la pin 8
  pinMode(13,OUTPUT);  // LED indicatrice à la pin 13
  Serial.begin(9600);  // moniteur série
  etatPrecedent = digitalRead(8); // on vérifie si l'aimant est là ou pas
}

void loop() {

  int etat, delai;
  unsigned long tempsFin;

  etat = digitalRead(4);  // on vérifie si l'aimant est là ou pas
  
  digitalWrite(13,etat);

  if ((etat) && (!etatPrecedent)){ // l'aimant vient d'arriver
    if (tempsDebut > 0){  // nous connaissons le moment du début de ce tour
      tempsFin = millis();  // quelle heure est-il?
      delai = tempsFin - tempsDebut;  // durée du tour qui vient de se terminer
      Serial.print("Periode :" );
      Serial.print(delai);
      Serial.print("  millisecondes,  Vitesse :");    
      Serial.print(3.6*2*3.1416*0.15*1000/delai);
      // (cette vitesse ne tient pas compte de la fonction d'étalonnage)
      Serial.println(" km/h");        
    }
    
    tempsDebut = tempsFin;  // mise à jour de la variable
  }
  
  etatPrecedent = etat;  // mise à jour de la variable
}
