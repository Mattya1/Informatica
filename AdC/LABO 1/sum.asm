# esercizio su somma

.globl main

.eqv  DIM 10

.data 
 V: .word 1,2,3,4,5,6,7,8,9,10
 b: .string "The sum is " 

.macro exit (%x)
	li a7, 93
	li a0, %x
	ecall
.end_macro

 .macro print_str (%x)
	li a7, 4
	la a0, %x
	ecall
.end_macro
 
.macro print_int (%x)
	li a7, 1
	mv a0, %x
	ecall
.end_macro

.macro print (%x)
	print_str(b)
	print_int(%x)
.end_macro


.text
	main:
	
	la a1, V		# a1 = V[0]
	li t0, 0		# i = 0
	li t1, 0		# acc = 0
	li t2, DIM		# 10

	
	for:
		beq t0, t2, end			# if i == 10
		slli t3, t0, 2			# t3 contiene offset = i*4
		add t4, a1, t3			# t4 = indirizzo di V + offset
		lw t5, 0(t4)			# v[i] 
		add t1, t1, t5			# acc += v[i]
		addi t0, t0, 1			#i+1			 
		
		j for	
		
	end:
	mv  s0, t1
	
	print(s0)
	
	exit(0)
	
	