# fattoriale con ricorsione!!!

.globl main

.data

msg1: .asciz "factorial: " 
msg2: .asciz "numb: " 


.macro read_int (%x)
 	li a7, 4
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

.macro exit (%x)
	li a7, 93
	mv a0, %x
	ecall
.end_macro

.text
main:
	li a0, 6		# voglio il fact di 6
	li t1, 1		# tengo 1 per controllo del numero più avanti
	la t0, msg2 
	print_string (t0)
	print_int(a0)
	jal factorial
	
	li t1, 0
	la t0, msg1
	print_string (t0)
	print_int(a0)
	exit(t1)
	
factorial:
	bgt a0, t1, Else	# controllo che a0 sia > 1
	li a0, 1		# caso base
	ret
	
Else: # ovvero tutti i cicli fino a quando n > 1
	addi sp, sp, -8	# alloco spazio nello stack
	sw a0, 0(sp)	# salvo il valore originale di n
	sw ra, 4(sp) 	# salvo l'indirizzo del ra per il main
	
	# n * fact(n-1)
	addi a0, a0, -1	# n-1
	jal factorial
	
	