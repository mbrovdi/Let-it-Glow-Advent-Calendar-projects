// Activity 4: No Erroneous Input
//
// Accept one key input per press, then wait until all keys are released.

#define KEY1_PIN 11
#define KEY2_PIN 10
#define KEY3_PIN 13
#define KEY4_PIN 12

int state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(KEY1_PIN, INPUT_PULLDOWN);
  pinMode(KEY2_PIN, INPUT_PULLDOWN);
  pinMode(KEY3_PIN, INPUT_PULLDOWN);
  pinMode(KEY4_PIN, INPUT_PULLDOWN);
}

bool anyKeyPressed() {
  return (digitalRead(KEY1_PIN) == HIGH ||
          digitalRead(KEY2_PIN) == HIGH ||
          digitalRead(KEY3_PIN) == HIGH ||
          digitalRead(KEY4_PIN) == HIGH);
}

void loop() {
  if (state == 0) {
    if (digitalRead(KEY1_PIN) == HIGH) {
      Serial.println("Key 1");
      state = 1;
    } else if (digitalRead(KEY2_PIN) == HIGH) {
      Serial.println("Key 2");
      state = 1;
    } else if (digitalRead(KEY3_PIN) == HIGH) {
      Serial.println("Key 3");
      state = 1;
    } else if (digitalRead(KEY4_PIN) == HIGH) {
      Serial.println("Key 4");
      state = 1;
    }
  } else {
    if (!anyKeyPressed()) {
      state = 0;
    }
  }

  delay(20);
}