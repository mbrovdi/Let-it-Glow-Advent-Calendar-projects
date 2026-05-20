Activity 1: Segment Testing 

This code lights each segment in sequence, then turns all off. Use it to verify your wiring. 

const int segments[5] = {13, 12, 11, 10, 9};

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(segments[i], OUTPUT);
    digitalWrite(segments[i], LOW);
  }
}


void loop() {
  // Light each segment one by one
  for (int i = 0; i < 5; i++) {
    digitalWrite(segments[i], HIGH);
    delay(500);
    digitalWrite(segments[i], LOW);
    delay(200);
  }
  // Turn all segments off
  for (int i = 0; i < 5; i++) {
    digitalWrite(segments[i], LOW);
  }
  delay(1000);
}
