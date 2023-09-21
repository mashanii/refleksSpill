#include <Arduino.h>
#line 1 "C:\\Users\\maria\\OneDrive\\NTNU\\1sem\\IELS\\ledliste\\refleksSpill\\ledliste\\Spill\\Spill.ino"
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN       11
#define NUMPIXELS 32

int player1 = 2;
int player1points = 0;
int player2 = 4;
int player2points = 0;

bool player1PickColour = false;
bool player2PickColour = false;

int player1red;
int player1green;
int player1blue;
int player2red;
int player2green;
int player2blue;

bool gameEnd = true;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 400

#line 28 "C:\\Users\\maria\\OneDrive\\NTNU\\1sem\\IELS\\ledliste\\refleksSpill\\ledliste\\Spill\\Spill.ino"
void setup();
#line 37 "C:\\Users\\maria\\OneDrive\\NTNU\\1sem\\IELS\\ledliste\\refleksSpill\\ledliste\\Spill\\Spill.ino"
void loop();
#line 47 "C:\\Users\\maria\\OneDrive\\NTNU\\1sem\\IELS\\ledliste\\refleksSpill\\ledliste\\Spill\\Spill.ino"
void startGame();
#line 135 "C:\\Users\\maria\\OneDrive\\NTNU\\1sem\\IELS\\ledliste\\refleksSpill\\ledliste\\Spill\\Spill.ino"
void gameRound();
#line 170 "C:\\Users\\maria\\OneDrive\\NTNU\\1sem\\IELS\\ledliste\\refleksSpill\\ledliste\\Spill\\Spill.ino"
void player1fastest();
#line 186 "C:\\Users\\maria\\OneDrive\\NTNU\\1sem\\IELS\\ledliste\\refleksSpill\\ledliste\\Spill\\Spill.ino"
void player2fastest();
#line 205 "C:\\Users\\maria\\OneDrive\\NTNU\\1sem\\IELS\\ledliste\\refleksSpill\\ledliste\\Spill\\Spill.ino"
void player2win();
#line 229 "C:\\Users\\maria\\OneDrive\\NTNU\\1sem\\IELS\\ledliste\\refleksSpill\\ledliste\\Spill\\Spill.ino"
void player1win();
#line 28 "C:\\Users\\maria\\OneDrive\\NTNU\\1sem\\IELS\\ledliste\\refleksSpill\\ledliste\\Spill\\Spill.ino"
void setup() {
  Serial.begin(9600);
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  pixels.begin();
}

void loop() {

if (gameEnd == true){
  startGame();
}

gameRound();

}

void startGame(){

gameEnd = false;

Serial.println(" Velkommen til Be Fast! "
"Dette spillet er førstemann til 16 poeng :D"
"Nå kan første spiller (blå ledning) velge farge: ");

while (player1PickColour == false){
    if (digitalRead(player1) == HIGH){
        player1PickColour = true;
        while (digitalRead(player1) == HIGH){
            player1red = random(0,255);
            player1green = random(0,255);
            player1blue = random(0,255);

        for (int i=0; i<NUMPIXELS; i++){
            pixels.setPixelColor(i, pixels.Color(player1red, player1green, player1blue));
        }
            pixels.show();
            delay(DELAYVAL*2);

        }

    }


}

for (int i=0; i < 3; i++){
pixels.clear();
pixels.show();
delay(DELAYVAL);

for (int i=0; i<NUMPIXELS; i++){
            pixels.setPixelColor(i, pixels.Color(player1red, player1green, player1blue));
        }
            pixels.show();
            delay(DELAYVAL);
}

pixels.clear();
pixels.show();
delay(DELAYVAL*2);

Serial.println("Nå skal spiller 2 velge farge");

while (player2PickColour == false){
    if (digitalRead(player2) == HIGH){
        player2PickColour = true;
        while (digitalRead(player2) == HIGH){
            player2red = random(0,255);
            player2green = random(0,255);
            player2blue = random(0,255);

        for (int i=0; i<NUMPIXELS; i++){
            pixels.setPixelColor(i, pixels.Color(player2red, player2green, player2blue));
        }
            pixels.show();
            delay(DELAYVAL*2);

        }

    }


}

for (int i=0; i < 3; i++){
pixels.clear();
pixels.show();
delay(DELAYVAL);

for (int i=0; i<NUMPIXELS; i++){
            pixels.setPixelColor(i, pixels.Color(player2red, player2green, player2blue));
        }
            pixels.show();
            delay(DELAYVAL);
}

pixels.clear();
pixels.show();
delay(DELAYVAL*4);

Serial.println("Nå starter spillet!");

}

void gameRound(){
pixels.clear();
pixels.show();

delay(DELAYVAL*2);

Serial.print("Ny runde!");

delay(random(20,4000));

for (int i=0; i<NUMPIXELS; i++){
  pixels.setPixelColor(i, pixels.Color(255, 255, 255));
}

pixels.show();

while ((digitalRead(player1) == LOW) && (digitalRead(player2) == LOW)){
}

if (digitalRead(player1) == HIGH){
  pixels.clear();
  pixels.show();
  Serial.print("poeng til spiller 1!");
  player1fastest();
}
else if (digitalRead(player2) == HIGH){
  pixels.clear();
  pixels.show();
    Serial.print("poeng til spiller 2!");
  player2fastest();
}

}


void player1fastest(){

player1points += 2;

for (int i = 0; i < (player1points+1); i++){
  pixels.setPixelColor(i, pixels.Color(player1red, player1green, player1blue));
}
  pixels.show();
  delay(DELAYVAL*5);

  pixels.clear();
  pixels.show();


}

void player2fastest(){

player2points += 2;

if (player2points < 32){
for (int i = 0; i < (player2points+1); i++){
  pixels.setPixelColor(i, pixels.Color(player2red, player2green, player2blue));  
}
pixels.show();
  delay(DELAYVAL*5);
}
else {
  player2win();
}


}


void player2win(){

Serial.print("Hold begge knapper inne for å starte på nytt!");

while ((digitalRead(player1) == LOW) || (digitalRead(player2) == LOW)){
for (int i = 0; i < NUMPIXELS; i++){
  pixels.setPixelColor(i, pixels.Color(player2red, player2green, player2blue));
  pixels.show();
  delay(DELAYVAL/16);
}

for (int i = 0; i < NUMPIXELS; i++){
  pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  pixels.show();
  delay(DELAYVAL/16);
}

}

delay(DELAYVAL*8);
gameEnd = true;

}

void player1win(){

Serial.print("Hold begge knapper for å starte på nytt!");

while ((digitalRead(player1) == LOW) || (digitalRead(player2) == LOW)){
for (int i = 0; i < NUMPIXELS; i++){
  pixels.setPixelColor(i, pixels.Color(player1red, player1green, player1blue));
  pixels.show();
  delay(DELAYVAL/16);
}

for (int i = 0; i < NUMPIXELS; i++){
  pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  pixels.show();
  delay(DELAYVAL/16);
}
}

delay(DELAYVAL*8);
gameEnd = true;

}

