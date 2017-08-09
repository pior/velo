/*

Feature: auto-on/off
Vibration sensor inform whether the bike is moving.
Sensor can wake the system up by interruption.
System can detect the bike is not moving anymore : no vibration for XX seconds

Feature: light sensing
Day/Dawn/Night

*/

#include "Arduino.h"

#include "FastLED.h"

#include "light.h"
#include "logging.h"
#include "pitches.h"
#include "ticker.h"
#include "vibration.h"

#ifdef DEBUG
#define SETUP_BEEP tone(BUZZER_PIN, NOTE_G6, 600);
#else
#define SETUP_BEEP tone(BUZZER_PIN, NOTE_G6, 150);
#endif

#define BUILTIN_LED_SETUP pinMode(LED_BUILTIN, OUTPUT);
#define BUILTIN_LED_ON digitalWrite(LED_BUILTIN, HIGH);
#define BUILTIN_LED_OFF digitalWrite(LED_BUILTIN, LOW);

#define LIGHT_ANALOG_PIN 0
#define LIGHT_ENABLE_PIN 7

#define BUZZER_PIN 9


void setup() {
  BUILTIN_LED_SETUP
  BUILTIN_LED_ON

  DEBUG_INIT

  init_vibration();

  init_light();

  SETUP_BEEP

  BUILTIN_LED_OFF
}

//---------------------------------------------

int read_light() {
  pinMode(LIGHT_ENABLE_PIN, OUTPUT);
  digitalWrite(LIGHT_ENABLE_PIN, HIGH);
  int value = analogRead(LIGHT_ANALOG_PIN);
  pinMode(LIGHT_ENABLE_PIN, INPUT);

  log_value("light", value);
  return value;
}

//---------------------------------------------


void loop() {
  check_activity();

  if(tick_1s()) {

    if(is_inactive()) {
      // GO TO SLEEP
      FastLED.show(0);
    } else {
      FastLED.show(255);
    }

  }

  next_tick();
}
