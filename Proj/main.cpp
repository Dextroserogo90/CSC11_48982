/* 
 * File:   main.cpp
 * Author: Deepak Menon
 * Class: CSC-11 (48982)
 * Assignment: Project 1
 * Created on November 8, 2015, 5:52 PM
 */

#include <stdio.h>
#include <cstdlib>
#include <ctime>
#incllude <iomanip>
#include "Guess.h"

using namespace std;
int main(int argc, char *argv[])
{
    
    unsigned int number;
    printf("Guess the correct random number and win the game.\n");
    
    
    srand(time(0));
    int rndnum1 = (rand()% 10);
    int rndnum2 = (rand()% 10);
    int rndnum3 = (rand()% 10);
    int rndnum4 = (rand()% 10);
    
    printf("*-------------------------*");
    printf("     Number mind          ");
    cout<<"--------------------------------
        <<"---########---------------------"
        <<"--#  .   . #--------------------"
        <<"--#    .   #--------------------"
        <<"--#  .   . #--------------------"
        <<"---########----------#########--"
        <<"--------------------#		  #-"
        <<"--------------------#	.  .  #-"
        <<"--------------------#		  #-"
        <<"-------------------- #########--"
        <<"-------------------------------";
        
    printf("\nGuess a number between 1 and 12. The game will also tell if it is too");
    printf("high or low. You'll have 4 tries to get it right.\n");
    
    pattern(rndnum1,status)
    pattern(rndnum2,status)
    pattern(rndnum3,status)
    pattern(rndnum4,status)
          
    if(status == 4){      
    printf("You have won the game.");
    }
    else if (status !=4){
         printf("You lose! Better luck next time.");
         }
    system("PAUSE");
    return 0;
}
