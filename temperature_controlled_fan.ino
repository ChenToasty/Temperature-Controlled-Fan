#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11
#define MOTORPIN 9

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(MOTORPIN, OUTPUT);
}

void loop() {
  float temp = dht.readTemperature();

  if (isnan(temp)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  int fanSpeed = map(temp, 23, 26, 0, 255);
  fanSpeed = constrain(fanSpeed, 0, 255);

  analogWrite(MOTORPIN, fanSpeed);

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" C, Fan Speed: ");
  Serial.println(fanSpeed);

  delay(2000);
}
