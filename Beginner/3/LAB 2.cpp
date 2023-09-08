#include "mbed.h"

#define BUTTON_1 p5
#define BUTTON_2 p6
#define BUTTON_3 p7
#define BUTTON_4 p8

#define RED_LED p9
#define YELLOW_LED p10
#define BLUE_LED p11


// Define the Input pins
	//Write your code here
DigitalIn b1(BUTTON_1);
DigitalIn b2(BUTTON_2);
DigitalIn b3(BUTTON_3);
DigitalIn b4(BUTTON_4);

//Define the Output pins
	//Write your code here
DigitalOut rled (RED_LED);
DigitalOut yled (YELLOW_LED);
DigitalOut bled (BLUE_LED);
//Define Input/Output buses
	//Write your code here
BusIn buttons(BUTTON_1,BUTTON_2,BUTTON_3,BUTTON_4);
BusOut leds(RED_LED,YELLOW_LED,BLUE_LED);

void ControlLED_DigitalIO ();
void ControlLED_BusIO ();


int main()
{
    while(1) {
        ControlLED_BusIO ();
        wait(0.25);
    }
}

void ControlLED_DigitalIO (){
          //Write your code here
    rled = (!b4&(!b3|b2))|(b4&b3&b2&b1);
    yled = (b4^b3) | (b4&b3&b2&b1);
    bled = b4;
}

void ControlLED_BusIO (){
    //Write your code here
    switch (buttons){
        case 0 ... 3: 
            leds = 0b0001;
            break;
        case 4 ... 5:
            leds = 0b0010;
            break;
        case 6 ... 7:
            leds = 0b0011;
            break;
        case 8 ... 11:
            leds = 0b0110;
            break;
        case 12 ... 14:
            leds = 0b0100;
            break;
        case 15:
            leds = 0b0111;
        default: ;
    }
}
