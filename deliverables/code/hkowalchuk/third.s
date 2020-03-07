@ third
@ Hayden Kowalchuk (c) 2020
@ Coding Crew GSU
@ Goal: This program does explores how we store and access half-words/shorts in ARM assembly

.section .data
a: 	.short -2 	@ 16-bit signed integer

@  Error: unknown psuedo-op: `.shalfword`, this is becuase this is not the correct designation for this type
@ Needs to be changed to "short" to indicate a signed 16 bit width integer

.section .text
.globl _start
_start:

@ The following is a simple ARM code example that attempts to load a set of
@ values into registers and it might have problems.

mov r0, #0x1 		      @ = 1
mov r1, #0xFFFFFFFF 	@ = -1 (signed)
mov r2, #0xFF 		    @ = 255
mov r3, #0x101 		    @ = 257
mov r4, #0x400 		    @ = 1024
mov r7, #1 		        @ Program Termination: exit syscall
svc #0 			          @ Program Termination: wake kernel
.end

@ GDB:
@ get the address of a:
@	p &a = 0x20090
@	x/1xh 0x20090 print the data located at 0x20090 as a single halfword in hex, 0xfffe = -2 in base 10 signed decimal
@	x/1xsh 0x20090 prints the data located at 0x20090 as a string and also as hex, prints 0xfffe and garbage since 0xff and 0xfe arent typical ASCII characters

