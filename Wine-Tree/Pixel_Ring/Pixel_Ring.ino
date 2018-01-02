#include <Adafruit_NeoPixel.h>

#define PIN 6
/* num of pixels in strip, pin num (most are valid), pixel type flags, add together as needed:
   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2) */
Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(30);
  strip.show();
}

void loop() {
  colorWipe(strip.Color(255,0,0),50); //red
  colorWipe(strip.Color(0,255,0),50); //green
  colorWipe(strip.Color(0,0,255),50); //blue
  rainbow(20);
  rainbowCycle(20);
}

void colorWipe(uint32_t c, uint8_t wait){
  for(int i=0; i<strip.numPixels(); i++){
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait){
  uint16_t i, j;

  for(j = 0; j< 256; j++){
    for(int i=0; i<strip.numPixels(); i++){
      strip.setPixelColor(i, Wheel((i+j)&255));
    }
    strip.show();
    delay(wait);
  }
}

void rainbowCycle(uint8_t wait){
  uint16_t i, j;

  for(j = 0; j< 256*5; j++){ //5 cycles of every color on wheel
    for(int i=0; i<strip.numPixels(); i++){
      strip.setPixelColor(i, Wheel(((i*256 / strip.numPixels())+j)&255));
    }
    strip.show();
    delay(wait);
  }
}

//0-255 for color value
uint32_t Wheel(byte WheelPos){
  if(WheelPos < 85){
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3,0);
  } else if(WheelPos < 170){
    WheelPos -= 85;
    return strip.Color(255 - WheelPos * 3,0,WheelPos * 3);
  } else {
    WheelPos -=170;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

