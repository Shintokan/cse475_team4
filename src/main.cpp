#include <Arduino.h>
#include <HCSR04.h>            // HCSR04 ultrasonic sensor@^2.0.3 library
#include <Adafruit_NeoPixel.h> // onboard RGB library

#define PIN 38 // RGB
#define NUMPIXELS 1

// sensor 1
const byte trig1 = 6;
const byte echo1 = 7;

// sensor 2
const byte trig2 = 12;
const byte echo2 = 11;

// onboard RGB setup
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// setting up both sensors
HCSR04 sensor1(6, 7);
HCSR04 sensor2(12, 11);

// Threshold distance in cm (triggers green color)
const float THRESHOLD = 10.0;

void setup()
{
  Serial.begin(9600);
  pixels.begin();
}

void loop()
{
  // get distance measurements
  float dist1 = sensor1.dist();
  float dist2 = sensor2.dist();

  // print statements for debugging
  Serial.print("sensor 1: ");
  Serial.println(dist1);
  Serial.print("sensor 2: ");
  Serial.println(dist2);

  // if object is within the THRESHOLD
  if (dist1 <= THRESHOLD && dist2 <= THRESHOLD)
  {
    Serial.println("THRESHOLD MET!");
    pixels.setPixelColor(0, pixels.Color(0, 255, 0)); // GREEN
  }
  else
  {
    pixels.setPixelColor(0, pixels.Color(255, 0, 0)); // RED
  }
  pixels.show();
  delay(1000);
}
