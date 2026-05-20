Activity 1: Test that each keypad is detected 

Set D11, D10, D13, D12 as INPUT_PULLDOWN
In loop, check each pin; print which button is pressed 

Code:

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
  if (digitalRead(KEY1_PIN)) Serial.println("Button 1");
  if (digitalRead(KEY2_PIN)) Serial.println("Button 2");
  if (digitalRead(KEY3_PIN)) Serial.println("Button 3");
  if (digitalRead(KEY4_PIN)) Serial.println("Button 4");
  delay(300);
}
