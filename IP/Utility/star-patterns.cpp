//esercizio sulle star pattern

#include <iostream>

using namespace std;

int main ()
{
	int i, j, lu;

	cout << "inserisci lunghezza: ";
	cin >> lu;
	
//triangolo superiore
//i sono le righe, j le colonne

//triangolo decrescente (da n a 0)
	for (i=0; i < lu; i++)
	{
		for (j=i; j<lu; j++){
		cout << "*";}
		
		cout << "\n";
	}

//triangolo crescente (da 0 a n)
	for (i=0; i < lu; i++ )
	{			
		for (j=0; j < i; j++){
		cout << "*";}		
		
		cout << "\n";
	}


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