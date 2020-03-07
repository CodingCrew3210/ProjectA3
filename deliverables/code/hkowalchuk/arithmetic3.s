@ arithmetic3
@ Hayden Kowalchuk (c) 2020
@ Coding Crew GSU
@ Goal: This program does some arithmetic statements on variables and stores the result in a register

.section .data
val1:  byte -60	@ 8-bit signed integer
val2:	.byte 11	@ 8-bit signed integer
val3:	.byte 16	@ 8-bit unsigned integer

.section .text
.globl _start
_start:

  eor r5, r5		  @ zero out r5

  ldr r1, =val1		@ move val1 into r1 as a 32bit sign extended byte
  ldrsb r1, [r1]

  ldr r2, =val2		@ move val2 into r2 as a 32bit sign extended byte
  ldrsb r2, [r2]

  ldr r3, =val3		@ move val3 into r3 as a 32bit zero extended byte
  ldrb r3, [r3]

  add r5, r2, #3 	@ r5 = (val2 + 3)		  = (11+3) 	= 14
  add r5, r5, r3	@ r5 = (val2 + 3) + val3	  = (14+16)	= 30
  sub r5, r5, r1	@ r5 = ((val2 + 3) + val3) - val1 = (30 - (-60))= 90

@ r5 which is the gp reg i chose contains 0x5a, or decimal 90
@ the negative flag is cleared because 90 is positive

  mov r5, r5		@ NOP for debugging

  mov r7, #1            @ Program Termination: exit syscall
  svc #0                @ Program Termination: wake kernel
.end
