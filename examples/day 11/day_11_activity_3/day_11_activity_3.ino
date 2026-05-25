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