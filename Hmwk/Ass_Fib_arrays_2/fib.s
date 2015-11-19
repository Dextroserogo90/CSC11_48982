/*Amul Bham
Purpose: Demonstrate fibbonacci using recursion function*/

.data
.balign 4
arr: .skip 180

/*address of text to be displayed*/
.balign 4
message1: .asciz "Which term of the Fibonacci Sequence would you like to see? \n"

/*address of the number the user would like to see*/
.balign 4
sequence: .word 0

/*Set the format of the scan f and printf*/
.balign 4
format: .asciz "%d"

/*address of the fib number*/
.balign 4
fib: .word 0

/*Address for output*/
.balign 4
output: .asciz "%d\n"

.text
.global main

ldr r7, address_of_arr

//Here lies code for looping in the array
Setup:
push {r1, lr}
	LDR R7, [R7, +R9]
	ADD R9, R9, #4 //R9 += 4 counter for loop and to set array
	str R1, R7
	
	pop{r1, lr}
	bx lr

recursion:
push {r2,lr}
cmp r0, #2
bgt _one
mov r1,#1
b _stop

_one:

sub r0,r0, #1
bl recursion
mov r2, r1 
sub r0,r0,#1
bl recursion
add r1, r1, r2  
bl Setup
add r0, r0, #2

_stop:
pop {r2,lr}
bx lr

main:

push {r4,lr}
MOV R8, #0 

ldr R0, address_of_message1
bl printf

ldr R0, format_of_answer
ldr R1, sequence_number
bl scanf

mov r6, r1
mov r7,#0

ldr r3, address_of_arr
mov r2, #0
str r2, [r3], #+4
add r2, r2, #1
str r2, [r3], #+8

ldr r0, sequence_number
ldr r0, [r0]
ldr R1, fib_number
ldr R1, [R1]
bl recursion

/*
CMP R0, R4
ADD R1, #4
MOV R4, #1
ldr R0, address_of_output
bl printf

pop {r4,lr}
bx lr
*/

	
	
address_of_message1: .word message1
format_of_answer: .word format 
sequence_number: .word sequence
fib_number: .word fib
address_of_output: .word output
address_of_arr: .word arr

/* External */
.global printf
.global scanf
