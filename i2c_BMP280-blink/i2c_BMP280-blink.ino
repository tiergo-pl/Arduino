#include <Wire.h>
#include "i2c.h"

#include "i2c_BMP280.h"

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
BMP280 bmp280;

void setup()
{
    Serial.begin(115200);

    Serial.print("Probe BMP280: ");
    if (bmp280.initialize()) Serial.println("Sensor found");
    else
    {
        Serial.println("Sensor missing");
        while (1) {}
    }

    // onetime-measure:
    bmp280.setEnabled(0);
    bmp280.triggerMeasurement();

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PD12, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Blue, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Red_, OUTPUT);

}

void loop()
{
    bmp280.awaitMeasurement();

    float temperature;
    bmp280.getTemperature(temperature);

    float pascal;
    bmp280.getPressure(pascal);

    static float meters, metersold;
    bmp280.getAltitude(meters);
    metersold = (metersold * 10 + meters)/11;

    bmp280.triggerMeasurement();

    Serial.print(" HeightPT1: ");
    Serial.print(metersold);
    Serial.print(" m; Height: ");
    Serial.print(meters);
    Serial.print(" Pressure: ");
    Serial.print(pascal);
    Serial.print(" Pa; T: ");
    Serial.print(temperature);
    Serial.println(" C");

    delay(500);
    
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

/**<

Program size:
A1.0.5:
A1.5.7: 9680b
A1.6.3: 9664b / 561b

 */
