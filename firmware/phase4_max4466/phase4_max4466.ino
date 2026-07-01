// MAX4466 Noise Sensor — MR Industries Monitor
// Phase 4
// Wiring:
//   MAX4466 VCC → 3V
//   MAX4466 GND → G
//   MAX4466 OUT → A0
//

#define ANALOGPIN A0

void setup() {
  Serial.begin(9600);
  Serial.println("MAX4466 ready");
  Serial.println("Quiet room first — then clap to test");
  delay(2000);
}

void loop() {
  int maxVal = 0;
  int minVal = 1023;

  // Take 50 samples over 0.5 seconds
  for (int i = 0; i < 50; i++) {
    int s = analogRead(ANALOGPIN);
    if (s > maxVal) maxVal = s;
    if (s < minVal) minVal = s;
    delay(10);
  }

  int peakToPeak = maxVal - minVal;

  Serial.print("Min: ");
  Serial.print(minVal);
  Serial.print("   Max: ");
  Serial.print(maxVal);
  Serial.print("   Peak-to-Peak: ");
  Serial.println(peakToPeak);
  // Peak-to-peak is your noise level number
  // Quiet: 20-80
  // Talking: 100-300
  // Clap: 400-700
  // Machine: 300-600

  delay(1000);
}
