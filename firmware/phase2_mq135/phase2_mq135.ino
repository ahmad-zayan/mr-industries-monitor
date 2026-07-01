// MQ135 Air Quality — MR Industries Monitor
// Phase 2
// Wiring:
//   MQ135 VCC → VU 
//   MQ135 GND → G
//   MQ135 AO  → A0
//   MQ135 DO  → not connected

#include "MQ135.h"

#define ANALOGPIN A0
#define MY_RZERO 194.4

MQ135 gasSensor(ANALOGPIN);

void setup() {
  Serial.begin(9600);
  Serial.println("MQ135 ready — warming up 60 seconds");

  for (int i = 60; i > 0; i--) {
    Serial.print("Warmup: ");
    Serial.print(i);
    Serial.println("s");
    delay(1000);
  }

  Serial.println("Reading started");
}

void loop() {
  int raw     = analogRead(ANALOGPIN);
  float ppm   = gasSensor.getPPM();
  float rzero = gasSensor.getRZero();

  Serial.print("Raw: ");
  Serial.print(raw);
  Serial.print("   PPM: ");
  Serial.print(ppm);
  Serial.print("   RZero: ");
  Serial.println(rzero);

  delay(5000);
}
