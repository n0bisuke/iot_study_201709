#include <Wire.h>
#include <Digital_Light_TSL2561.h>

void setup()
{
  Wire.begin();
  Serial.begin(115200);
  TSL2561.init();
}

void loop()
{
  Serial.print("The Light value is: ");
  Serial.println(TSL2561.readVisibleLux());
  delay(1000);
}
