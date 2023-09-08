#include "mbed.h"

InterruptIn Adult (p5);
InterruptIn Child (p6);
InterruptIn Fire_alarm (p7);

DigitalOut no_entry (p8);
DigitalOut chair_1 (p9);
DigitalOut chair_2 (p10);
DigitalOut chair_3 (p11);
DigitalOut Wall_clk (p12);
BusOut seating (p13, p14, p15, p16, p17, p18, p19, p20);

int Time_ch1;
int Time_ch2;
int Time_ch3;
int seat;
int adult_no;
int adult_wait;
int child_no;

void adult_ISR(){
    if ((adult_no+child_no+adult_wait)<8){
        adult_no++;
        seat = seat <<1;
        seat = seat|01;
    }else {
        no_entry = 1;
        wait_ms(50);
        no_entry = 0;
    }
}

void child_ISR(){
    if ((adult_no+child_no+adult_wait)<7){
        child_no = child_no+1;
        adult_wait++;
        seat = seat <<2;
        seat = seat|03;
    }else {
        no_entry = 1;
        wait_ms(50);
        no_entry = 0;
    }
}
void fire_ISR(){
    no_entry = 1;
    chair_1=chair_2=chair_3=0;
    while (seat!=0){
        seat=seat>>1;
        seating=seat;
        wait_ms(600);
    }
    adult_no = 0;
    child_no = 0;
    adult_wait = 0;
    wait(500);
    no_entry = 0;
}

int main(){
    Adult.rise(&adult_ISR);
    Child.rise(&child_ISR); 
    Fire_alarm.rise(&fire_ISR); 
    
    while(1){
        if (chair_1==1){
            Time_ch1--;
            if (Time_ch1==0){
                chair_1 = 0;
            }
        }else if (adult_no !=0){
            chair_1 = 1;
            adult_no--;
            seat=seat>>1;
            Time_ch1 = 12;
        }
        if (chair_2==1){
            Time_ch2--;
            if (Time_ch2==0){
                chair_2 = 0;
            }
        }else if (adult_no !=0){
            chair_2 = 1;
            adult_no--;
            seat=seat>>1;
            Time_ch2 = 12;
        }
        if (chair_3==1){
            Time_ch3--;
            if (Time_ch3==0){
                chair_3=0;
            }
        }else if (child_no!=0){
            chair_3 = 1;
            child_no--;
            seat=seat>>1;
            Time_ch3 = 12;
            if(Time_ch3==0){
                adult_wait--;
                seat = seat>>2;
                seating = seat;
            }
        }
        seating=seat;
        wait_ms(1000);
        Wall_clk!=Wall_clk;
    }
}

