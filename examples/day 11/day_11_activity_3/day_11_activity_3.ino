// Activity 3: Push to Flash (Block LED)
//
// Use keypad input to control block LED flash speed.

#define KEY1_PIN 11
#define KEY2_PIN 10
#define KEY3_PIN 13
#define KEY4_PIN 12
#define BLOCK_LED_PIN 6

void setup() {
  pinMode(KEY1_PIN, INPUT_PULLDOWN);
  pinMode(KEY2_PIN, INPUT_PULLDOWN);
  pinMode(KEY3_PIN, INPUT_PULLDOWN);
  pinMode(KEY4_PIN, INPUT_PULLDOWN);
  pinMode(BLOCK_LED_PIN, OUTPUT);
  digitalWrite(BLOCK_LED_PIN, LOW);
}

void loop() {
  int flashDelay = 500;

  if (digitalRead(KEY1_PIN) == HIGH) {
    flashDelay = 120;
  } else if (digitalRead(KEY2_PIN) == HIGH) {
    flashDelay = 250;
  } else if (digitalRead(KEY3_PIN) == HIGH) {
    flashDelay = 500;
  } else if (digitalRead(KEY4_PIN) == HIGH) {
    flashDelay = 1000;
  }

  digitalWrite(BLOCK_LED_PIN, HIGH);
  delay(flashDelay);
  digitalWrite(BLOCK_LED_PIN, LOW);
  delay(flashDelay);
}