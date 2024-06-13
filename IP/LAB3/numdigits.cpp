/*Scrivere un programma che chiede all’utente un numero intero K strettamente positivo e ne stampa il numero di cifre (in
base 10). Ad esempio su 27458 stampa 5.
La richiesta deve essere esattamente questa "Inserisci un numero intero strettamente positivo: " (notare lo spazio in
fondo);
L’output è:
— se K <= 0 allora "Il numero inserito NON e' valido"
— se 1 <= K <= 9 allora "Il numero inserito e' composto da 1 cifra" (notare il singolare)
— se K >= 10 allora "Il numero inserito e' composto da N cifre" dove N è il numero di cifre di K (notare il plurale)
[ File numdigits.cpp ]*/

#include <iostream>
using namespace std;

int main ()
{
	
int k;
int conta=0;
	
cout << "Inserisci un numero intero strettamente positivo: "<< endl;
cin >> k;

if (k<=0){
cout<< "Il numero inserito NON e' valido" <<endl;}
else if(1 <= k && k<=9){
cout << "Il numero inserito e' composto da 1 cifra" << endl;}
else if(k>=10){
		
//devo contare le cifre, divido k per 10 e aumento un counter
for (conta=0; conta < k; conta++){
	k=k/10;}
	
cout << "Il numero inserito e' composto da " << conta << " cifre" << endl;}

return 0;
}