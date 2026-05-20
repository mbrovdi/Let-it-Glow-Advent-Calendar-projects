// Pin assignments
const int redButtonPin = 2;    // Right button
const int greenButtonPin = 3;  // Left button
const int ledPin = 14;         // LED


void setup() {
  pinMode(redButtonPin, INPUT_PULLDOWN);   // Use pulldown to match Pico code
  pinMode(greenButtonPin, INPUT_PULLDOWN);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  delay(200); // Debounce


  if (digitalRead(redButtonPin) == HIGH) {
    Serial.println("Light OFF");