void lightning() {
  if (count % random(100, 1000) == 0) {
    for (int i = 0; i < 25; i++) {
      leds[i] = CRGB( r, g, b);
    }
    for (int i = 0; i < 25; i++) {
      leds1[i] = CRGB( r, g, b);
    }
    FastLED.show();
    //FastLED.clear();
  }
}
void sunny() {
  for (int i = 0; i < 25; i++) {
    leds[i] = CRGB( 255, 255, 255);
  }
  for (int i = 0; i < 25; i++) {
    leds1[i] = CRGB( 255, 255, 255);
  }
  FastLED.show();
}

void cloudy() {
  for (int i = 0; i < 25; i++) {
    leds[i] = CRGB( 20, 20, 20);
  }
  for (int i = 0; i < 25; i++) {
    leds1[i] = CRGB( 20, 20, 20);
  }
  FastLED.show();
}
