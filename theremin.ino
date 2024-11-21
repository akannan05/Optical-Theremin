void setup() {
  // initialize serial communication at 9600 bits per second:
  //pinMode(A0, INPUT); //photo
  //pinMode(A1, INPUT); //photo
  pinMode(A3, INPUT); //resistor

  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0 and pin 1:
  //int sensorValue1 = analogRead(A0);
  //int sensorValue2 = analogRead(A1);
  int resistor = analogRead(A3);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  //float voltage1 = sensorValue1 * (5.0 / 1023.0);
  //float voltage2 = sensorValue2 * (5.0 / 1023.0);
  float voltageR = resistor * (5.0/1023.0);
  // print out the value you read:
  //Serial.println(voltage1);
  //Serial.println(voltage2);
 

  // calculate voltage across each photoresistor

  float voltage_resistor = 5 - voltageR;
  float voltage_photo1 = voltageR;
  //float voltage_photo1 = voltageR - voltage1;
  //float voltage_photo2 = voltage1 - voltage2;
  //float voltage_photo3 = voltage2;

  float current = voltage_resistor/1000;

  float intensity1 = 1/(voltage_photo1/current);
  //float intensity2 = 1/(voltage_photo2/current);
  //float intensity3 = 1/(voltage_photo3/current);

  Serial.print("VR: ");
  Serial.print(voltage_resistor, 6);
  Serial.print("      ");
  Serial.print("V1: ");
  Serial.print(voltage_photo1,4);
  Serial.print("      ");
//  Serial.print("V2: ");
//  Serial.print(voltage_photo2,4);
//  Serial.print("      ");
//  Serial.print("V3: ");
//  Serial.print(voltage_photo3,4);
//  Serial.print("      ");
  Serial.print("Current: ");
  Serial.print(current,4);
  Serial.print("       ");
  Serial.print("intensity1: ");
  Serial.print(intensity1,4);
  Serial.print("        ");
//  Serial.print("intensity2: ");
//  Serial.print(intensity2,4);
//  Serial.print("        ");
//  Serial.print("intensity3: ");
//  Serial.print(intensity3,4);
  Serial.println();

  // map voltage to a sound frequency
//  float frequencyRed = map(intensity, 0, 5, 200, 600);
//  float frequencyBlue = map(intensity, 0, 5, 600, 1000);
//  float frequencyGreen = map(intensity, 0, 5, 1000, 1400);

  // play three notes in succession corresponding to the frequency
  //tone(8, frequencyRed, 500);
  //tone(8, frequencyBlue, 500);
  //tone(8, frequencyGreen, 500);
  //delay(500);
 delay(2000);

}