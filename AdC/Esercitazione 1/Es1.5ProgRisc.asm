# E5 Scrivere un programma Risc-V per calcolare il massimo comun divisore di due numeri interi positivi
# usando l’algoritmo di Euclide delle sottrazioni successive.

.global main

.data
str:  .asciz "inserisci numero: "
str2: .asciz "l'MCD è: "

.macro print_int (%x)
	li a7, 1
	mv a0, %x
	ecall
.end_macro

.macro read_int
	li a7, 5
	ecall
.end_macro

.macro print_string(%x)
	li a7, 4
	la a0, %x
	ecall
.end_macro

.text
	main:
	
	print_string(str)		# m
	read_int
	mv t0, a0
	
	print_string(str) 		# n
	read_int
	mv t1, a0
	
	bgt t0, t1, Euclide
	blt t0, t1, Minore
	#altrimenti t0 == t1 e mcd = entrambi
	j end
	
	
	Euclide:
		#caso base
		rem t3, t0, t1		# t3 = t0 % t1
		beq t3, zero, end	# rem == 0
		
		mv t0, t1			# scambio i valori per la prox iterazione
		mv t1, t3
		j Euclide
		
	Minore:			# scambio gli argomenti e rimando a Euclide
		mv t3, t0
		mv t0, t1
		mv t1, t3
		j Euclide
		
	end:
		print_string(str2)		
		print_int(t1)		
		
		li a7, 10
		ecall
	
	