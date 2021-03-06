/*Deepak Menon
Purpose: Demonstrate Fibonacci using recursion function*/

.data
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
add r0, r0, #2


_stop:
pop {r2,lr}
bx lr



main:

push {r4,lr}

ldr R0, address_of_message1
bl printf

ldr R0, format_of_answer
ldr R1, sequence_number
bl scanf


ldr r0, sequence_number
ldr r0, [r0]
ldr R1, fib_number
ldr R1, [R1]
bl recursion


ldr R0, address_of_output
bl printf

pop {r4,lr}
bx lr

address_of_message1: .word message1
format_of_answer: .word format 
sequence_number: .word sequence
fib_number: .word fib
address_of_output: .word output


/* External */
.global printf
.global scanf
