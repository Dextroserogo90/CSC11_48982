#include <cstdlib>
#include <iostream>
#include <stdio.h>



using namespace std;

void emp_pay();
void isp();
void fib();


int main(int argc, char *argv[])
{
	_menu:
	unsigned int R0;
	printf("Please select a choice from 1-4 \n"
                "1. Employees Pay \n"
                "2. ISP packages and fees \n"
                "3. Fibonacci sequence \n"
         	"4  Exit \n");
	scanf("%d",&R0);
	
	
	if(R0 == 1) {emp_pay();goto _menu;}
	else if (R0 == 2) {isp();goto _menu;}
	else if (R0 == 3) {fib();goto _menu;}
	else if (R0 == 4) {goto _exit;}
	else goto _menu;
	
        
    //User exit
     _exit:
    return 0;
}

void emp_pay(){
    //First program
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
}

void isp(){
_second:
//Second program
//Customer's variables

char R1;
unsigned int R2 = 0;
unsigned int R3 = 0, temp1,temp2;

//Prompt user for the package
printf("Enter the package you have subscribed to \n"
"(a). $30 per month, 11 hours access.\n"
"(b). $35 per month, 22 hours access.\n"
"(c). $40 per month, 33 hours access.\n");
cin>>R1;

printf("Enter the number of hours watched: \n");
scanf("%d",&R2);

if(R1 == 'a'){
    goto _package1;
}
else if(R1 == 'b'){
    goto _package2;
}
else if (R1 == 'c'){
    goto _package3;
}
else goto _second;

_package1:
R3 = 30;

if(11<R2<=22){
    R3+=(R2-11)*3;
}
else if(22<R2){
    R3+=(3*11)+(R2-22)*6;
}
goto _output;


_package2:
R3=35;

if(22<R2<=44){
    R3+=(R2-22)*2;
}
else if(44<R2){
    temp1= (22*2);
    temp2 = 35 + ((R2-44)*4);   
    R3 = temp1 + temp2;       
}
goto _output;


_package3:
R3=40;
if(33<R2<=66){
    R3+=(R2-33)*1;
}
else if(66<=R2){
    temp1 = 33*1;
    temp2 = R2-66*2;
    R3=temp1 + temp2;
}
goto _output;

_output:
//Outputs for monthly charges
printf("The monthly charges with the fees: $");
printf("%d",R3);  
cout<<endl;
}

void fib(){
//Declare variables

unsigned int R0=0; //Input
unsigned int R1=1; //Output at the number
unsigned int R2=1; //Starting point
unsigned int R3 = 0;

printf("Enter the term that you would like to get the Fibonnacci sequence of: \n");
cin>>R3;

_theloop:
R0= R1 + R2;
R1 = R2;
R2 = R0;
R3--;
if (R3 > 2) {
    cout<<R0<<endl;
}else{
    cout<<R0<<"<--- This is your last term\n";
}
if(R3!=2)goto _theloop;




//output
//printf("%d",R0);
//cout<<endl;
}