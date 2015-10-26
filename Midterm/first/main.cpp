#include <cstdlib>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[])
{
    int R1, R2, R3;
    
    //Prompt
    printf("Enter pay rate per hour: \n");
    scanf("%d",&R1);
    
    printf("Enter hours worked: \n");
    scanf("%d",&R2);
    
    //Calculations
    if(R2<=40){
                R3 = R1 * R2;
                }
     else if(40<R2<=50){
                R3 = R1 * R2;
                }
     else if(50<R2<=60){
                R3 = R1 * R2;
                }
                
      else goto _exit;
     
     printf("Gross pay: \n");
     cout << R3 <<endl;
     
     //User exit
     _exit:
    return EXIT_SUCCESS;
}
