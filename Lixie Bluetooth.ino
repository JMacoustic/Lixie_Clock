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
int num = 0  // divergence
int N1, N2, N3, N4, N5, N6, N7, N8;
int Col[3] = {0,0,0}; // RGB array
int Digit[8]; 
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
  
  N1 = 1 + (now.hour()/10);
  N2 = 1 + (now.hour()%10);
  N3 = 0;
  N4 = 1 + (now.minute()/10);
  N5 = 1 + (now.minute()%10);
  N6 = 0;
  N7 = 1 + (now.second()/10);
  N8 = 1 + (now.second()%10);
  
  Digit[0] = N1;
  Digit[1] = N2;
  Digit[2] = N3;
  Digit[3] = N4;
  Digit[4] = N5;
  Digit[5] = N6;
  Digit[6] = N7;
  Digit[7] = N8;

  setColor(k);

  numMatch(Digit, output_A, output_B, output_C, output_D);


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
  
  // delay(delayval);
  
}

void setColor(int i) {
  for(int j=0; j<3; j++){
    Col[j]=1;
  }
  Col[i]=255;
}

void numMatch(int array[8], int matrix_A[2][2], matrix_B[2][2], matrix_C[2][2], matrix_D[2][2]){
  matrix_A[0][0] = numTable[0][array[0]][0];
  matrix_A[0][1] = numTable[0][array[0]][1];
  matrix_A[1][0] = numTable[1][array[1]][0];
  matrix_A[1][1] = numTable[1][array[1]][1];
  
  matrix_B[0][0] = numTable[0][array[2]][0];
  matrix_B[0][1] = numTable[0][array[2]][1];
  matrix_B[1][0] = numTable[1][array[3]][0];
  matrix_B[1][1] = numTable[1][array[3]][1]; 
  
  matrix_C[0][0] = numTable[0][array[4]][0];
  matrix_C[0][1] = numTable[0][array[4]][1];
  matrix_C[1][0] = numTable[1][array[5]][0];
  matrix_C[1][1] = numTable[1][array[5]][1]; 
  
  matrix_D[0][0] = numTable[0][array[6]][0];
  matrix_D[0][1] = numTable[0][array[6]][1];
  matrix_D[1][0] = numTable[1][array[7]][0];
  matrix_D[1][1] = numTable[1][array[7]][1]; 
} // output LED strip number that corresponds to input digit


void divergence(){
  randomSeed(analogRead(5));
  int s;
  switch(num){
    case 0:
      for(s=0; s<8; s++){
        Digit[s]=random(0,9);
      }    
      
    case 1:
      for(s=0; s<8; s++){
        Digit[s]=random(0,9);
      }
      N8 = random(0,9);
      Digit[7]=N8;
      break;
      
     case 2:
      for(s=0; s<7; s++){
        Digit[s]=random(0,9);
      }
      N7 = random(0,9);
      Digit[6]=N7;
      Digit[7]=N8;
      break;
      
     case 3:
      for(s=0; s<6; s++){
        Digit[s]=random(0,9);
      }
      N6 = random(0,9);
      Digit[5]=N6;
      Digit[6]=N7;
      Digit[7]=N8;
      break;
      
     case 4:
      for(s=0; s<5; s++){
        Digit[s]=random(0,9);
      }
      N5 = random(0,9);
      Digit[4]=N5;
      Digit[5]=N6;
      Digit[6]=N7;
      Digit[7]=N8;
      break;
      
     case 5:
      for(s=0; s<4; s++){
        Digit[s]=random(0,9);
      }
      N4 = random(0,9);
      Digit[3]=N4;
      Digit[4]=N5;
      Digit[5]=N6;
      Digit[6]=N7;
      Digit[7]=N8;
      break;
      
     case 6:
      for(s=0; s<3; s++){
        Digit[s]=random(0,9);
      }
      N3 = random(0,9);
      Digit[2]=N3;
      Digit[3]=N4;
      Digit[4]=N5;
      Digit[5]=N6;
      Digit[6]=N7;
      Digit[7]=N8;
      break;
      
     case 7:
      for(s=0; s<2; s++){
        Digit[s]=random(0,9);
      }
      N2 = 1;
      Digit[1]=N2;
      Digit[2]=N3;
      Digit[3]=N4;
      Digit[4]=N5;
      Digit[5]=N6;
      Digit[6]=N7;
      Digit[7]=N8;
      break;
     
     case 8:
      N1 = 0;
      Digit[0]=N1
      Digit[1]=N2;
      Digit[2]=N3;
      Digit[3]=N4;
      Digit[4]=N5;
      Digit[5]=N6;
      Digit[6]=N7;
      Digit[7]=N8;
      break;
  }
}
