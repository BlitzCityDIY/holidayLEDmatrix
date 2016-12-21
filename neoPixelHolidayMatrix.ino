#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <avr/pgmspace.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 3
#define NUMPIXELS 100 //# of LEDs

// Color definitions in 16 bit values
const uint16_t BLACK  =  0x0000;
const uint16_t YELLOW  =  0xFFE0;
const uint16_t GREEN = 0xF800;
const uint16_t RED = 0x07E0;
const uint16_t CYAN   =  0x07FF;
const uint16_t PINK = 0xF810;
const uint16_t BLUE  = 0x001F; 
const uint16_t WHITE  =  0xFFFF;
const uint16_t PURPLE = 0x801F;
const uint16_t ORANGE = 0xFC00;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(10, 10, 1, 1, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
  NEO_GRB           + NEO_KHZ800); 

void setup() {
  
matrix.begin();
matrix.setBrightness(40);
strip.setBrightness(40);
matrix.show();

}

void loop() {

matrix.setRotation(2); //orients scenes properly

xmasTree();
  delay(500);
  matrix.clear();

theaterChase(strip.Color(255, 255, 0), 50); //yellow

dreidelDreidelNun();
  delay(500);
  matrix.clear();

theaterChase(strip.Color(0, 0, 255), 50); //blue

dreidelDreidelGimel();
  delay(500);
  matrix.clear();

theaterChase(strip.Color(255, 255, 0), 50); //yellow

dreidelDreidelHe();
  delay(500);
  matrix.clear();

theaterChase(strip.Color(0, 0, 255), 50); //blue

dreidelDreidelShin();
  delay(500);
  matrix.clear();

theaterChase(strip.Color(255, 0, 0), 50);

theaterChase(strip.Color(0, 255, 0), 50);

redAndGreenHLines();
  delay(500);
  matrix.clear();

redAndGreenVLines();
  delay(500);
  matrix.clear();

redAndGreenVortex();
  delay(500);
  matrix.clear();

candyCane();
  delay(500);
  matrix.clear();

matrix.setRotation(1); //orients letters properly

happyHolidays();
  delay(500);
  matrix.clear();

}

void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void xmasTree() { 
  matrix.drawRect(0, 0, 10, 10, RED); //background
  matrix.drawRect(1, 1, 8, 8, RED);
  matrix.drawRect(2, 2, 6, 6, RED);
  matrix.drawRect(3, 3, 4, 4, RED);
  matrix.drawRect(4, 4, 2, 2, RED);
  matrix.drawPixel(1, 5, YELLOW); //star
  matrix.fillTriangle(8, 2, 2, 5, 8, 8, GREEN); //tree
    matrix.show(); //sends LED information
    delay(5000); //length of time scene is shown
}

void dreidelDreidelHe() {
  matrix.drawRect(0, 0, 10, 10, YELLOW); //background
  matrix.drawRect(1, 1, 8, 8, YELLOW);
  matrix.drawRect(2, 2, 6, 6, YELLOW);
  matrix.drawRect(3, 3, 4, 4, YELLOW);
  matrix.drawRect(4, 4, 2, 2, YELLOW);
  matrix.drawLine(3, 7, 3, 4, BLUE);
  matrix.drawLine(4, 3, 7, 3, BLUE); //He
  matrix.drawLine(5, 7, 7, 7, BLUE);
    matrix.show(); //sends LED information
    delay(5000); //length of time scene is shown
}

void dreidelDreidelGimel() {
  matrix.drawRect(0, 0, 10, 10, BLUE); //background
  matrix.drawRect(1, 1, 8, 8, BLUE);
  matrix.drawRect(2, 2, 6, 6, BLUE);
  matrix.drawRect(3, 3, 4, 4, BLUE);
  matrix.drawRect(4, 4, 2, 2, BLUE);
  matrix.drawLine(2, 6, 2, 5, YELLOW); //Gimel
  matrix.drawLine(3, 4, 5, 4, YELLOW);
  matrix.drawLine(6, 5, 7, 6, YELLOW);
  matrix.drawLine(6, 3, 7, 2, YELLOW);
    matrix.show(); //sends LED information
    delay(5000); //length of time scene is shown
}

void dreidelDreidelShin() {
  matrix.drawRect(0, 0, 10, 10, YELLOW); //background
  matrix.drawRect(1, 1, 8, 8, YELLOW);
  matrix.drawRect(2, 2, 6, 6, YELLOW);
  matrix.drawRect(3, 3, 4, 4, YELLOW);
  matrix.drawRect(4, 4, 2, 2, YELLOW);
  matrix.drawLine(3, 8, 5, 8, BLUE); //Shin
  matrix.drawLine(6, 7, 5, 6, BLUE);
  matrix.drawLine(3, 5, 4, 5, BLUE);
  matrix.drawLine(7, 6, 7, 4, BLUE);
  matrix.drawLine(3, 2, 5, 2, BLUE);
  matrix.drawPixel(6, 3, BLUE);
    matrix.show(); //sends LED information
    delay(5000); //length of time scene is shown
}

