#include <math.h>
#include <NeoPixelBus.h>
const uint16_t PixelCount = 8;
NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(PixelCount);

// For Esp8266, the Pin is omitted and it uses GPIO3 due to DMA hardware use.
// There are other Esp8266 alternative methods that provide more pin options,
// but also have
// other side effects.
// NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(PixelCount);
//
// NeoEsp8266Uart800KbpsMethod uses GPI02 instead
// You can also use one of these for Esp8266,
// each having their own restrictions
// These two are the same as above as the DMA method is the default
// NOTE: These will ignore the PIN and use GPI03 pin
// NeoPixelBus<NeoGrbFeature, NeoEsp8266Dma800KbpsMethod> strip(PixelCount,
// PixelPin);
// NeoPixelBus<NeoRgbFeature, NeoEsp8266Dma400KbpsMethod> strip(PixelCount,
// PixelPin);

// Uart method is good for the Esp-01 or other pin restricted modules
// NOTE: These will ignore the PIN and use GPI02 pin
// NeoPixelBus<NeoGrbFeature, NeoEsp8266Uart800KbpsMethod> strip(PixelCount,
// PixelPin);
// NeoPixelBus<NeoRgbFeature, NeoEsp8266Uart400KbpsMethod> strip(PixelCount,
// PixelPin);

// The bitbang method is really only good if you are not using WiFi features of
// the ESP
// It works with all but pin 16
// NeoPixelBus<NeoGrbFeature, NeoEsp8266BitBang800KbpsMethod> strip(PixelCount,
// PixelPin);
// NeoPixelBus<NeoRgbFeature, NeoEsp8266BitBang400KbpsMethod> strip(PixelCount,
// PixelPin);

#define colorSaturation 128
RgbColor red(colorSaturation, 0, 0);
RgbColor green(0, colorSaturation, 0);
RgbColor blue(0, 0, colorSaturation);
RgbColor white(colorSaturation);
RgbColor black(0);

void leds_setup() {
  // this resets all the neopixels to an off state
  strip.Begin();
  strip.Show();
}

void drawPixels(float startColor) {
  for (int i = 0; i < PixelCount; i++) {
    float color = (float)i / (PixelCount - 1) * 0.2;
    strip.SetPixelColor(i, HslColor(startColor + color, 1.0f, 0.5f));
  }

  strip.Show();
}
float color = 0;
void leds_loop() {
  // strip.SetPixelColor(0, i ? red : green);
  // strip.SetPixelColor(1, i ? green : red);
  // strip.Show();
  // i = !i;
  // delay(1000);
  drawPixels(color);
  color += 0.01;
  if (color > 1)
    color = 0;
  delay(20);
}
