
#define VIBRATION_PIN 2

#ifdef DEBUG
#define INACTIVITY_PERIOD 5
#else
#define INACTIVITY_PERIOD 30
#endif

void init_vibration();
void check_activity();
int is_inactive();
