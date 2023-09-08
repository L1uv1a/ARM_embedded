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

//Define ISRs for the interrupts
void button_1_handler(){
	
	//Write your code here
	rled = !rled;
	
}

void button_2_handler(){
	
	//Write your code here
	yled = !yled;
}

void button_3_handler(){
	
	//Write your code here
	bled = !bled;
}

void button_4_handler(){
	
	//Write your code here
	rled = 1;
	yled = 1;
	bled = 1;
}

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
		
	//Initially turn off all LEDs
    rled = 0;
    yled = 0;
    bled = 0;
	//Write your code here

	//Interrupt handlers
	
	//Attach the address of the ISR to the rising edge
	
	//Write your code here
	button_1.rise(&button_1_handler);
	button_2.rise(&button_2_handler);
	button_3.rise(&button_3_handler);
	button_4.rise(&button_4_handler);
	//wait 100 ms
	while(1)
		wait_ms(100);
}

