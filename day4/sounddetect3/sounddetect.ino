#define WIO_DIGITAL 2
#define PIN_ADC A0
#define LED_PIN 13
#define THRESHOLD 500 //閾値

void setup() {
  Serial.begin(115200);
  pinMode(WIO_DIGITAL, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  if(isSoundDetected()){//if it detects the moving people?
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(WIO_DIGITAL, HIGH);
    Serial.println("反応あり");
  }else{
    digitalWrite(LED_PIN, LOW);
    digitalWrite(WIO_DIGITAL, LOW);
    Serial.println("反応なし");
  }

  Serial.println(cal());
  delay(100);
}

boolean isSoundDetected(){
  if(cal() >= THRESHOLD){//閾値よりも高いかどうか
    return true;//yes,return true
  }else{
    return false;//no,return false
  }
}

int cal(){
    long sum = 0;
    
    for(int i=0; i<32; i++){
      sum += analogRead(PIN_ADC);
    }
    sum >>= 5;

    return sum;
}
