int outputpin = A0;  //initializes/defines the output pin of the LM35 temperature sensor
                    //this sets the ground pin to LOW and the input voltage pin to high

int lED = D7;
void setup()
{
  digitalWrite(lED, HIGH);

  
  
 
Serial.begin(9600);
}

void loop() //main loop
{
int analogValue = analogRead(outputpin);
float millivolts = (analogValue/1024.0) * 3300; //3300 is the voltage provided by NodeMCU
float celsius = millivolts/10;
Serial.print("in DegreeC=   ");
Serial.println(celsius);
  delay(1000);

if (celsius >= 30) {
  digitalWrite(lED, HIGH);
  Serial.println("D2, HIGH");
  // Danger! Shut down the system.
}
else if (celsius >= 25) { // 60 <= temperature < 70
  // Warning! User attention required.
}
else { // temperature < 60
  digitalWrite(lED, HIGH);
  Serial.println("D2, LOW");

  delay(1000);
  // Safe! Continue usual tasks.
}
}