void dreidelDreidelNun() {
  matrix.drawRect(0, 0, 10, 10, BLUE); //background
  matrix.drawRect(1, 1, 8, 8, BLUE);
  matrix.drawRect(2, 2, 6, 6, BLUE);
  matrix.drawRect(3, 3, 4, 4, BLUE);
  matrix.drawRect(4, 4, 2, 2, BLUE);
  matrix.drawLine(2, 6, 2, 5, YELLOW); //Nun
  matrix.drawLine(3, 4, 6, 4, YELLOW);
  matrix.drawLine(7, 6, 7, 4, YELLOW);
    matrix.show(); //sends LED information
    delay(5000); //length of time scene is shown
}

void redAndGreenHLines() {
  matrix.drawLine(0, 0, 0, 9, RED); //1st &/or top horizontal line
  matrix.drawLine(1, 0, 1, 9, GREEN); //2nd, etc
  matrix.drawLine(2, 0, 2, 9, RED);
  matrix.drawLine(3, 0, 3, 9, GREEN);
  matrix.drawLine(4, 0, 4, 9, RED);
  matrix.drawLine(5, 0, 5, 9, GREEN);
  matrix.drawLine(6, 0, 6, 9, RED);
  matrix.drawLine(7, 0, 7, 9, GREEN);
  matrix.drawLine(8, 0, 8, 9, RED);
  matrix.drawLine(9, 0, 9, 9, GREEN);
    matrix.show(); //sends LED information
    delay(1000); //length of time scene is shown
}

void redAndGreenVLines() {
  matrix.drawLine(0, 0, 9, 0, RED); //1st left vertical line
  matrix.drawLine(0, 1, 9, 1, GREEN); //2nd, etc
  matrix.drawLine(0, 2, 9, 2, RED);
  matrix.drawLine(0, 3, 9, 3, GREEN);
  matrix.drawLine(0, 4, 9, 4, RED);
  matrix.drawLine(0, 5, 9, 5, GREEN);
  matrix.drawLine(0, 6, 9, 6, RED);
  matrix.drawLine(0, 7, 9, 7, GREEN);
  matrix.drawLine(0, 8, 9, 8, RED);
  matrix.drawLine(0, 9, 9, 9, GREEN);
    matrix.show(); //sends LED information
    delay(1000); //length of time scene is shown
}

void redAndGreenVortex() {
  matrix.drawRect(0, 0, 10, 10, GREEN); //outside border
  matrix.drawRect(1, 1, 8, 8, RED); //one row in, etc
  matrix.drawRect(2, 2, 6, 6, GREEN);
  matrix.drawRect(3, 3, 4, 4, RED);
  matrix.drawRect(4, 4, 2, 2, GREEN);
    matrix.show(); //sends LED information
    delay(1000); //length of time scene is shown
}

void candyCane() {
  matrix.drawRect(0, 0, 10, 10, GREEN); //background
  matrix.drawRect(1, 1, 8, 8, GREEN);
  matrix.drawRect(2, 2, 6, 6, GREEN);
  matrix.drawRect(3, 3, 4, 4, GREEN);
  matrix.drawRect(4, 4, 2, 2, GREEN);
  //1st cane
  matrix.drawPixel(1, 9, RED);
  matrix.drawPixel(0, 8, WHITE);
  matrix.drawPixel(1, 7, RED);
  matrix.drawPixel(2, 7, WHITE);
  matrix.drawPixel(3, 7, RED);
  //2nd cane
  matrix.drawPixel(1, 5, RED);
  matrix.drawPixel(0, 4, WHITE);
  matrix.drawPixel(1, 3, RED);
  matrix.drawPixel(2, 3, WHITE);
  matrix.drawPixel(3, 3, RED);
  //3rd cane
  matrix.drawPixel(6, 7, RED);
  matrix.drawPixel(5, 6, WHITE);
  matrix.drawPixel(6, 5, RED);
  matrix.drawPixel(7, 5, WHITE);
  matrix.drawPixel(8, 5, RED);
  //4th cane
  matrix.drawPixel(6, 3, RED);
  matrix.drawPixel(5, 2, WHITE);
  matrix.drawPixel(6, 1, RED);
  matrix.drawPixel(7, 1, WHITE);
  matrix.drawPixel(8, 1, RED);
    matrix.show(); //sends LED information
    delay(5000); //length of time scene is shown
}

