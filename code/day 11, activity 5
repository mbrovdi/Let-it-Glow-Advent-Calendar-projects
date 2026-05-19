Activity 5: Secret Present List (Passcode System)

Required a 4-digit passcode using the keypad. If correct, light the block LED and print a secret list 

Store passcode as a list ([1,2,3,4])
Collect user input into a list 
If input matches passcode, light LED and print presents 
If not, print “Access denied”

Code: 

#define KEY1_PIN 11
#define KEY2_PIN 10
#define KEY3_PIN 13
#define KEY4_PIN 12
#define BLOCK_LED_PIN 6

int passcode[4] = {1, 2, 3, 4};
int userentry[4];
int entryIndex = 0;
int state = 0;
int key = 0;

void setup() {
  Serial.begin(9600);
  pinMode(KEY1_PIN, INPUT_PULLDOWN);
  pinMode(KEY2_PIN, INPUT_PULLDOWN);
  pinMode(KEY3_PIN, INPUT_PULLDOWN);
  pinMode(KEY4_PIN, INPUT_PULLDOWN);
  pinMode(BLOCK_LED_PIN, OUTPUT);
  Serial.println("Welcome to the Secret Present List system");
  delay(1000);
  Serial.print("Enter the passcode to continue: ");
}

void loop() {
  if (entryIndex < 4) {
    delay(100);
    if (state == 0) {
      if (digitalRead(KEY1_PIN)) { key = 1; appendKey(); }
      else if (digitalRead(KEY2_PIN)) { key = 2; appendKey(); }
      else if (digitalRead(KEY3_PIN)) { key = 3; appendKey(); }
      else if (digitalRead(KEY4_PIN)) { key = 4; appendKey(); }
    } else if (state == 1 &&
               digitalRead(KEY1_PIN) == 0 &&
               digitalRead(KEY2_PIN) == 0 &&
               digitalRead(KEY3_PIN) == 0 &&
               digitalRead(KEY4_PIN) == 0) {
      state = 0;
    }
  } else {
    // Check passcode
    bool correct = true;
    for (int i = 0; i < 4; i++) {
      if (userentry[i] != passcode[i]) correct = false;
    }
    if (correct) {
      digitalWrite(BLOCK_LED_PIN, HIGH);
      Serial.println("\n----------------------");
      Serial.println("*** ACCESS GRANTED ***");
      Serial.println("----------------------");
      Serial.println("Secret present list:");
      Serial.println("Train set");
      Serial.println("Furby");
      Serial.println("Boomerang");
      Serial.println("YoYo");
      Serial.println("----------------------");
      digitalWrite(BLOCK_LED_PIN, LOW);
    } else {
      Serial.println("\n------------------");
      Serial.println("INCORRECT PASSCODE");
      Serial.println("ACCESS DENIED");
    }
    while (1); // Stop program
  }
}

void appendKey() {
  userentry[entryIndex++] = key;
  Serial.print("*");
  state = 1;
}

