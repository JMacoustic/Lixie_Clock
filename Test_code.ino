#include <Adafruit_NeoPixel.h>
#define PIN 6	     // input pin Neopixel is attached to
#define NUMPIXELS 22 // number of neopixels in strip
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 1000; // timing delay in milliseconds
int num = 0;
int k = 0;
int Col[3] = {0,0,0};


// setColor()
// picks random values to set for RGB
void setColor(int i) {
    for(int j=0; j<3; j++){
      Col[j]=1;
    }
    Col[i]=255;
}

void setup() {
    pixels.begin(); // Initialize the NeoPixel library.
}

void loop() { 
  setColor(k);

    for(num=0; num<11; num++){
      switch(num) {
        case 0:
          pixels.setPixelColor(1, pixels.Color(Col[0], Col[1], Col[2]));
            pixels.setPixelColor(7, pixels.Color(Col[0], Col[1], Col[2]));
            pixels.show();
            pixels.setPixelColor(1, pixels.Color(0, 0, 0));
            pixels.setPixelColor(7, pixels.Color(0, 0, 0));
            break;
        case 1:
          pixels.setPixelColor(2, pixels.Color(Col[0], Col[1], Col[2]));
            pixels.setPixelColor(6, pixels.Color(Col[0], Col[1], Col[2]));
            pixels.show();
            pixels.setPixelColor(2, pixels.Color(0, 0, 0));
            pixels.setPixelColor(6, pixels.Color(0, 0, 0));
            break;
        case 2:
          pixels.setPixelColor(5, pixels.Color(Col[0], Col[1], Col[2]));
            pixels.setPixelColor(9, pixels.Color(Col[0], Col[1], Col[2]));
            pixels.show();
            pixels.setPixelColor(5, pixels.Color(0, 0, 0));
            pixels.setPixelColor(9, pixels.Color(0, 0, 0));
            break;
        case 3:
          pixels.setPixelColor(4, pixels.Color(Col[0], Col[1], Col[2]));
            pixels.setPixelColor(10, pixels.Color(Col[0], Col[1], Col[2]));
            pixels.show();
            pixels.setPixelColor(4, pixels.Color(0, 0, 0));
            pixels.setPixelColor(10, pixels.Color(0, 0, 0));
            break;
        case 4:
          pixels.setPixelColor(3, pixels.Color(Col[0], Col[1], Col[2]));
            pixels.setPixelColor(11, pixels.Color(Col[0], Col[1], Col[2]));
            pixels.show();
            pixels.setPixelColor(3, pixels.Color(0, 0, 0));
            pixels.setPixelColor(11, pixels.Color(0, 0, 0));
            break;
        case 5:
          pixels.setPixelColor(12, pixels.Color(Col[0], Col[1], Col[2]));
            pixels.setPixelColor(19, pixels.Color(Col[0], Col[1], Col[2]));
            pixels.show();
            pixels.setPixelColor(12, pixels.Color(0, 0, 0));
            pixels.setPixelColor(19, pixels.Color(0, 0, 0));
            break;
        case 6:
          pixels.setPixelColor(13, pixels.Color(Col[0], Col[1], Col[2]));
            pixels.setPixelColor(18, pixels.Color(Col[0], Col[1], Col[2]));
            pixels.show();
            pixels.setPixelColor(13, pixels.Color(0, 0, 0));
            pixels.setPixelColor(18, pixels.Color(0, 0, 0));
            break;
        case 7:
          pixels.setPixelColor(14, pixels.Color(Col[0], Col[1], Col[2]));
            pixels.setPixelColor(17, pixels.Color(Col[0], Col[1], Col[2]));
            pixels.show();
            pixels.setPixelColor(14, pixels.Color(0, 0, 0));
            pixels.setPixelColor(17, pixels.Color(0, 0, 0));
            break;
        case 8:
          pixels.setPixelColor(16, pixels.Color(Col[0], Col[1], Col[2]));
            pixels.setPixelColor(20, pixels.Color(Col[0], Col[1], Col[2]));
            pixels.show();
            pixels.setPixelColor(16, pixels.Color(0, 0, 0));
            pixels.setPixelColor(20, pixels.Color(0, 0, 0));
            break;
        case 9:
          pixels.setPixelColor(15, pixels.Color(Col[0], Col[1], Col[2]));
            pixels.setPixelColor(21, pixels.Color(Col[0], Col[1], Col[2]));
            pixels.show();
            pixels.setPixelColor(15, pixels.Color(0, 0, 0));
            pixels.setPixelColor(21, pixels.Color(0, 0, 0));
            break;
        default:
          pixels.setPixelColor(0, pixels.Color(Col[0], Col[1], Col[2]));
            pixels.setPixelColor(8, pixels.Color(Col[0], Col[1], Col[2]));
            pixels.show();
            pixels.setPixelColor(0, pixels.Color(0, 0, 0));
            pixels.setPixelColor(8, pixels.Color(0, 0, 0));
            break;
        }
      
      delay(delayval);    // Delay for a period of time (in milliseconds).
      if (num > 11) break;
    }
  k++;
  if(k>2) k=k-3;
}