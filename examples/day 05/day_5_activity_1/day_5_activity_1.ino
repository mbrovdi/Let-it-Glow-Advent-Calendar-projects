Activity 3: DIP Switch Controls Bar Graph 

This code lights up a bar graph segment for each DIP switch that is ON 

const int dipPins[5] = {6, 5, 4, 3, 2};      // DIP switch pins
const int segments[5] = {13, 12, 11, 10, 9}; // Bar graph segment pins

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(dipPins[i], INPUT_PULLDOWN);
    pinMode(segments[i], OUTPUT);
    digitalWrite(segments[i], LOW); // Start with all segments off
  }
}

void loop() {
  for (int i = 0; i < 5; i++) {
    if (digitalRead(dipPins[i]) == HIGH) {
      digitalWrite(segments[i], HIGH); // Turn ON segment if switch is ON
    } else {