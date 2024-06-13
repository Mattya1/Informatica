/*3. Scrivere un programma che chiede all’utente un numero intero positivo n e stampa un rombo di asterischi che sulle due
diagonali ha 2 x n + 1 caratteri. Ad esempio con 8 in input stampa (disegno)

che sulle due diagonali ha 17 caratteri. [ File stamparombo.cpp ]
[SUGGERIMENTO: È più facile stampare il rombo con due cicli, il primo per le righe in cui il numero di asterischi cresce e
il secondo per le righe in cui il numero di asterischi diminuisce. 
In questo modo si può suddividere l’esercizio in due parti:
(a) stampare il triangolo superiore (la parte superiore del rombo), dopodichè 
(b) adattare il codice per stampare il triangolo
inferiore (la parte inferiore del rombo).]*/

#include <iostream>

using namespace std;

int main ()
{
	int i, j, lu;

	cout << "inserisci lunghezza: ";
	cin >> lu;
//triangolo superiore (decrescente, crescente, decrescente)
	for (i=0; i < lu; i++){
	 
		for (j=i; j<lu; j++){ //per fare gli spazi a sinistra
		cout << " ";		
		}
		for (j=0; j < (i-1); j++){ //x fare triangolo complementare 
		cout << "*";				// i-1 x non avere due cime
		}
		for (j=0; j < i; j++){ //altro triangolo crescente
		cout << "*";
		 }	
		
		cout <<"\n"; // per andare a capo alla fine
	}
	
//ora devo invertire (crescente, decrescente, crescente, decrescente)

	for (i=0; i < lu; i++)
	{
		
		for (j=0; j < i; j++){
		cout << " ";
		}
		for (j=i; j<lu; j++){
		cout << "*";
		}
		for (j=i; j<(lu-1); j++){ //lu - 1 per la doppia colonna
		cout << "*";
		}
		for (j=0; j < i; j++){
		cout << " ";
		}
		
		cout << "\n";
	}



}