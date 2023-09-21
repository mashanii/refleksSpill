#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN       11
//#define RED       14
//#define GREEN     15
//#define BLUE      16
#define NUMPIXELS 32

int RED = 14;
int GREEN = 15;
int BLUE = 16;

float GREENlight;
float REDlight;
float BLUElight;


Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 5

void setup() {
  Serial.begin(9600);
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  pixels.begin();
}

void loop() {
  Serial.println(GREENlight);
  //pixels.clear();

int randRed = random(0,255);
int randGreen = random(0,255);
int randBlue = random(0,255);

int re = 255;
int gr = 0;
int bl = 0;


  /*for(int i=0; i<NUMPIXELS; i++) {

    GREENlight = 255*(float(analogRead(GREEN))/1023);
    REDlight = 255*(float(analogRead(RED))/1023);
    BLUElight = 255*(float(analogRead(BLUE))/1023);


    pixels.setPixelColor(i, pixels.Color(REDlight, GREENlight, BLUElight));
    Serial.println(GREENlight);
    pixels.show();
    delay(DELAYVAL);

    
  }*/

}
