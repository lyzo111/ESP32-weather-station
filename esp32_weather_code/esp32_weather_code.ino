#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#define NORMDRUCK 1013
Adafruit_BME280 bme; // legt ein Objekt für die I2C-Kommunikation an
void setup() {
Serial.begin(115200);
bool communication = bme.begin(0x76); //Initialisierung I2C-Kommunikation
if (!communication) {
  Serial.println("Kein BME280-Sensor gefunden!");
  Serial.println("Verdrahtung, Adresse, Sensor-ID prüfen!");
  Serial.print("SensorID: 0x");
  Serial.println(bme.sensorID(), 16);
  Serial.println("ID 0xFF bedeutet i.d.R. eine falsche Sensor-Adresse\n");
  while (true) { };
  delay(10);
} else {
  Serial.println("I2C-Kommunikation zum BME280 aufgebaut!\n");
  }
}

void loop() {
  Serial.print("Temperatur = ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");
  Serial.print("Luftdruck = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");
  Serial.print("Luftfeuchtigkeit = ");
  Serial.print(bme.readHumidity());
  Serial.println(" % ");
  Serial.print("Höhe über NN = ");
  Serial.print(bme.readAltitude(NORMDRUCK));
  Serial.println(" m\n");
  delay(1000);
}