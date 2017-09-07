#define WIO_DIGITAL 2
#define PIN_ADC A0
#define LED_PIN 13
#define THRESHOLD 200
#define SAMPLINGRATE 100

void setup() {
  Serial.begin(115200);
  pinMode(WIO_DIGITAL, OUTPUT);
}

void loop() {
   if (isSoundDetected()) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(WIO_DIGITAL, HIGH);
    Serial.println("反応あり");
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(WIO_DIGITAL, LOW);
    //Serial.println("反応なし");
  }
  delay(100);
}

bool isSoundDetected(){
  static unsigned int sum = 0; // 積算用変数
  unsigned int avg = sum; // 前回の積算値をコピー
  sum = 0;
  bool detected = false;
  // SAMPLINGRATE回数だけサンプルをとって平均値を出す
  for(int i=0; i<SAMPLINGRATE; i++) {
    int a = analogRead(PIN_ADC);
    sum += a;
    
    // 前回の平均値よりTHRESHOLD以上大きい値がとれたらdetected
    if (a >= ((avg/SAMPLINGRATE)+THRESHOLD)) detected = true;
  }

  Serial.println(sum/SAMPLINGRATE); // デバッグ用シリアル出力
  return detected;
}