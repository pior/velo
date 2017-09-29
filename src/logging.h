#ifndef LOGGING_H
#define LOGGING_H

#ifdef DEBUG
#define DEBUG_INIT Serial.begin(9600); Serial.println("Debug logs activated");
#define log(name) Serial.println(msg);
#define log_value(name, value) Serial.print(name); Serial.print(": "); Serial.println(value);

#else
#define DEBUG_INIT
#define log(name)
#define log_value(name, value)

#endif

#endif // LOGGING_H
