# 1 "C:\\Users\\maria\\OneDrive\\NTNU\\1sem\\IELS\\ledliste\\refleksSpill\\ledliste\\Spill\\Spill.ino"
# 2 "C:\\Users\\maria\\OneDrive\\NTNU\\1sem\\IELS\\ledliste\\refleksSpill\\ledliste\\Spill\\Spill.ino" 2

# 4 "C:\\Users\\maria\\OneDrive\\NTNU\\1sem\\IELS\\ledliste\\refleksSpill\\ledliste\\Spill\\Spill.ino" 2





# 8 "C:\\Users\\maria\\OneDrive\\NTNU\\1sem\\IELS\\ledliste\\refleksSpill\\ledliste\\Spill\\Spill.ino"
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

Adafruit_NeoPixel pixels(32, 11, ((1 << 6) | (1 << 4) | (0 << 2) | (2)) /*|< Transmit as G,R,B*/ + 0x0000 /*|< 800 KHz data transmission*/);


void setup() {
  Serial.begin(9600);




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
    if (digitalRead(player1) == 0x1){
        player1PickColour = true;
        while (digitalRead(player1) == 0x1){
            player1red = random(0,255);
            player1green = random(0,255);
            player1blue = random(0,255);

        for (int i=0; i<32; i++){
            pixels.setPixelColor(i, pixels.Color(player1red, player1green, player1blue));
        }
            pixels.show();
            delay(400*2);

        }

    }


}

for (int i=0; i < 3; i++){
pixels.clear();
pixels.show();
delay(400);

for (int i=0; i<32; i++){
            pixels.setPixelColor(i, pixels.Color(player1red, player1green, player1blue));
        }
            pixels.show();
            delay(400);
}

pixels.clear();
pixels.show();
delay(400*2);

Serial.println("Nå skal spiller 2 velge farge");

while (player2PickColour == false){
    if (digitalRead(player2) == 0x1){
        player2PickColour = true;
        while (digitalRead(player2) == 0x1){
            player2red = random(0,255);
            player2green = random(0,255);
            player2blue = random(0,255);

        for (int i=0; i<32; i++){
            pixels.setPixelColor(i, pixels.Color(player2red, player2green, player2blue));
        }
            pixels.show();
            delay(400*2);

        }

    }


}

for (int i=0; i < 3; i++){
pixels.clear();
pixels.show();
delay(400);

for (int i=0; i<32; i++){
            pixels.setPixelColor(i, pixels.Color(player2red, player2green, player2blue));
        }
            pixels.show();
            delay(400);
}

pixels.clear();
pixels.show();
delay(400*4);

Serial.println("Nå starter spillet!");

}

void gameRound(){
pixels.clear();
pixels.show();

delay(400*2);

Serial.print("Ny runde!");

delay(random(20,4000));

for (int i=0; i<32; i++){
  pixels.setPixelColor(i, pixels.Color(255, 255, 255));
}

pixels.show();

while ((digitalRead(player1) == 0x0) && (digitalRead(player2) == 0x0)){
}

if (digitalRead(player1) == 0x1){
  pixels.clear();
  pixels.show();
  Serial.print("poeng til spiller 1!");
  player1fastest();
}
else if (digitalRead(player2) == 0x1){
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
  delay(400*5);

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
  delay(400*5);
}
else {
  player2win();
}


}


void player2win(){

Serial.print("Hold begge knapper inne for å starte på nytt!");

while ((digitalRead(player1) == 0x0) || (digitalRead(player2) == 0x0)){
for (int i = 0; i < 32; i++){
  pixels.setPixelColor(i, pixels.Color(player2red, player2green, player2blue));
  pixels.show();
  delay(400/16);
}

for (int i = 0; i < 32; i++){
  pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  pixels.show();
  delay(400/16);
}

}

delay(400*8);
gameEnd = true;

}

void player1win(){

Serial.print("Hold begge knapper for å starte på nytt!");

while ((digitalRead(player1) == 0x0) || (digitalRead(player2) == 0x0)){
for (int i = 0; i < 32; i++){
  pixels.setPixelColor(i, pixels.Color(player1red, player1green, player1blue));
  pixels.show();
  delay(400/16);
}

for (int i = 0; i < 32; i++){
  pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  pixels.show();
  delay(400/16);
}
}

delay(400*8);
gameEnd = true;

}
