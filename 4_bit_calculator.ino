#define LED_1_PIN 4
#define LED_2_PIN 5
#define LED_3_PIN 6
#define LED_4_PIN 7

void setup() {
  Serial.begin(115200);
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  pinMode(LED_4_PIN, OUTPUT);

  int LEDState = LOW;
  digitalWrite(LED_1_PIN, LEDState);
  digitalWrite(LED_2_PIN, LEDState);
  digitalWrite(LED_3_PIN, LEDState);
  digitalWrite(LED_4_PIN, LEDState);
}

void loop() {
  if (Serial.available() > 0) {
    int result = receiveInputOnSerialMonitorAndCalculate();
    uint8_t finalValue = twosComplement(result);
    
    if (finalValue <= 15) {
      displayLEDs(finalValue);
      Serial.println("Your Result is: " + (String)finalValue);
    }
    else {
      Serial.println("Invalid Input!");
    }
  }
}
int receiveInputOnSerialMonitorAndCalculate() {
  int num1 = Serial.parseInt();
  char sign = Serial.read();
  int num2 = Serial.parseInt();
  int answer = calculate(num1, sign, num2);
  return answer;
}

int calculate(int num1, char sign, int num2) {
  int answer = 0;
  if (sign == '+') {
    answer = num1 + num2;
  }
  else if (sign == '-') {
    answer = num1 - num2;
  }
  else {
    Serial.println("Invalid Sign!");
  }
  return answer;
}
void displayLEDs(uint8_t answer) {
  int mask = 0x01;
  digitalWrite(LED_1_PIN, answer & mask);
  digitalWrite(LED_2_PIN, answer >> 1 & mask);
  digitalWrite(LED_3_PIN, answer >> 2 & mask);
  digitalWrite(LED_4_PIN, answer >> 3 & mask);
  delay(1000);
}

uint8_t twosComplement(int input) {
  if (input >= 0) {
    return input;
  }
  uint8_t positive = abs(input);
  uint8_t inverted = ~positive;
  uint8_t answer = inverted + 1;
  return answer;
}
