#include "mbed.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>

int check_serial(void);
string read_serial(void);
void write_serial(string serial_out);
void parse_serial(double *params, int data_size); 


