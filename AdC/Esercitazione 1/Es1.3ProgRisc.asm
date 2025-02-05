# E3 Scrivere un programma Risc-V in grado di leggere da console un valore intero K e controllare che K sia incluso tra 1 e 10

.globl main

.data
A:	.string "K incluso tra 1 e 10"
B: 	.string "K out of bounds"	

.macro read_int
	li a7, 5
	ecall
.end_macro

.macro print_int (%x)
	li a7, 1
	mv a0, %x
	ecall
.end_macro

.macro print_string (%s)
	li a7, 4
	mv a0, %s
	ecall
.end_macro

.macro exit
	li a7, 10
	ecall
.end_macro

.text 
main:
	addi t1, zero, 1		# 1 in t1
	addi t2, zero, 10	# 10 in t2
	
	la t3, A			# add di A in t3 
	la t4, B			# add di B in t4
	
	read_int
	mv t0, a0			# K in t0
	
if:
	bgt t0, t2, End		# if k > 10
	
	blt t0, t1, End		# if k <1
	print_string (t3)		# K in bounds
	exit
	
End:
	print_string(t4)		# K OoB
	exit
	
	
	
	
	
	
