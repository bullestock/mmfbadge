#include <FastLED.h>

#include "neomatrix.hpp"
#include "display.hpp"

const int led1 = D5;
const int led2 = D1;
const int PixelPin = D2;
int effective_leds = 2;

CRGB* leds;

void setup()
{                
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);

    leds = new CRGB[effective_leds];
    
    FastLED.addLeds<WS2811, PixelPin, GRB>(leds, effective_leds).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(255);

    clear_all();
    FastLED.show();
    
    neomatrix_init();
}

uint8_t starthue = 0;

int pwm_val = 0;
void loop()
{
    analogWrite(led1, pwm_val);
    analogWrite(led2, 1024-pwm_val);
    ++pwm_val;
    if (pwm_val >= 1024)
        pwm_val = 0;
    
    neomatrix_run();
    
    delay(10);
#if 0
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    fill_rainbow(leds, N, --starthue, 20);
    FastLED.show();
    delay(1000); 

    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    fill_rainbow(leds, N, --starthue, 20);
    FastLED.show();
    delay(1000);

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    fill_rainbow(leds, N, --starthue, 20);
    FastLED.show();
    delay(1000);
#endif
}

void clear_all()
{
    memset(leds, 0, effective_leds * 3);
}

void show()
{
    FastLED.show();
}

