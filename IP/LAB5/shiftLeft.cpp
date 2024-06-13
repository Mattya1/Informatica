/*Scrivere il programma che esegua la traslazione verso sinistra degli elementi di un vettore letto in ingresso (di dimensione
D fissata nel codice del programma), ovvero ogni elemento deve essere copiato in quello di indice immediatamente minore.
Il valore del primo elemento deve essere perso, quello dell’ultimo deve essere rimpiazzato da 0. Quindi stampa il risultato.
Ad esempio: [1 10 15 18] −→ [10 15 18 0]*/

#include <iostream>
using namespace std;

int main ()
{
	int D=4;
	int arr[D]={1, 10, 15, 18};
	
	for (int i=0; i<D; ++i)
	{
		arr[i]=arr[i+1];
	}
	arr[D-1]=0;
	
	for (int i=0; i<D-1; ++i)
	{
		cout<<arr[i]<< ", ";
	}
	cout<<arr[D-1];
	return 0;
}