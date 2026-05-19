Activity 3: Push to Flash (Block LED) 

Use keypad to set flash speed for the block LED 

On key press, set a flash variable to a different delay 
While key is held, blink the block LED at the selected speed 

Code: 

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
}

void program1(float flash) {
  digitalWrite(BLOCK_LED_PIN, HIGH);
  delay(flash * 1000);
  digitalWrite(BLOCK_LED_PIN, LOW);
  delay(flash * 1000);
}

void loop() {
  while (digitalRead(KEY1_PIN)) program1(1.0);
  while (digitalRead(KEY2_PIN)) program1(0.5);
  while (digitalRead(KEY3_PIN)) program1(0.1);
  while (digitalRead(KEY4_PIN)) program1(0.05);
}
