const int OUTPUT_FIRST_PIN = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(450000);

  for (int pin = OUTPUT_FIRST_PIN; pin < OUTPUT_FIRST_PIN + 8; pin++) {
    pinMode(pin, OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  int value = Serial.read();
  if (value >= 0) {
    byte valueByte = value;
    PORTB = valueByte >> 2;
    digitalWrite(6, valueByte & 0x1);
    digitalWrite(6, (valueByte >> 1) & 0x1);
  }
}
