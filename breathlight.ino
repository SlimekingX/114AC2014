// 定義 PWM 控制引腳
const int redPin = 4;
const int greenPin = 5;
const int bluePin = 6;

// 定義可變電阻輸入引腳
const int potPin = A0;

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  // A0 預設即為輸入模式，不需特別設定 pinMode
}

void loop() {
  breathColor(255, 0, 0);     // 紅色
  breathColor(0, 255, 0);     // 綠色
  breathColor(0, 0, 255);     // 藍色
  breathColor(128, 0, 128);   // 紫色
  breathColor(0, 128, 128);   // 青色
}

void breathColor(int maxR, int maxG, int maxB) {
  // 漸亮過程
  for (int i = 0; i <= 255; i++) {
    // 讀取可變電阻數值 (0 ~ 1023)
    int potValue = analogRead(potPin);
    
    // 將 0~1023 映射為延遲時間 2ms ~ 30ms (可依需求自行調整最小值與最大值)
    int speedDelay = map(potValue, 0, 1023, 2, 30);

    int r = (maxR * i) / 255;
    int g = (maxG * i) / 255;
    int b = (maxB * i) / 255;
    setColor(r, g, b);
    
    delay(speedDelay); // 動態延遲時間
  }

  // 漸暗過程
  for (int i = 255; i >= 0; i--) {
    int potValue = analogRead(potPin);
    int speedDelay = map(potValue, 0, 1023, 1, 30);

    int r = (maxR * i) / 255;
    int g = (maxG * i) / 255;
    int b = (maxB * i) / 255;
    setColor(r, g, b);
    
    delay(speedDelay);
  }
  
  delay(100);
}