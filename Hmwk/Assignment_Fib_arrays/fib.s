/*
Deepak Menon
Purpose: To do Fibonacci series using Arrays
*/

//Greetings and ask user
.data
.balign 4
greeting1: .asciz "Enter term for Fibonacci: "
.balign 4
result: .asciz "\nInput is %d Output is %d\n"

/*Now scanf and printf*/
.balign 4
scan: .asciz "%d"

.balign 4
read: .word 0

.balign 4
array: .skip 180 //int 45 planes * 4 bytes, so 180

.text
	.global main

main:

push {R2,lr}



/* Gets input here */
	LDR R0, address_of_greeting1 //Asks user for input
	bl printf

	LDR R0, address_of_scan
	LDR R1, address_of_read //Input heree
	bl scanf

	LDR R1, address_of_read
	LDR R1, [R1]

LDR R7, address_of_array //Address of array into R7

/*Looping, and skipping here */

CMP R1, #45
	BGT exceed

/*Fibonacci calculation*/

recursion:
cmp r0, #2
bgt _one
mov r1,#1

_one:

sub r0,r0, #1
bl recursion
mov r2, r1 
sub r0,r0,#1
bl recursion
add r1, r1, r2 
str r1, [r3], #+4
add r0, r0, #2

bl disResult // Print outs result at end

//Here lies code for looping in the array
Setup:
	MOV R3, R1 //R1 changes
	MOV R1, R1, LSL#2 //moves 4 bytes

calArrFib:
	ADD R9, R9, #4 //R9 += 4 counter for loop and to set array
	LDR R4, [R7, +R9]
	CMP R9, R1
		BLE calArrFib
	bl disResult

//Outupts here
exceed:
	MOV R2, #0

	LDR R0, address_of_result
        bl printf

	bl _exit


disResult:
	MOV R2, R4 

	LDR R0, address_of_result
	bl printf

_exit:

	pop {r2, lr}
	bx lr

address_of_greeting1: .word greeting1
address_of_result: .word result
address_of_scan: .word scan
address_of_read: .word read
address_of_array: .word array


.global printf
.global scanf

