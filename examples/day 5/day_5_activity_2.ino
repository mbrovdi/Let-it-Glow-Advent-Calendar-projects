Activity 2. DIP Switch Pin Value Debug 

This code prints the raw digital value (0 or 1) of each DIP switch pin every seconds 

const int dipPins[5] = {6, 5, 4, 3, 2};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 5; i++) {
    pinMode(dipPins[i], INPUT_PULLDOWN);
  }
}

void loop() {
  for (int i = 0; i < 5; i++) {
    Serial.print("Pin D");
    Serial.print(dipPins[i]);
    Serial.print(": ");
    Serial.println(digitalRead(dipPins[i]));
  }
  Serial.println("-----");
  delay(1000);
}
