#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9340.h"

#define _sclk 13
#define _miso 12
#define _mosi 11
#define _cs 10
#define _rst 9
#define _dc 8

Adafruit_ILI9340 tft = Adafruit_ILI9340(_cs, _dc, _rst);

int x;
int y;
int WIDTH;
int HEIGHT;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A5, INPUT);
  tft.begin();
  tft.fillScreen(ILI9340_BLACK);
  
  WIDTH = tft.width();
  HEIGHT = tft.height();
}

void loop() {
  x = map(analogRead(A0), 0, 1023, 0, WIDTH);
  y = map(analogRead(A5), 0, 1023, HEIGHT, 0);
  tft.drawPixel(x, y, ILI9340_WHITE);
}
