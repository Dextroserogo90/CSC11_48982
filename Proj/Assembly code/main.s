/* Deepak Menon
   11/8/2015
   CSC-11 (48982)
   Project 1
*/

//Data Main
.data

.balign 4
Prompt1: .asciz "Guess the correct random number and win the game.\n"
.balign 4
dice1: .asciz "*-------------------------*"
.balign 4
dice2: .asciz "---########---------------------"
.balign 4
win: .asciz " "You have won the game."\n"
.balign 4
lose: .asciz "You lose! Better luck next time!\n"


.text
	.global main

main:

	/*Output the greeting*/
	LDR R0, address_of_greeting1
	bl printf

	
	bl randnum//Calls function randnum for numbers
	
	
/* Output the results */
_plose:
ldr r0, address_of_lose
bl printf
b _exit

_pwin:
ldr r0, address_of_win
bl printf
b _exit

b _exit
_exit:
ldr lr, address_of_return 
ldr lr, [lr] 
bx lr

.balign 4
return: .word 0
.balign 4
storeit: .word 0
.balign 4
scan: .asciz "%d"


/* Memeory addresses */
address_of_greeting1: .word Prompt1
address_of_chest1: .word dice1
address_of_lose: .word lose
address_of_win: .word win

//External
.global printf
.global scanf
.global time
.global srand
.global rand