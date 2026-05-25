// Activity 1: Test that each keypad is detected
//
// Print which key is currently pressed.

#define KEY1_PIN 11
#define KEY2_PIN 10
#define KEY3_PIN 13
#define KEY4_PIN 12

void setup() {
  Serial.begin(9600);
  pinMode(KEY1_PIN, INPUT_PULLDOWN);
  pinMode(KEY2_PIN, INPUT_PULLDOWN);
  pinMode(KEY3_PIN, INPUT_PULLDOWN);
  pinMode(KEY4_PIN, INPUT_PULLDOWN);
}

void loop() {
  if (digitalRead(KEY1_PIN) == HIGH) {
    Serial.println("Key 1 pressed");
  }
  if (digitalRead(KEY2_PIN) == HIGH) {
    Serial.println("Key 2 pressed");
  }
  if (digitalRead(KEY3_PIN) == HIGH) {
    Serial.println("Key 3 pressed");
  }
  if (digitalRead(KEY4_PIN) == HIGH) {
    Serial.println("Key 4 pressed");
  }

  delay(100);
}