#include <cstdlib>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[])
{
	_menu:
	unsigned int R0;
	printf("Please select a choice from 1-4 \n"
                "1. Employees Pay \n"
                "2.\n"
                "3.\n"
         	"4 is for exit \n");
	scanf("%d",&R0);
	
	
	if(R0 == 1) goto _first;
	//else if (R0 == 2) goto _second;
	//else if (R0 == 3) goto _third;
	else if (R0 == 4) goto _exit;
	else goto _menu;
	

    //First program
    _first:
    unsigned int R1, R2, R3;
    
    //Prompt
    printf("Enter pay rate per hour: \n");
    scanf("%d",&R1);
    
    printf("Enter hours worked: \n");
    scanf("%d",&R2);
    
	//Conditionals
	if (R2<=40){
		goto _Time;
	}
	else if (40< R2 <=50){
		goto _dtime;
	}
	else if (50 < R2 <=60){
		goto _ttime;
	}
	
    //Calculations
    _Time:
	R3 = (R1*R2);
	goto _foutput;
    _dtime:
	R3 = (R1*40) + ((R2-40)*(2*R1));
	goto _foutput;
    _ttime:
	R3 = (R1*40) + (2 * R1 * 10) + (R2-50)*(3*R1);
	goto _foutput;
     
     _foutput:
     printf("Gross pay: $");
     printf("%d",R3);
     printf("\n");
     goto _menu;
	 
     //User exit
     _exit:
    return 0;
}

//Second program
//_second:
