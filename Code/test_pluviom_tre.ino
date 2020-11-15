#define pinILS 4
#define pi 3.14159265359
#define RayonDesBras    0.07 // en mètre de l'anénomètre
 
void setup()
{
  pinMode(pinILS, INPUT);
  Serial.begin(9600);
}
 
unsigned long millis_old(0);
float deltaTime(0);
float vitesseVent(0);
float NombreTourSec(0);
float FEtalonage(1);
/* NB : La fonction d'étalonnage traduit les propriétés aérodynamiques de
l'anémomètre et les frottements qui altèrent le mouvement de rotation de l'anémomètre.
Elle dépend des dimensions et matériaux de l'anémomètre et de sa vitesse de rotation.
Seuls des essais en soufflerie à différents régimes de vent permettent de la déterminer précisément. */
bool isActive(false);
 
void loop()
{
    UpdateILS();
    //convertion periode -> fréquense
    NombreTourSec = (1 / deltaTime);
    //vitesse du vent
 
    vitesseVent = 2*pi*RayonDesBras*NombreTourSec*FEtalonage;
    //affichage de la vitesse
    Serial.print("la vitesse du vent est de ");
    Serial.println(vitesseVent);
    Serial.print(" m/s.");
}
void UpdateILS()
{
    //lecture du capteur
    isActive = digitalRead(pinILS);
 
    if(isActive)
    {
        deltaTime = (millis() - millis_old) / 1000 ; // div en 1000 pour avoir le résultat en sec
        millis_old = millis(); // remise à 0 du compteur pour capturé la différence de temps au prochain tour
    }
}
