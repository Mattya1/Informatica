# E2 Scrivere un programma Risc-V in grado di leggere da console due valori interi M ed N e verificare se M è maggiore, uguale o minore di N.

.globl main

.macro read_int
	li a7, 5		# directive to read int from console
	ecall
.end_macro

.macro print_int (%x)
	li a7, 1
	mv a0, %x
	ecall
.end_macro

.text
main:

read_int 
mv t0, a0		# M
 
read_int
mv t1, a0		# N

li t2, 0	# t2 = 0

sgt t2, t0, t1	# if M >= N, t2 = 1 ;  else 0
print_int (t2)

li a7, 93
li a1, 0
ecall



