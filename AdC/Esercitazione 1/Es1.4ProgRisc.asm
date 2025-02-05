# E4 Scrivere un programma RIsc-V in grado di leggere da console un valore intero K, controllare che K sia incluso tra 1 e 10, 
# leggere quindi K valori interi da console e, infine, stampare sempre su console la somma dei valori letti.

.globl main

.macro read_int
	li a7, 5
	ecall
.end_macro

.macro print_int(%x)
	li a7, 1
	mv a0, %x
	ecall
.end_macro

.text 
	main:
		li t1, 10
	
		read_int
		mv t0, a0			# sposto int in t0
		
		bge t0, t1, exit		# k > 10
		li t1, 1
		blt t0, t1, exit		# k < 1
		
		li t1, 0			# t1 = i
		li t2, 0			# acc
	for:
		bge t1, t0, sum		# i > k -> sum
		addi sp, sp, -4		# faccio spazio per un num
		read_int
		sw a0, 0(sp)		# metto num su stack
		addi t1, t1, 1		# i ++
		j for
		
		
	sum: 
		beq t1, zero, exit		# if i = 0 exit
		lw t0, 0(sp)			# Last In, First Out
		add t2, t2, t0			# sum += sp
		addi sp, sp, 4			# dealloco stack
		addi t1, t1, -1			# i--
		j sum
	
	exit:
		print_int(t2)			
		li a7, 93			
		li a1, 0
		ecall
	
