#include <Arduino.h>
#include <leds.h>
#include <buttons.h>

void setup() {
  Serial.begin(9600);

  leds_setup();
}

void loop() {
  leds_loop();
}