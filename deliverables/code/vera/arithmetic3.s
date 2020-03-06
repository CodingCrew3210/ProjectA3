.section .data
val1: .byte -60			@8-bit signed integer
val2: .byte 11			@8-bit signed integer
val3: .byte 16			@8-bit unsigned integer
.section .text 
.globl _start
_start:
ldr r1, =val1			@load the memory address of val1 into r1
ldrsb r1, [r1]			@load the value val1 into r1
ldr r2, =val2			@load the memory address of val2 into r2
ldrsb r2, [r2]			@load the value val2 into r2
ldr r3, =val3			@load the memory address of val3 into r3
ldrb r3, [r3]			@load the value val3 into r3
add r2, r2, #3			@add 3 to r2 and store into r2
add r2, r2, r3			@add r2 to r1 and store into r2
sub r2, r2, r1			@subtract r1 from r2 and store into r2
mov r7, #1			@Program Termination:exit syscall
svc #0				@Program Termination:wake kernel
.end   


