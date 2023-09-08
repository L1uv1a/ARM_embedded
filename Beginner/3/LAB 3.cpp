#include "mbed.h"


// Define the Input pins 
DigitalIn  START(p5); //Start control, start = 1 
DigitalIn  STOP(p6); //Machine guard sensor; guard closed = 1 
DigitalIn  GUARD(p7);//Temperature sensor; excess temp = 1 
DigitalIn  TEMP(p8); //Stop control, stop = 1 

//Define the Output pins 
DigitalOut READY(p9);//Motor is ready to run, i.e. guard closed, temp OK. 
DigitalOut RUNNING(p10); //Motor is running 
DigitalOut FAULT(p11); //Guard is openend while motor running 
DigitalOut EXCESS(p12); //Excess temp 

int main()
{
    while(1) {
        while ((GUARD==0)||(TEMP==1)){
            RUNNING = 0;
            FAULT = 0;
            EXCESS = 0;
            READY =!READY;
            wait(0.2);
        }
        READY = 1;
        while (START==0){
            wait(0.01);
        }
            while ((GUARD==1)&&(TEMP==0)&&(STOP==0)){
            READY = 0;
            RUNNING = 1;
            wait(0.2);
            if (GUARD==0){
                RUNNING = 0;
                FAULT = 1;
                wait(0.5);
                FAULT = 0;
            }
            if(TEMP==1){
                RUNNING = 0;
                EXCESS = 1;
                wait(0.5);
                EXCESS = 0;
            }
            if(STOP==1){
                RUNNING = 0;
            }
        }
    }
}


