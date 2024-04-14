#include <avr/io.h>

int main(void){
    
	//PA7 is blue LED
	PORTA_DIRSET = (1<<7); //set to output
	PORTA_OUTSET = (1<<7); // set HIGH;
	
    while (1) 
    {
		
    }
}