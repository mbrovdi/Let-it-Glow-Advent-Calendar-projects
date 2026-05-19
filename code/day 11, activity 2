Activity 2: LED Strand Colour Selector 

Use keypad to select color patterns for the RGB strand 
Define color variables ( green, white, blue, yellow)
On key press, call a function to fill even/odd LEDs with selected colours

Code:

 #include <Adafruit_NeoPixel.h>
#define STRAND_PIN 2
#define LED_COUNT  15
#define KEY1_PIN 11
#define KEY2_PIN 10
#define KEY3_PIN 13
#define KEY4_PIN 12

Adafruit_NeoPixel strand(LED_COUNT, STRAND_PIN, NEO_RGB + NEO_KHZ800);

uint32_t aqua  = strand.Color(0, 255, 255);
uint32_t green = strand.Color(0, 255, 0);
uint32_t white = strand.Color(255, 255, 255);
uint32_t blue  = strand.Color(0, 0, 255);
uint32_t yellow= strand.Color(255, 255, 0);
uint32_t pink  = strand.Color(255, 0, 255);
uint32_t off   = strand.Color(0, 0, 0);

void setup() {
  strand.begin();
  strand.show();
  pinMode(KEY1_PIN, INPUT_PULLDOWN);
  pinMode(KEY2_PIN, INPUT_PULLDOWN);
  pinMode(KEY3_PIN, INPUT_PULLDOWN);
  pinMode(KEY4_PIN, INPUT_PULLDOWN);
}

void blinky1(uint32_t color1, uint32_t color2) {
  for (int i = 0; i < LED_COUNT; i++) {
    if (i % 2 == 0) strand.setPixelColor(i, color1);
    else            strand.setPixelColor(i, color2);
  }
  strand.show();
}

void loop() {
  if (digitalRead(KEY1_PIN)) blinky1(aqua, green);
  else if (digitalRead(KEY2_PIN)) blinky1(white, blue);
  else if (digitalRead(KEY3_PIN)) blinky1(yellow, pink);
  else if (digitalRead(KEY4_PIN)) blinky1(off, off);
  delay(100);
}
