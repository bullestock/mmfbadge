#include <FastLED.h>

const int led1 = D5;
const int led2 = D1;
const int PixelPin = D2;
const int N = 2;

CRGB rgb[N];

void setup()
{                
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);

    FastLED.addLeds<WS2811, PixelPin, GRB>(rgb, N).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(255);

}

uint8_t starthue = 0;

void loop()
{
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    fill_rainbow(rgb, N, --starthue, 20);
    FastLED.show();
    delay(1000);

    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    fill_rainbow(rgb, N, --starthue, 20);
    FastLED.show();
    delay(1000); 

    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    fill_rainbow(rgb, N, --starthue, 20);
    FastLED.show();
    delay(1000);

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    fill_rainbow(rgb, N, --starthue, 20);
    FastLED.show();
    delay(1000); 
}
