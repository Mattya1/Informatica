/*Scrivere una funzione con un parametro n di tipo intero che stampa un rombo di asterischi che sulla diagonale ha 2*n+1
caratteri. Ad esempio, dato 8 stampa (rombo) che sulla diagonale ha 17 caratteri */

#include <iostream>
using namespace std;

void rombo (int lu)
{

	int i,j;
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

int main ()
{
	int lungh;
	cout << "inserisci la lunghezza della semi diagonale minore: ";
	cin >> lungh;
	
	rombo(lungh);
	
	
	
return 0;
}