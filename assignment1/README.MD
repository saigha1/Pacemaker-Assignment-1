# Modules
## main.cpp
Includes the main loop for calling the pacing function and reading from serial indefinitely
## clock.cpp
Includes two counters ( Main clock counter, Pace Counter) 

**Might be changed in the future to include history timing and dual chambers implementation**
## serial.cpp
Includes four functions:
### void check_serial(void)
checks for the first part(byte) of the serial packet and returns 1 if found
### string read_serial(void)
reads the serial packet up to the end byte and then returns a string including all the bytes from the packet
### void write_serial(string serial_out)
sends a string out through serial
### void parse_serial(double *params,int data_size)
splits the input packet into an array of type float

**Most likely going to change how the serial input looks like**
## pacing.cpp
Mainly used to generate the output wave through a gpio ouput pin

# Serial
Some conventions for assignment 1 for serial COM
* The serial packet begins with '#' byte
* The serial packet ends with '$' byte
* The serial packet paramaters are split with ','
* For assignment 1 I assumed the serial packet paramters in order split by ',' for Ventricular and Atrial Pacing:  
Chamber ( 0 for Ventricular and 1 for Atrial)
,Pulse width
,Low time ( Time between two highs ), Pin name (0-15) for pins (D0-D15)
* For dual pacing:  
Chamber (2), Ventricular pulse width, Atrial pulse width, Low time, AV delay, Ventricular pin name, Atrial pin name 

**NOTE: THIS NEEDS TO BE CHANGED SOMETIME SOON IF YOU HAVE QUESTIONS MESSAGE ME**  
**NOTE2: THE CODE ISN'T WELL COMMENTED YET**  
**NOTE3: FOR LED LOGIC 1 is FOR LOW AND LOGIC 0 IS FOR HIGH**  
**NOTE4: WHEN YOU DOCUMENT DO NOT CALL IT A SERIAL PACKET JUST CALL IT A SERIAL MESSAGE**  
