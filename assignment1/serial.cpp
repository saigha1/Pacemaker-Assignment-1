#include "serial.h"

Serial pc(USBTX, USBRX); // Define serial port

/*Checks for the start*/
int check_serial(void)
{
    char p; 
    if (pc.readable()>0){
    p = pc.getc(); // Reads a byte from serial 

    if (p == '#') // Checks for the first byte (Beginning of a single)
    {
        return 1;
    }
    
    }
    return 0;
}

/*Reads the serial packet until the end byte '$'*/
string read_serial(void)
{
    char p;
    string serial_in = "";
    
    p = pc.getc();
    while (p != '$')
    {
        serial_in += p;
        p = pc.getc();
    }
    return serial_in;
}

/*Sends a serial packet*/
void write_serial(string serial_out)
{
    pc.printf(serial_out.c_str());
}

/*Parses serial packet and sets the paramaters*/
void parse_serial(double *params, int data_size)    
{
    string data_stream = read_serial();
    std::string input = data_stream;
    std::istringstream ss(input);
    std::string token;
    for(int i = 0; i < data_size; i++)
    {
        std::getline(ss, token, ',');
        params[i] = atof(token.c_str()); // converts string to float
    }
}



