#include "Arduino.h"
#include "logging.h"
#include "vibration.h"
#include "ticker.h"

void init_vibration() {
  pinMode(VIBRATION_PIN, INPUT);
}

int read_vibration() {
  int value = digitalRead(VIBRATION_PIN);
  log_value("vibration", value);
  return value;
}

const int VIBRATION_STATE_RESET = INACTIVITY_PERIOD * TICK_PER_SECOND;
int vibration_state = 0;

void check_activity() {
  int vibration = read_vibration();
  if(vibration) {
    vibration_state = VIBRATION_STATE_RESET;
  } else {
    vibration_state = vibration_state > 0 ? vibration_state - 1 : 0;
  }
}

int is_inactive() {
  return vibration_state == 0;
}
