# il risultato dovrà essere 16
.globl main

.eqv L 8		# define L = 8

.data 
H: .space 32

.macro print_int (%x)
	li a7, 1
	mv a0, %x
	ecall
.end_macro

.macro exit
	li a7, 10
	ecall
.end_macro


.text

main:

	la a1, H					# H[0]
	
	li a2, 8					# a2 = L 
	
	#addi sp, sp, -8 				# alloco spazio nello stack per una word
	
	jal func1
	
	print_int(a0)
	exit
	
func1:

	li a0, 0					# k
	li t0, 0					# i
	li t1, 0					# j
	li t2, 5					# costante per i for
	li t3, 0					# t
	li t4, 0					# u
	li t5, 2					# m = 2
	
	li t6, 0					# mi servirà per i calcoli
	

	primo_for: 
	bge t0, a2, end_first_for			# for (i = 0; i < L; i++)
		
		secondo_for:
		bge t1, a2, incremento_i		# for (j = 0; j < L, j++)
			
			bne t0, zero, terzo_for		# if ( == 0 && j == 0)
			bne t1, zero, terzo_for
				
				mul t6, t0, a2				# i * L
				add t6, t6, t1				# (i*L) + j
				slli t6, t6, 2				# t6 * 4 = offset
				
				add t6, t6, a1				# indirizzo di H[(i*L)+j]
				li t4, 10
				sw t4, 0(t6)				# H[ (i*L) + j] = 10
					
				addi t1, t1, 1
				
				j incremento_j

			terzo_for:
				bgt a0, t2, incremento_j		# for (k = 0; k <= 5; k++)
					
					slli t3, a0, 1	
						
					blt t0, t3, incremento_k	
					bge t1, t3, incremento_k	# if (i >= t && j < t)
					
						sub t4, t0, t3				# i - t
						mul t4, t4, a2				# (i-t) *L
						add t4, t4, t3				# (i-t)*L + j
						slli t4, t4, 2				# calcolo offset di H[(i-t)*L+j]
						
						mul t6, t0, a2				# i * L
						add t6, t6, t1				# (i*L) + j
						slli t6, t6, 2				# calcolo offset di H[i*L+j]
						
						add t6, t6, a1				# indirizzo di H[i*L+j] 					
						add t4, t4, a1				# indirizzo di H[(i-t)*L+j]
							
						lw t4, 0(t4)
							
						sw t4, 0(t6)				# H[i*L + j] = H[(i-t)*L+j]

						j incremento_k
				
					incremento_k:
					addi a0, a0, 1			# incremento k
					j incremento_j			# torno a inizio loop
				

			incremento_j:
			li a0, 0			# resetto k
			addi t1, t1, 1		# incremento j
			j secondo_for
				
	 #SONO NEL CORPO DEL SECONDO FOR			
			
	incremento_i:
	li t1, 0			# resetto j		
	addi t0, t0, 1		# incremento i
	j primo_for

		
	end_first_for:
	
	li t4, 0				# u = 0
	li t2, 16
	li a0, 0				# k = 0
	
	quarto_for: 
		bge a0, t2, fine			# for ( a0 = 0; a0 < 16; ++k)
	
		addi a0, a0, 1		# ++k
		
		li t6, 0			# t6 = 0
		add t6, t6, a0		# t6 = k
		slli t6, t6, 2		# t6 = k * 4 (offset)
		add t6, t6, a1		# offset + H[0]  = H[k]
		lw t6, 0(t6)
		
		add  t4, t4, t6		# u = u + H[k]
		
		j quarto_for
	
	fine:
	ret
	
