#include<wiringPi.h>
#include<softTone.h>
#include<stdio.h>

#define PIN_18 18
#define PIN_21 21

int main(){
	if(wiringPiSetupGpio()==-1){
		return 1;
	}
	pinMode(PIN_18,INPUT);
	softToneCreate(PIN_21);
	
	while(1){
		if(LOW==digitalRead(PIN_18)){
			printf("detect\n");
			while(LOW==digitalRead(PIN_18)){
				softToneWrite(PIN_21,300);
				delay(300);
				softToneWrite(PIN_21,400);
				delay(300);
			}
		}
		else{
			softToneWrite(PIN_21,0);
			delay(300);
		
		}
	}
	return 0;
	
}
