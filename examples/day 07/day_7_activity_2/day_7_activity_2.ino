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