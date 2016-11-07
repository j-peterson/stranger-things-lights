#include <FastLED.h>
#define NUM_LEDS 50
#define DATA_PIN_1 5
#define DATA_PIN_2 6
#define BRIGHT_DEFAULT 63
#define ALPHA_OFFSET 5

int _Z = ALPHA_OFFSET + 0;
int _Y = ALPHA_OFFSET + 1;
int _X = ALPHA_OFFSET + 2;
int _W = ALPHA_OFFSET + 3;
int _V = ALPHA_OFFSET + 4;
int _U = ALPHA_OFFSET + 5;
int _T = ALPHA_OFFSET + 6;
int _S = ALPHA_OFFSET + 7;
int _R = ALPHA_OFFSET + 8;

int _Q = ALPHA_OFFSET + 17;
int _P = ALPHA_OFFSET + 16;
int _O = ALPHA_OFFSET + 15;
int _N = ALPHA_OFFSET + 14;
int _M = ALPHA_OFFSET + 13;
int _L = ALPHA_OFFSET + 12;
int _K = ALPHA_OFFSET + 11;
int _J = ALPHA_OFFSET + 10;
int _I = ALPHA_OFFSET + 9;

int _H = ALPHA_OFFSET + 18;
int _G = ALPHA_OFFSET + 19;
int _F = ALPHA_OFFSET + 20;
int _E = ALPHA_OFFSET + 21;
int _D = ALPHA_OFFSET + 22;
int _C = ALPHA_OFFSET + 23;
int _B = ALPHA_OFFSET + 24;
int _A = ALPHA_OFFSET + 25;

CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];

CRGB::HTMLColorCode colors[] = {
  CRGB::Red, CRGB::Green, CRGB::Blue,
  CRGB::Cyan, CRGB::Yellow, CRGB::Magenta,
  CRGB::Orange, CRGB::Purple, CRGB::White
};
int n = sizeof(colors) / sizeof(colors[0]);


void setup() {
  FastLED.addLeds<WS2811, DATA_PIN_1>(leds1, NUM_LEDS);
  FastLED.addLeds<WS2811, DATA_PIN_2>(leds2, NUM_LEDS);
  FastLED.setBrightness(BRIGHT_DEFAULT);

  randomSeed(analogRead(0));
}

void loop() {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds1[i] = CRGB::Red;
    leds2[i] = CRGB::Red;
    FastLED.show();
    delay(100);
  }

  FadeOut();
  delay(3000);

  SetAllColorful();
  FadeIn();
  delay(5000);

  FlickerTime(150); delay(3000);
  FlickerTime(100); delay(200);
  Flicker(2); delay(2000);

  FadeOut(); delay(10000);

  RightHere();
  delay(4000);
  Run();

  // demogorgon
  SetAllColorful();
  FastLED.show();
  delay(500);
  Flicker(8);
  Surge();
  Flicker(3);
  delay(250);
  Flicker(2);
  Surge();
  Flicker(15);
  Surge();
  Flicker(3); delay(2500);
  FadeOut();


  SetAllSolid(CRGB::Red);
  FadeIn();
  FadeOut();

  SetAllSolid(CRGB::Red);
  FadeIn(); delay(1000);
  FadeOut(); delay(5000);

  Cascade(); delay(5000);
  Cascade(); delay(5000);
  Cascade(); delay(5000);

  delay(10000);
  
  SetAllSolid(CRGB::Red);
  FadeIn(); delay(1000);
  FadeOut(); delay(2000);

  delay(10000);
  JusticeForBarb();
  delay(10000);
}


void FlickerTime(int t) {
  FastLED.setBrightness(0);
  FastLED.show();
  delay(t);
  FastLED.setBrightness(BRIGHT_DEFAULT);
  FastLED.show();
  delay(25);
}

void Flicker(int count) {
  for (int i = 0; i < count; ++i) {
    FastLED.setBrightness(0);
    FastLED.show();
    delay(random(10, 50));
    FastLED.setBrightness(BRIGHT_DEFAULT);
    FastLED.show();
    delay(random(10, 200));
  }
}

void Surge() {
  int highWaterMark = 128;
  for(int i = BRIGHT_DEFAULT; i < highWaterMark + 1; i++) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(2);
  }
  for(int i = highWaterMark; i >= BRIGHT_DEFAULT; i--) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(5);
  }
}

void FadeIn() {
  for(int i = 0; i < BRIGHT_DEFAULT + 1; i++) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(25);
  }
}

void FadeOut() {
  for(int i = BRIGHT_DEFAULT; i > 0; i--) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(50);
  }

  SetAllBlack();
  FastLED.setBrightness(BRIGHT_DEFAULT);
}

void Cascade() {
  for (int i = NUM_LEDS - 1; i > 26; i--) {
    leds2[i] = colors[random(n)];
    FastLED.show();
    leds2[i] = CRGB::Black;
    delay(500);
  }
  for (int i = 35; i < NUM_LEDS; i++) {
    leds1[i] = colors[random(n)];
    FastLED.show();
    leds1[i] = CRGB::Black;
    delay(500);
  }
  delay(1000);
  FastLED.show();
}

void SetAllBlack() {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds1[i] = CRGB::Black;
    leds2[i] = CRGB::Black;
  }
  FastLED.show();
  delay(10);
}

void SetAllSolid(CRGB::HTMLColorCode color) {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds1[i] = color;
    leds2[i] = color;
  }
}

void SetAllColorful() {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds1[i] = colors[random(n)];
    leds2[i] = colors[random(n)];
  }
}

void RightHere() {
  SetAllBlack();

  ShowLetter(_R, CRGB::Cyan);
  ShowLetter(_I, CRGB::Green);
  ShowLetter(_G, CRGB::Red);
  ShowLetter(_H, CRGB::Green);
  ShowLetter(_T, CRGB::Yellow);

  ShowLetter(_H, CRGB::Green);
  ShowLetter(_E, CRGB::Blue);
  ShowLetter(_R, CRGB::Cyan);
  ShowLetter(_E, CRGB::Blue);
}

void Run() {
  SetAllBlack();

  ShowLetter(_R, CRGB::Cyan);
  ShowLetter(_U, CRGB::Blue);
  ShowLetter(_N, CRGB::Red);
}

void JusticeForBarb() {
  SetAllBlack();

  ShowLetter(_J, CRGB::Magenta);
  ShowLetter(_U, CRGB::Blue);
  ShowLetter(_S, CRGB::White);
  ShowLetter(_T, CRGB::Yellow);
  ShowLetter(_I, CRGB::Green);
  ShowLetter(_C, CRGB::Magenta);
  ShowLetter(_E, CRGB::Blue);

  ShowLetter(_F, CRGB::Yellow);
  ShowLetter(_O, CRGB::Purple);
  ShowLetter(_R, CRGB::Cyan);

  ShowLetter(_B, CRGB::Blue);
  ShowLetter(_A, CRGB::White);
  ShowLetter(_R, CRGB::Cyan);
  ShowLetter(_B, CRGB::White);
}

void ShowLetter(int letter, CRGB::HTMLColorCode color) {
  leds1[letter] = color;
  FastLED.show();
  delay(random(500, 1500));
  leds1[letter] = CRGB::Black;
  FastLED.show();
  delay(random(250, 750));
}
