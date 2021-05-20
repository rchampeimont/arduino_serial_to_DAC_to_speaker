// Uses pins OUTPUT_FIRST_PIN to OUTPUT_FIRST_PIN + 7.
// OUTPUT_FIRST_PIN is the least significant bit
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
    PORTB = valueByte >> 2; // sets pins 8 to 13 to the 6 most significant bits

    // with digitalWrite, least significant bit would change 7 to 8 microseconds after PORTB
    //digitalWrite(7, (valueByte >> 1) & 0x1);
    //digitalWrite(6, valueByte & 0x1);

    // with this optimized version, least significant bit changes 0.4 to 0.7 microsecond after PORTB
    byte shiftedByte = valueByte << 6;
    PORTD |= shiftedByte & B11000000; // set pins 6 and 7 to 1 if needed
    PORTD &= shiftedByte | B00111111; // set pins 6 and 7 to 0 if needed
  }
}
