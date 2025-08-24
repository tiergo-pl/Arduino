/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// the setup function runs once when you press reset or power the board

#define PD12 12
#define Red 2
#define Blue 3
#define Green 4
#define Red_ 5

int varTime;

void clearLeds()
{
  digitalWrite(Red,LOW);
  digitalWrite(Blue,LOW);
  digitalWrite(Green,LOW);
  digitalWrite(Red_,LOW);
  digitalWrite(PD12,LOW);
}

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PD12, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Blue, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Red_, OUTPUT);
  Serial.begin(9600);
  
}

// the loop function runs over and over again forever
void loop() {
  varTime = analogRead(A0);
  Serial.println(varTime);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  clearLeds();
  digitalWrite(Red, HIGH);   // 
  delay(varTime);
  clearLeds();
  digitalWrite(Blue, HIGH);   // 
  delay(varTime);
  clearLeds();
  digitalWrite(Green, HIGH);   // 
  delay(varTime);
  clearLeds();
  digitalWrite(Red_, HIGH);   // 
  delay(varTime);
  clearLeds();
  digitalWrite(PD12, HIGH);   // 
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(varTime);
}
