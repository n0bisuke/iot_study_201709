#define LED_PIN 13
#define DELAY_TIME 1000

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(DELAY_TIME);
  digitalWrite(LED_PIN, LOW);
  delay(DELAY_TIME);
}
