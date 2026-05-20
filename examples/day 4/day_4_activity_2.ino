Activity 2: Button-Controlled Bar Graph 

This code uses two buttons to increment or decrement the number of lit segments 

const int redButtonPin = 2;
const int greenButtonPin = 3;
const int segments[5] = {13, 12, 11, 10, 9};
int count = -1;


void setup() {
  pinMode(redButtonPin, INPUT_PULLDOWN);
  pinMode(greenButtonPin, INPUT_PULLDOWN);
  for (int i = 0; i < 5; i++) {
    pinMode(segments[i], OUTPUT);
    digitalWrite(segments[i], LOW);
  }
}


void loop() {
  delay(10); // Debounce


  // Light up next segment
  if (digitalRead(redButtonPin) == HIGH) {
    if (count < 4) {
      count++;
      digitalWrite(segments[count], HIGH);
      delay(200); // Prevent multiple counts per press
    }
  }


  // Turn off last lit segment
  if (digitalRead(greenButtonPin) == HIGH) {
    if (count >= 0) {
      digitalWrite(segments[count], LOW);
      delay(200); // Prevent multiple counts per press
      count--;
    }
  }
}
