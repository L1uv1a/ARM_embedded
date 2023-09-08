#include "mbed.h"

#define SPEAKER p21
#define AIN1 p15
#define AIN2 p16

// Define the PWM speaker output
PwmOut speaker(SPEAKER);
// Define analog inputs
AnalogIn pot1(AIN1);
AnalogIn pot2(AIN2);
//Write your code here

//Define variables
float i;
float val_pot1;
float val_pot2;

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/
int main(){
    while(1){
        val_pot1 = pot1.read();
        val_pot2 = pot2.read();
        // Create a saw-tooth sound wave
        // Make the period and volume adjustable using the potentiometers
        for (i=0.0; i<1; i+= 0.05){
            speaker.period(0.003125-0.02*val_pot1);
            speaker = i*0.05*val_pot2;
        }
        wait_ms(100);
    }
}