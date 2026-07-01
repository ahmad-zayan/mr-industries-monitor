// SW-420 Vibration Sensor 
// MR Industries Monitor — Phase 5
//   0 = still / no vibration
//   1 = vibration detected
// Wiring: VCC→3V, GND→G, DO→D6

#define VIBPIN D6

unsigned long lastTriggerTime = 0;
const unsigned long latchDuration = 1000; // show VIBRATION for 1 second after trigger

void setup() {
  Serial.begin(9600);
  pinMode(VIBPIN, INPUT_PULLUP);
  Serial.println("SW-420 Vibration Monitor — MR Industries");
  Serial.println("Potentiometer: turn to halfway between full CW and full CCW");
  delay(1000);
}

void loop() {
  int state = digitalRead(VIBPIN);

  // YOUR board: 1 = vibration, 0 = still
  if (state == 1) {
    lastTriggerTime = millis(); // record when vibration last happened
  }

  // Show VIBRATION for 1 full second after last trigger
  // This catches brief pulses the eye would miss
  if (millis() - lastTriggerTime < latchDuration) {
    Serial.println("VIBRATION DETECTED");
  } else {
    Serial.println("Still...");
  }

  delay(20); // poll 50 times per second — catches brief triggers
}
