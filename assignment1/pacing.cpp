#include "pacing.h"

PinName atrial_pin;
PinName ventricular_pin; 
double v_pulsewidth = 0; // Ventricular pulse width
double a_pulsewidth = 0; // Atrial pulse width
double low_time = 0; // Time when there is no pacing
double av_delay=0; // AV Delay

/*Function that generates the pace wave*/
void generate_pace(char chamber)
{
    if (chamber == 'v') // Ventricular pacing
    {
         if (get_counter() > (v_pulsewidth + low_time))
        {
            reset_counter();
        }
        if (get_counter() <= low_time)
        {
            gpio_output(chamber, 0);
        }
        else
        {
            gpio_output(chamber, 1);
        }   
    }
    
    else if (chamber == 'a') // Atrial pacing
    {
         if (get_counter() > (a_pulsewidth + low_time))
        {
            reset_counter();
        }
        if (get_counter() <= low_time)
        {
            gpio_output(chamber, 0);
        }
        else
        {
            gpio_output(chamber, 1);
            
        }   
    }
    
    else if (chamber == 'd') //Dual Chamber pacing
    {
        if (get_counter() > (v_pulsewidth + av_delay + a_pulsewidth + low_time))
        {
            reset_counter();
        }
        if (get_counter() <= low_time)
        {
            reset_gpio();
        }
        else if (get_counter() <= (low_time + a_pulsewidth))
        {
            gpio_output('a', 1);
        }
        else if (get_counter() <= (low_time + a_pulsewidth + av_delay))
        {
            gpio_output('a', 0);    
        }
        else if (get_counter() <= (low_time + a_pulsewidth + av_delay + v_pulsewidth))
        {
            gpio_output('v', 1);    
        }
        else
        {
        }
        
    }
}  

/*Writes logic to a gpio pin*/
void gpio_output(char chamber, int logic)
{
    DigitalOut(get_pin(chamber), logic);
}

PinName get_pin(char chamber)
{
    if (chamber == 'a')
    {
        return atrial_pin;
    }
    else if (chamber == 'v')
    {
        return ventricular_pin;
    }
    return LED1;
}

/*Sets the chamber's output pin*/
void set_pin(char chamber, PinName pin)
{
    if (chamber == 'a')
    {
        atrial_pin = pin;
    }
    else if (chamber == 'v')
    {
        ventricular_pin = pin;
    }
}

/*Sets the pulse width for the pace*/
void set_pulsewidth(double width, char chamber)
{
    if (chamber == 'v')
    {
        v_pulsewidth = width;    
    }
    else if (chamber == 'a')
    {
        a_pulsewidth = width;    
    }
    
}

/*Sets AV Delay value*/
void set_avdelay(double delay)
{
    av_delay = delay;    
}

/*Sets the time period when there is no pacing*/
void set_lowtime(double time)
{
    low_time = time;
}

/*Writes zero to the two chambers' gpio pins*/
void reset_gpio(void)
{
    gpio_output('v', 0);
    gpio_output('a', 0);
}