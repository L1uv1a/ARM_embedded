#include "mbed.h"

#define BUTTON_1 p5
#define BUTTON_2 p6 
#define BUTTON_3 p7 
#define BUTTON_4 p8 

#define RED_LED p9
#define YELLOW_LED p10
#define BLUE_LED p11

//Define outputs

	//Write your code here
DigitalOut rled(RED_LED);
DigitalOut yled(YELLOW_LED);
DigitalOut bled(BLUE_LED);

//Define interrupt inputs

	//Write your code here
InterruptIn button_1 (BUTTON_1);
InterruptIn button_2 (BUTTON_2);
InterruptIn button_3 (BUTTON_3);
InterruptIn button_4 (BUTTON_4);

//Define counters
volatile unsigned int count_red;
volatile unsigned int count_yellow;
volatile unsigned int count_blue;
volatile unsigned int count_max;

    //Write your code here

void updateLEDs(){
    //Write your code here
    rled = 0;
    yled = 0;
    bled = 0;
    if (count_red==count_max) rled = 1;
    if (count_yellow==count_max) yled = 1;
    if (count_blue==count_max) bled = 1;
    
}


//Define ISRs for the interrupts
void button_1_handler(){
	
	//Write your code here
	count_red++;
	if(count_red>count_max) count_max = count_red;
	updateLEDs();
}

void button_2_handler(){
	
	//Write your code here
	count_yellow++;
	if(count_yellow>count_max) count_max = count_yellow;
	updateLEDs();
}

void button_3_handler(){
	
	//Write your code here
	count_blue++;
	if(count_blue>count_max) count_max = count_blue;
	updateLEDs();
}

void button_4_handler(){
	
	rled = 0;
	yled = 0;
	bled = 0;
	count_red = 0;
	count_yellow = 0;
	count_blue = 0;
	count_max = 0;
	//Write your code here
	
}

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
		
	//Initially turn off all LEDs and set all the counters to 0
	
	//Write your code here
    button_4_handler();
	//Interrupt handlers
	
	//Write your code here
    button_1.rise(&button_1_handler);
    button_2.rise(&button_2_handler);
    button_3.rise(&button_3_handler);
    button_4.rise(&button_4_handler);
	//wait 100 ms
	while(1)
		wait_ms(100);
}
