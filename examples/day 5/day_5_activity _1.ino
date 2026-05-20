Activity 1: DIP Switch State Test 

This code prints the ON/OFF state of each DIP switch every 5 seconds to the Serial Monitor 
const int dipPins[5] = {6, 5, 4, 3, 2};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 5; i++) {
    pinMode(dipPins[i], INPUT_PULLDOWN);
  }
}

void loop() {
  for (int i = 0; i < 5; i++) {
    if (digitalRead(dipPins[i]) == HIGH) {
      Serial.print("Switch ");
      Serial.print(i + 1);
      Serial.println(": ON");
    } else {
      Serial.print("Switch ");
      Serial.print(i + 1);
      Serial.println(": OFF");
    }
  }
  Serial.println("-------------");
  delay(5000);
}

