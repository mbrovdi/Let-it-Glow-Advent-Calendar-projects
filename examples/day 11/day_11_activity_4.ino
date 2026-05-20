Activity 4: No Erroneus Input 

Prevent multiple detectors from a single long key press 

Use a state variable 
Only allow new input when all keys are released 

Code:

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

void loop() {
  delay(100);
  if (state == 0) {
    if (digitalRead(KEY1_PIN)) { Serial.println("Button 1"); state = 1; }
    else if (digitalRead(KEY2_PIN)) { Serial.println("Button 2"); state = 1; }
    else if (digitalRead(KEY3_PIN)) { Serial.println("Button 3"); state = 1; }
    else if (digitalRead(KEY4_PIN)) { Serial.println("Button 4"); state = 1; }
  } else if (state == 1 &&
             digitalRead(KEY1_PIN) == 0 &&
             digitalRead(KEY2_PIN) == 0 &&
             digitalRead(KEY3_PIN) == 0 &&
             digitalRead(KEY4_PIN) == 0) {
    state = 0;
  }
}
