#include <Wire.h>
#include <Digital_Light_TSL2561.h>
#define LED_PIN 13
#define THRESHOLD 100
#define DELAY_TIME 50

void setup()
{
  Wire.begin();
  Serial.begin(115200);
  TSL2561.init();
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  Serial.print("The Light value is: ");
  Serial.println(TSL2561.readVisibleLux());
  if(TSL2561.readVisibleLux() < THRESHOLD){
    digitalWrite(LED_PIN, HIGH);
    delay(DELAY_TIME);
    digitalWrite(LED_PIN, LOW);
    delay(DELAY_TIME);
  }else{
    digitalWrite(LED_PIN, LOW);
  }
  delay(DELAY_TIME);
}