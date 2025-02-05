# determina potenza di x finchè 2^x = 128

.globl main
	
.macro print_int (%x)
	li a7, 1	#comando per fare ecall che stampi intero 
	mv a0, %x	#il numero che va stampato
	ecall
.end_macro

.macro exit (%x)
	li a7, 93
	li a0, %x
	ecall
.end_macro

.text
main: 
	addi s0, zero, 1		# s0 = 1 = pow
	add  s1, zero, zero		# s1 = 0 = x
	
	addi t0, zero, 128		#il paragone
	
 while:
 	beq s0, t0, Exit			# se s0 == 128 ESCO
 #else
	slli s0, s0, 1			# pow = pow * 2
	addi s1, s1, 1			# x = x+1
	j while
	
Exit:
	print_int(s1)
	exit (0)
	
	
		