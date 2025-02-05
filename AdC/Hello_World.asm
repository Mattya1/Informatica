.data						#non è un codice
str:						#stringa:
 .string "Hello world!\n"			#scrivo la stringa
 
 .text						#ora scrivo del testo
 main:						#specifico che è da qua che deve iniziare ad eseguire il programma
 
 li a0, 1					#inserisco il valore 1 nel registro a0
 la a1, str					#in a1 inserisco l'indirizzo della stringa
 li a2, 13					#carico la lunghezza della stringa in a2
 li a7, 64					#a7 is what determines which system call we are calling and we what to call write (64
 ecall						#chiamata a sistema
 
 li a0, 0					#e'� il codice di uscita
 li a7, 93					#exit 93
 ecall 
