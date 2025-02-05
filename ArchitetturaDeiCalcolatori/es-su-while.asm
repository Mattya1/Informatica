.globl main

.data
A:	.word 1,2,3,4,5,6,7,8,9,10,11,12,-1
acc:	.word 0						#acc = somma di tutti i numeri "scanditi"

# le macro sono come delle funzioni 
.macro print_int (%x)	
	li a7, 1			#carico 1 in a7, registro per specificare syscall	1 rappresenta la chiamata per stampare un intero
	mv a0, %x			#copio il valore x in a0, registro argomento della syscall
	ecall				#effettua la chiamata a sistema,
					#a7 contiene 1, quindi stampa un intero x, ovvero a0
.end_macro

.macro exit (%x)
	li a7, 93			#93 è il valore per fare una syscall per terminare il programma
	li a0, %x			#carico il valore di %x in a0, che rappresenta il codice di uscita
	ecall				
.end_macro

.text 
main:
#non salverò in memoria la vartiabile i, non mi servirà più
li t1, 0		# t1 è acc, e la inizializzo con 0
li t2, 0		# t2 è i
la t3, A		# carico l'indirizzo di A in t3 -- A[0]
li t4, -1		# salvo -1 perchè è il parametro di confronto del while
li t5, 0		# in t5 metto MOD, mi servirà dopo
la t0, acc		 # salvo l'accumulatore

#inizio con ciclo while
while:
	lw t6, 0(t3)			# metto il primo elem di A in t6
	beq t6, t4, fin_while		# A[i] == -1 ? se si, finisco while  -- beq = branch if equal
	bne t6, t4, next			# t6 != -1 ? se si, next, vado avanti
	
	add t1, t1, t6			# acc += A[i]
	addi t5, t5, 3			# MOD = 3

next:	
	addi t2, t2, 1		# i++
	addi t3, t3, 4		# A[i+1]
	j while			# torno a inizio while
	
fin_while:
	sw t1, 0(t0)		# salvo acc in memoria
	print_int(t1)		# stampo acc
	exit(0)
	
	