void happyHolidays() {
matrix.drawLine(0, 0, 0, 9, GREEN); //background fills in what letter background doesn't
matrix.drawLine(1, 0, 1, 9, GREEN);
matrix.drawLine(2, 0, 2, 9, GREEN);
matrix.drawLine(3, 0, 9, 0, GREEN);
matrix.drawLine(3, 1, 9, 1, GREEN);
matrix.drawLine(9, 2, 9, 9, GREEN);
  matrix.setCursor(3, 2); //sets position for top LH corner of the letter box, like positioning the type position in text or Word .doc
  matrix.setTextColor(RED, GREEN); //1st color is the letter color, 2nd is the background color directly around the letter
  matrix.print(F("H")); //text to display, can be any length
    matrix.show(); //sends LED information
    delay(2000); //length of time letter is shown
    matrix.clear(); //resets matrix for next letter

matrix.drawLine(0, 0, 0, 9, BLUE);
matrix.drawLine(1, 0, 1, 9, BLUE);
matrix.drawLine(2, 0, 2, 9, BLUE);
matrix.drawLine(3, 0, 9, 0, BLUE);
matrix.drawLine(3, 1, 9, 1, BLUE);
matrix.drawLine(9, 2, 9, 9, BLUE);
  matrix.setCursor(3, 2);
  matrix.setTextColor(GREEN, BLUE);
  matrix.print(F("A"));
    matrix.show();
    delay(2000);
    matrix.clear();

matrix.drawLine(0, 0, 0, 9, YELLOW);
matrix.drawLine(1, 0, 1, 9, YELLOW);
matrix.drawLine(2, 0, 2, 9, YELLOW);
matrix.drawLine(3, 0, 9, 0, YELLOW);
matrix.drawLine(3, 1, 9, 1, YELLOW);
matrix.drawLine(9, 2, 9, 9, YELLOW);
  matrix.setCursor(3, 2);
  matrix.setTextColor(BLUE, YELLOW);
  matrix.print(F("P"));
    matrix.show();
    delay(2000);
    matrix.clear();

matrix.drawLine(0, 0, 0, 9, PURPLE);
matrix.drawLine(1, 0, 1, 9, PURPLE);
matrix.drawLine(2, 0, 2, 9, PURPLE);
matrix.drawLine(3, 0, 9, 0, PURPLE);
matrix.drawLine(3, 1, 9, 1, PURPLE);
matrix.drawLine(9, 2, 9, 9, PURPLE);
  matrix.setCursor(3, 2);
  matrix.setTextColor(YELLOW, PURPLE);
  matrix.print(F("P"));
    matrix.show();
    delay(2000);
    matrix.clear();

matrix.drawLine(0, 0, 0, 9, WHITE);
matrix.drawLine(1, 0, 1, 9, WHITE);
matrix.drawLine(2, 0, 2, 9, WHITE);
matrix.drawLine(3, 0, 9, 0, WHITE);
matrix.drawLine(3, 1, 9, 1, WHITE);
matrix.drawLine(9, 2, 9, 9, WHITE);
  matrix.setCursor(3, 2);
  matrix.setTextColor(PURPLE, WHITE);
  matrix.print(F("Y"));
    matrix.show();
    delay(2000);
    matrix.clear();

matrix.drawLine(0, 0, 0, 9, PINK);
matrix.drawLine(1, 0, 1, 9, PINK);
matrix.drawLine(2, 0, 2, 9, PINK);
matrix.drawLine(3, 0, 9, 0, PINK);
matrix.drawLine(3, 1, 9, 1, PINK);
matrix.drawLine(9, 2, 9, 9, PINK);
  matrix.setCursor(3, 2);
  matrix.setTextColor(WHITE, PINK);
  matrix.print(F("*"));
    matrix.show();
    delay(2000);
    matrix.clear();

matrix.drawLine(0, 0, 0, 9, CYAN);
matrix.drawLine(1, 0, 1, 9, CYAN);
matrix.drawLine(2, 0, 2, 9, CYAN);
matrix.drawLine(3, 0, 9, 0, CYAN);
matrix.drawLine(3, 1, 9, 1, CYAN);
matrix.drawLine(9, 2, 9, 9, CYAN);
  matrix.setCursor(3, 2);
  matrix.setTextColor(PINK, CYAN);
  matrix.print(F("H"));
    matrix.show();
    delay(2000);
    matrix.clear();

matrix.drawLine(0, 0, 0, 9, RED);
matrix.drawLine(1, 0, 1, 9, RED);
matrix.drawLine(2, 0, 2, 9, RED);
matrix.drawLine(3, 0, 9, 0, RED);
matrix.drawLine(3, 1, 9, 1, RED);
matrix.drawLine(9, 2, 9, 9, RED);
  matrix.setCursor(3, 2);
  matrix.setTextColor(CYAN, RED);
  matrix.print(F("O"));
    matrix.show();
    delay(2000);
    matrix.clear();

matrix.drawLine(0, 0, 0, 9, GREEN);
matrix.drawLine(1, 0, 1, 9, GREEN);
matrix.drawLine(2, 0, 2, 9, GREEN);
matrix.drawLine(3, 0, 9, 0, GREEN);
matrix.drawLine(3, 1, 9, 1, GREEN);
matrix.drawLine(9, 2, 9, 9, GREEN);
  matrix.setCursor(3, 2);
  matrix.setTextColor(RED, GREEN);
  matrix.print(F("L"));
    matrix.show();
    delay(2000);
    matrix.clear();

matrix.drawLine(0, 0, 0, 9, BLUE);
matrix.drawLine(1, 0, 1, 9, BLUE);
matrix.drawLine(2, 0, 2, 9, BLUE);
matrix.drawLine(3, 0, 9, 0, BLUE);
matrix.drawLine(3, 1, 9, 1, BLUE);
matrix.drawLine(9, 2, 9, 9, BLUE);
  matrix.setCursor(3, 2);
  matrix.setTextColor(GREEN, BLUE);
  matrix.print(F("I"));
    matrix.show();
    delay(2000);
    matrix.clear();

matrix.drawLine(0, 0, 0, 9, YELLOW);
matrix.drawLine(1, 0, 1, 9, YELLOW);
matrix.drawLine(2, 0, 2, 9, YELLOW);
matrix.drawLine(3, 0, 9, 0, YELLOW);
matrix.drawLine(3, 1, 9, 1, YELLOW);
matrix.drawLine(9, 2, 9, 9, YELLOW);
  matrix.setCursor(3, 2);
  matrix.setTextColor(BLUE, YELLOW);
  matrix.print(F("D"));
    matrix.show();
    delay(2000);
    matrix.clear();

matrix.drawLine(0, 0, 0, 9, PURPLE);
matrix.drawLine(1, 0, 1, 9, PURPLE);
matrix.drawLine(2, 0, 2, 9, PURPLE);
matrix.drawLine(3, 0, 9, 0, PURPLE);
matrix.drawLine(3, 1, 9, 1, PURPLE);
matrix.drawLine(9, 2, 9, 9, PURPLE);
  matrix.setCursor(3, 2);
  matrix.setTextColor(YELLOW, PURPLE);
  matrix.print(F("A"));
    matrix.show();
    delay(2000);
    matrix.clear();

matrix.drawLine(0, 0, 0, 9, WHITE);
matrix.drawLine(1, 0, 1, 9, WHITE);
matrix.drawLine(2, 0, 2, 9, WHITE);
matrix.drawLine(3, 0, 9, 0, WHITE);
matrix.drawLine(3, 1, 9, 1, WHITE);
matrix.drawLine(9, 2, 9, 9, WHITE);
  matrix.setCursor(3, 2);
  matrix.setTextColor(PURPLE, WHITE);
  matrix.print(F("Y"));
    matrix.show();
    delay(2000);
    matrix.clear();

matrix.drawLine(0, 0, 0, 9, PINK);
matrix.drawLine(1, 0, 1, 9, PINK);
matrix.drawLine(2, 0, 2, 9, PINK);
matrix.drawLine(3, 0, 9, 0, PINK);
matrix.drawLine(3, 1, 9, 1, PINK);
matrix.drawLine(9, 2, 9, 9, PINK);
  matrix.setCursor(3, 2);
  matrix.setTextColor(WHITE, PINK);
  matrix.print(F("S"));
    matrix.show();
    delay(2000);
    matrix.clear();

matrix.drawLine(0, 0, 0, 9, CYAN);
matrix.drawLine(1, 0, 1, 9, CYAN);
matrix.drawLine(2, 0, 2, 9, CYAN);
matrix.drawLine(3, 0, 9, 0, CYAN);
matrix.drawLine(3, 1, 9, 1, CYAN);
matrix.drawLine(9, 2, 9, 9, CYAN);
  matrix.setCursor(3, 2);
  matrix.setTextColor(PINK, CYAN);
  matrix.print(F("!"));
    matrix.show();
    delay(2000);
    matrix.clear();

matrix.drawLine(0, 0, 0, 9, RED);
matrix.drawLine(1, 0, 1, 9, RED);
matrix.drawLine(2, 0, 2, 9, RED);
matrix.drawLine(3, 0, 9, 0, RED);
matrix.drawLine(3, 1, 9, 1, RED);
matrix.drawLine(9, 2, 9, 9, RED);
  matrix.setCursor(3, 2);
  matrix.setTextColor(CYAN, RED);
  matrix.print(F("*"));
    matrix.show();
    delay(2000);
    matrix.clear();
}
