// Phase 1 — NodeMCU Blink Test
// MR Industries Monitor
// Purpose: Confirm NodeMCU ESP8266 ESP-12E is working correctly
// Result: Built-in LED blinks every 1 second, Serial Monitor prints LED status
// Date completed: 2026-06-24
// Board: NodeMCU ESP8266 ESP-12E (CH340)

void setup() {
  pinMode(D4, OUTPUT);
  Serial.begin(9600);
  Serial.println("MR Industries Monitor — NodeMCU confirmed working");
}

void loop() {
  digitalWrite(D4, LOW);
  Serial.println("LED ON");
  delay(1000);
  digitalWrite(D4, HIGH);
  Serial.println("LED OFF");
  delay(1000);
}
