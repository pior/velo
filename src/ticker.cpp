#include "Arduino.h"
#include "ticker.h"

const int TICK_PERIOD = 1000 / TICK_PER_SECOND;
int tick_counter = 0;

void next_tick() {
  delay(TICK_PERIOD);
  tick_counter++;
}

int tick_1s() {
  return tick_counter % 10 == 0;
}


