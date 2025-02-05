# ES1
# Legge un numero in input usando le call di sistema (sia K) minore di 30
# usando la readint troverete il valore letto in a0
# Legge quindi K numeri interi e li memorizza in memoria
# avrete già allocato un array o con .word 0,0... o meglio con .space 120
# Elabora i dati memorizzati calcolandone la somma e la media
# Stampa il risultato su console
#

.globl main

.data
A: .space 120

msg1: .asciz  "\nsomma:"
msg2: .asciz  "\nmedia:"

.macro read_int
	li a7, 5 # codice per syscall per lettura int da console
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

.macro exit (%x)
li a7, 93
li a0, %x
ecall
.end_macro

.text
main:

#k = t1, i = t2, sum = t3, med = t4

read_int # prendo k, che sara' il num di elem da memorizzare
mv t1, a0 # k in t1 	

li t2, 0 # i = 0
li t3, 0 # sum = 0
li t4, 0 # med = 0

la t0, A # t0 = A[0]

for:
	bge t2, t1 End 		 # if i > k End
	read_int			 # leggo da console
	sw a0, 0(t0)		 # A[i] = a0, quello che ho appena preso
	addi t0, t0, 4		 # A[i+1] mi muovo al prox elemento
	addi t2, t2, 1		 # i++
	
	j for

End:					 # scorro l'array da capo per fare somma e media
	li t2, 0			 # i = 0, resetto
	la t0, A			 # carico ind di A in t0

for2:
	bge t2, t1 Exit 		# if i > k

	lw t5, 0(t0)

	add t3, t3, t5 		 # sum = sum + A[i]
	addi t0, t0, 4		 # A[i+1]
	addi t2, t2, 1		 # i++

	j for2

Exit:
	div t4, t3, t1 		# med = sum / k
	la a0, msg1 
	print_string(a0)		#stampo la somma
	print_int (t3)
	
	la a0, msg2		
	print_string (a0)		#stampo la media
	print_int (t4)
	exit(0)
