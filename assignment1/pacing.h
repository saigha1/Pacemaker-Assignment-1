#include "mbed.h"
#include "clock.h"
#include <string>

void generate_pace(char chamber);
void gpio_output(char chamber, int logic);
PinName get_pin(char chamber);
void set_pin(char chamber, PinName pin);
void set_pulsewidth(double width, char chamber);
void set_avdelay(double delay);
void set_lowtime(double time);
void reset_gpio(void);

