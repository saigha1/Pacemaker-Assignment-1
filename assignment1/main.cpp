#include "main.h"

char chamber;
double params[7];
PinName pins[16] = {D0, D1, D2, D3, D4,
                    D5, D6, D7, D8, D9,
                    D10, D11, D12, D13,
                    D14, D15};

/*Temporary function to avoid duplicating*/
void handy_serial(void)
{
    reset_counter();
    reset_gpio();
    parse_serial(params, 7);
    if (params[0] == 0)
    {
        chamber = 'v';
        set_pin('v', pins[int(params[3])]);
        set_pulsewidth(params[1], chamber);
        set_lowtime(params[2]);
    }
    else if (params[0] == 1)
    {
        chamber = 'a';
        set_pin('a', pins[int(params[3])]);
        set_pulsewidth(params[1], chamber);
        set_lowtime(params[2]);
    }
    else if (params[0] == 2)
    {
     chamber = 'd';
     set_pin('v', pins[int(params[5])]);
     set_pulsewidth(params[1], 'v');
     set_pin('a', pins[int(params[6])]);   
     set_pulsewidth(params[2], 'a');
     set_lowtime(params[3]);
     set_avdelay(params[4]);
    }
}


int main(void)
{
    start_clock();
    while(!check_serial()){}
    handy_serial();
    
    while(1)
    {
        generate_pace(chamber);
        if(check_serial())
        {
         handy_serial();   
        }
    
    }

}
