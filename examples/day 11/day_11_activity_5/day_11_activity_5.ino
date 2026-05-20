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