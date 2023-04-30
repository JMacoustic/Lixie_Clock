#include <RTClib.h>
#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#define PIN_A 4
#define PIN_B 5
#define PIN_C 6	     // input pin Neopixel is attached to
#define PIN_D 7
#define NUMPIXELS 44 // number of neopixels in strip
RTC_DS3231 rtc;
Adafruit_NeoPixel pixel_A = Adafruit_NeoPixel(NUMPIXELS, PIN_A, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixel_B = Adafruit_NeoPixel(NUMPIXELS, PIN_B, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixel_C = Adafruit_NeoPixel(NUMPIXELS, PIN_C, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixel_D = Adafruit_NeoPixel(NUMPIXELS, PIN_D, NEO_GRB + NEO_KHZ800);

int delayval = 1000;  // timing delay in milliseconds 
int k = 0;  // Color type : R/G/B 
int N1, N2, N3, N4, N5, N6, N7, N8;
int Col[3] = {0,0,0}; // RGB array
int Digit_A[2], Digit_B[2], Digit_C[2], Digit_D[2];  // 2 numbers of second
int output_A[2][2], output_B[2][2], output_C[2][2], output_D[2][2];


int numTable[2][11][2] = {
  {{0,8},{1,7},{2,6},{5,9},{4,10},{3,11},{12,19},{13,18},{14,17},{16,20},{15,21}},
  {{22,30},{23,29},{24,28},{27,31},{26,32},{25,33},{34,41},{35,40},{36,39},{38,42},{37,43}}
  };  // convert digits to LED strip number


void setup() {
    pixel_A.begin(); // Initialize the NeoPixel library.
    pixel_B.begin();
    pixel_C.begin();
    pixel_D.begin();
    Serial.begin(9600);
    Wire.begin();
    rtc.begin();

}

void loop() { 
  DateTime now = rtc.now();
  
  N1 = now.hour()/10;
  N2 = now.hour()%10;
  N3 = 0;
  N4 = now.minute()/10;
  N5 = now.minute()%10;
  N6 = 0;
  N7 = now.second()/10;
  N8 = now.second()%10;
  
  Digit_A[0] = N1;
  Digit_A[1] = N2;
  Digit_B[0] = N3;
  Digit_B[1] = N4;
  Digit_C[0] = N5;
  Digit_C[1] = N6;
  Digit_D[0] = N7;
  Digit_D[1] = N8;

  setColor(k);

  numMatch(Digit_A, output_A);
  numMatch(Digit_B, output_B);
  numMatch(Digit_C, output_C);
  numMatch(Digit_D, output_D);

  for(int p=0; p<2; p++){
    for (int q=0;q<2; q++){
      pixel_A.setPixelColor(output_A[p][q], pixel_A.Color(Col[0], Col[1], Col[2]));
      pixel_B.setPixelColor(output_B[p][q], pixel_B.Color(Col[0], Col[1], Col[2]));
      pixel_C.setPixelColor(output_C[p][q], pixel_C.Color(Col[0], Col[1], Col[2]));
      pixel_D.setPixelColor(output_D[p][q], pixel_D.Color(Col[0], Col[1], Col[2]));      
    }
  } // Lights on 
  
  pixel_A.show();
  pixel_B.show();
  pixel_C.show();
  pixel_D.show();

  for(int p=0; p<2; p++){
    for (int q=0;q<2; q++){
      pixel_A.setPixelColor(output_A[p][q], pixel_A.Color(0, 0, 0));
      pixel_B.setPixelColor(output_B[p][q], pixel_B.Color(0, 0, 0));
      pixel_C.setPixelColor(output_C[p][q], pixel_C.Color(0, 0, 0));
      pixel_D.setPixelColor(output_D[p][q], pixel_D.Color(0, 0, 0));
    }
  } // Lights off
  
  delay(delayval);
  
  //k++;
  //if(k>2) k=k-3;
}

void setColor(int i) {
  for(int j=0; j<3; j++){
    Col[j]=1;
  }
  Col[i]=255;
}

void numMatch(int array[2], int matrix[2][2]){
  matrix[0][0] = numTable[0][array[0]][0];
  matrix[0][1] = numTable[0][array[0]][1];
  matrix[1][0] = numTable[1][array[1]][0];
  matrix[1][1] = numTable[1][array[1]][1]; 
} // output LED strip number that corresponds to input digit