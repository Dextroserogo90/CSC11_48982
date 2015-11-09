/* 
 * File:   Guess.h
 * Author: Deepak Menon
 *
 * Created on November 8, 2015, 7:57 PM
 */

#ifndef GUESS_H
#define	GUESS_H
#include <stdio.h>

using namespace std;

int pattern(int rndnumber, int status){
for(int i = 0; i <= 5; i++){
        
            printf("\nRand = %d\n", gBonusRndNum);
            printf("User Input: ");
            scanf("%d", &number);
        
            if(number > rndnum){
                printf("The INPUT is too HIGH.\n");
            }else if(number < rndnum){
                printf("The INPUT is too LOW.\n");
            }else if(number == rndnum){
                printf("\nYou've guessed correctly!\n You have won the game");
				status =1;
                goto STOPnum;
            }   
	
	return status;}
	
#endif