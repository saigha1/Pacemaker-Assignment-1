#include "clock.h"

Ticker counters_ticker;

double counter = 0;
double pace_counter = 0;

/*Starts the counters*/
int start_clock(void)
{
    counters_ticker.attach(&increment_counters, 0.0001); // Attaches the counting function to a ticker
    return 1;
}

/*Increments the cuonters*/
void increment_counters(void)
{
    counter += 0.0001; // Increments the main counter
    pace_counter += 0.0001; // Increments the pace counter used for pacing
}

/*Returns the pace counter*/
double get_counter(void)
{
    return pace_counter;
}

/*Resets the pace counter*/
void reset_counter(void)
{
    pace_counter = 0;  
}
