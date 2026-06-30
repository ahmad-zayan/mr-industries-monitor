// DHT22 Temperature and Humidity — MR Industries Monitor
// Phase 3
// Wiring:
//   DHT22 VCC  → 3V
//   DHT22 GND  → G
//   DHT22 DATA → D5

#include "DHT.h"

#define DHTPIN D5
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  delay(2000);
  Serial.println("DHT22 ready");
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("ERROR — check D5 wire");
    delay(3000);
    return;
  }

  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print(" C   Humidity: ");
  Serial.print(h);
  Serial.print(" %   HeatIndex: ");
  Serial.print(dht.computeHeatIndex(t, h, false));
  Serial.println(" C");

  delay(3000);
}
