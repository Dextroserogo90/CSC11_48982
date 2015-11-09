.data
.balign 4
Prompt1: .asciz "\nThe INPUT is too HIGH.\n"
.balign 4
askGuess: .asciz "User Input: "

.balign 4
input: .asciz "%d"

//Execution begins here

.text

	.global guess
guess:
	LDR R1, address_of_returnG
	STR LR, [R1]



	MOV R7, #0 //Counts loops till 5
	LDR R0, address_of_askGuess
	bl printf
	
	bl randnum 
	

	//scan
	LDR R0, address_of_scanG
	LDR R1, address_of_input
	bl scanf
	
	ADD R7, R7, #1
	
	LDR R0, address_of_input
	LDR R0, [R0]
	MOV R9, R0
	
	CMP R9, R10
		BEQ same
		BLT less
		BGT greater
		
		
	_exitGame:
	LDR LR, address_of_returnG
	LDR LR, [LR]
	BX LR
	
	same:
	LDR R0, address_of_cInput
	bl printf
	MOV R8, #169 //status
	bl _exitGame

	less:
	LDR R1, address_of_input
	LDR R1, [R1]
	LDR R0, address_of_disLes
	bl printf
	ADD R5, R5, #1
	bl _exitGame

	greater:
	LDR R1, address_of_input
	LDR R1, [R1]
	LDR R0, address_of_disGrt
	bl printf
	ADD R5, R5, #1
	bl _exitGame

address_of_Prompt1: .word Prompt1
address_of_askGuess: .word askGuess
address_of_scanG: .word scanG
address_of_returnG: .word returnG
address_of_input: .word input

//External
.global printf
.global scanf
.global time
.global srand
.global rand