#include "mbed.h"

// Define the PWM speaker output
PwmOut speaker(p21);
DigitalOut led(p5);

// Define analog inputs
AnalogIn temperature(p15);
AnalogIn level(p16);
//Write your code here

//Define variables
float i;
float hival;
float lowval;

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/
int main(){
    while(1){
        speaker = 0.5;
        while(level.read()<0.75){
            led!=led;
            for (i=0.0; i<1; i+=0.05){
                speaker.period(0.01-0.008*i);
            }
        }
        led = 0;
        if (temperature.read()<(1/3)){
            hival = 0.005;
            lowval = 1;
        }
        if(temperature.read()>(2/3)){
            hival = 0.001;
            lowval = 0.005;
        }
        if ((temperature.read()>(1/3))&&(temperature.read()<(2/3))){
            hival = 0.002;
            lowval = 0.002;
        }
        // Create a saw-tooth sound wave
        speaker.period(hival);
        wait_ms(500);
        speaker.period(lowval);
        wait_ms(500);
        // Make the period and volume adjustable using the potentiometers
    }
}
