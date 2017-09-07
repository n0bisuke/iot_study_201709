#define DIGITAL_OUTPUT 2

void setup() {
  Serial.begin(115200);
  pinMode(DIGITAL_OUTPUT, OUTPUT);
}

void loop() {
  digitalWrite(DIGITAL_OUTPUT, LOW);
  delay(100);
}
