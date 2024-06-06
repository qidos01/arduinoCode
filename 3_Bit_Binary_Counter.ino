#define LSB_LED 4
#define MID_LED 3
#define MSB_LED 2
 int numberOfBits = 3;
 
 int bitnumber = 0x01;

void setup() {
 //for (int i = 0; i <= numberOfBits; i++)
pinMode(LSB_LED, OUTPUT);
pinMode(MID_LED, OUTPUT);
pinMode(MSB_LED, OUTPUT);
}

void loop() {
  for(int counter = 0; counter < 8; counter++){
      digitalWrite(LSB_LED, bitnumber & counter);
      digitalWrite(MID_LED, (bitnumber << 1)& counter );
      digitalWrite(MSB_LED, (bitnumber << 2)& counter);
      delay(1000);
      }
}
