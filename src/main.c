#include "true.h"

void main(){
    
    CLK_DIV = 0;// Main clock no DIV
    P0M1 = 0; P0M0 = 0xff; // push-pull output
	P1M1 = 0; P1M0 = 0;
	P2M1 = 0; P2M0 = 0xff; // output
	P3M1 = 0; P3M0 = 0; //full compatip 8051
	P4M1 = 0; P4M0 = 0;//full compatip 8051
	P41INPUT;
	P42OUTPUT;
	P43OUTPUT;
	P44OUTPUT;
	P5M1 = P5M0 = 0; // full compatip 8051
	P4 = 0;
	P3 = 0xff;
	P0 = P2 = 0;
    while(1);
}