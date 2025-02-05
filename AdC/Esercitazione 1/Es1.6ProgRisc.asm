# E6 Considerare il programma
# int main(…) {
# int A[13] = {1,2,3,4,5,6,7,8,9,10,11,12,-1};
# int acc = 0;
# int i = 0;
# while(A[i] != -1) {
#	  if(i%3 == 0) acc+=A[i];
#	  i++; 
#	 }
# printf("%d\n",acc);
# exit(0) 
# }
# Generare il corrispondente codice Risc-V completando il seguente template:

.globl main
.data
A: .word 1,2,3,4,5,6,7,8,9,10,11,12,-1
acc: .word 0

.macro print_int (%x)
	li a7, 1
	mv a0, %x
	ecall
.end_macro

.macro exit (%x)
	li a7, 93
	li a0, %x
	ecall
.end_macro

.text 
main:
# t0 = A[0], t1 = i, t2 = acc, t3 = -1, t4 = rem, t6 = 3
# inizializzo tutto
la t0, A			# t0 = 1
add t1, zero, zero	# i = 0
lw t2, acc			# acc
addi t3, zero, -1		# const -1
add t4, zero, zero	# rem 0
addi t6, zero, 3		# const 3
 
 while:
 	lw t5, 0(t0)		# carico il prossimo el in t5
 	beq t5, t3 end_while	# A[i] == -1 ?
 	
	
	rem t4, t1, t6	 	# t4 = i % 3 
 	bne t4, zero Else	# (i % 3) != 0 -> SKIPPO
 	
 	add t2, t2, t5		# altrimenti acc += A[i]
 	
Else:
	addi t1, t1, 1		# i++ 
	addi t0, t0, 4		# next word
	j while
 
 end_while:
 	print_int (t2)		# print acc
 	exit(0)

   	


