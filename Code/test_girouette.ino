void setup() {
Serial.begin(9600);
}
void loop() {
int sensorValue = analogRead(A1);

//angle 180, SUD
if (sensorValue >=280 && sensorValue <= 290) 
{
  Serial.print("angle : 180°; ");
  Serial.println("direction : SUD");
}

if (sensorValue >=88 && sensorValue <=98) 
{
  Serial.print("angle : 90°; ");
  Serial.println("direction : EST");
}

if (sensorValue >=784 && sensorValue <=794 ) 
{
  Serial.print("angle : 0°; ");
  Serial.println("direction : NORD");
}

if (sensorValue >=940 && sensorValue <=950 ) 
{
  Serial.print("angle : 270°; ");
  Serial.println("direction : OUEST");
}
if (sensorValue >=884 && sensorValue <=894 ) 
{
  Serial.print("angle : 315°; ");
  Serial.println("direction : NORD-OUEST");
}
if (sensorValue >=458 && sensorValue <=468 ) 
{
  Serial.print("angle : 45°; ");
  Serial.println("direction : NORD-EST");
}
if (sensorValue >=180 && sensorValue <=190 ) //
{
  Serial.print("angle : 135°; ");
  Serial.println("direction : SUD-EST");
}
if (sensorValue >=628 && sensorValue <=638 ) //
{
  Serial.print("angle : 225°; ");
  Serial.println("direction : SUD-OUEST");
}

delay(1000);
}
