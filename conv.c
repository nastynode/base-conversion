#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const char *ascii = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/";





int main(int argc, char *argv[]){
	//make sure you only have 2 args
	if(argc!=3){
		printf("%s\n", "You need to enter 2 arguments: a decimal number and a base");
		return 1;
	}

	//vars and basic declarations
	char buf[32];
	int bufpoint = 30;
	buf[31] = 0;
	


	//use atoi("stringtoconvert") to convert str to int
	int val = atoi(argv[1]);
	int base = atoi(argv[2]);
	int temp; //digit placeholder

	//error check base2-64 and 256, if values pass this check then check if they should be maskShift or mod looped
	if(base<2 || (base>64 && base!=256)){
		printf("%s\n", "Error, Please Run again and enter base value from 2-64 or 256");
		return 2;
	}else if(base==2 || base==4 || base==8 || base==16 || base==32 || base==64 || base==256){
		//find #bits to shift ie what power of 2 is the base?
		int arb=base;
		int shift=0;
		while(arb>1){ //shift = (int) log2(base)); //doesnt work well with linux
			arb = arb / 2;
			shift++;
		}
		
		//mask & shift while loop
		while(val>0){
			bufpoint--;
			//mask base-1
			temp = val & (base-1);
			//put digits in buf, if base exceeds ascii chars available, do ip address style 
			if(base==256){
				

				//digit maker				
				while(temp>0){
				
					buf[bufpoint] = ascii[temp%10];			
					//having a hard time figuring out how to get 0s to print
					temp = temp/10;
					bufpoint--;

				}
				
				buf[bufpoint] = '.';
				
				
							
				
				
			}else{
				buf[bufpoint] = ascii[temp];
			}			
			//shift base/2
			val = val >> shift;

		}


	}else{
		int divres;
		//mod loop
		while(val>0){
			bufpoint--;
			temp = val % base; //mod
			//put each digit in buff
			buf[bufpoint] = ascii[temp];

			val = val / base;
		}

	}
	
	
	//final function call should be a single printf of the 32 char buffer
	printf("%s\n", &buf[bufpoint]); //&is adressof operator
	return 0;
}
