#define LED_PIN 13
#define DLAY_TIME 1000

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(DLAY_TIME);
  digitalWrite(LED_PIN, LOW);
  delay(DLAY_TIME);
}
