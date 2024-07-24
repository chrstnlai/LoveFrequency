#include <FastLED.h>

#define NUM_LEDS 90      
#define LAST_LED_START_INDEX 60 
#define DATA_PIN 3       
#define SOUND_SENSOR_PIN A0

CRGB leds[NUM_LEDS];


const int SOUND_THRESHOLD = 120;  

void setup() {
  pinMode(DATA_PIN, OUTPUT);  
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  
  FastLED.clear();  
  FastLED.show();
}

void loop() {
  int sensorValue = analogRead(SOUND_SENSOR_PIN); 


  int brightness = map(sensorValue, 0, 1023, 0, 100); // Mapping to 0-255 for brightness range
  
  if (sensorValue > SOUND_THRESHOLD) {
    for (int i = 0; i <= brightness; i++) {
      fill_solid(&leds[LAST_LED_START_INDEX], NUM_LEDS - LAST_LED_START_INDEX, CRGB(0, i, i)); 
      FastLED.show();
      delay(10);  
    }

    for (int i = brightness; i >= 0; i--) {
      fill_solid(&leds[LAST_LED_START_INDEX], NUM_LEDS - LAST_LED_START_INDEX, CRGB(0, i, i)); 
      FastLED.show();
      delay(10);  
    }
  } else {
    FastLED.clear();  
    FastLED.show();
    delay(250);  /
  }
}
