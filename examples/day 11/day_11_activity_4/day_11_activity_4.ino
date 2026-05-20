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