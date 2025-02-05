# E1 Scrivere un programma Risc-V in grado di leggere due numeri interi da console e stampare sempre su console il risultato della loro somma.

.globl main

.macro read_int
	li a7, 5	# directive to read int from console
	ecall	# int will go in a0
.end_macro

.macro print_int (%x)
	li a7, 1	# directive to print an int
	mv a0, %x
	ecall
.end_macro

  
.text
main:

read_int
mv t0, a0		# first int in t0

read_int
mv t1, a0		# second int in t1

add t0, t0, t1  # t0 = t0 + t1

print_int (t0)

li a7, 93
li a0, 0
ecall

