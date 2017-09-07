#define WIO_DIGITAL 2
#define PIN_ADC A0
#define THRESHOLD 500 //閾値

int val = 0;

void setup() {
  Serial.begin(115200);
  pinMode(WIO_DIGITAL, OUTPUT);
}

void loop() {
  val = cal();
  if(val >= THRESHOLD){
    digitalWrite(WIO_DIGITAL, HIGH);
    Serial.print("反応あり:");
  }else{
    digitalWrite(WIO_DIGITAL, LOW);
    Serial.print("反応なし:");
  }
  Serial.println(val);

  delay(10);
}

int cal(){
    long sum = 0;
    
    for(int i=0; i<32; i++){
      sum += analogRead(PIN_ADC);
    }
    sum >>= 5;

    return sum;
}
