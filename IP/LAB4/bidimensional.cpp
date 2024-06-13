/* Scrivere un programma che definisce due valori costanti, M pari a 5 e N pari a 8. 
Dichiara poi un array bidimensionale a di dimensioni M×N con int a[M][N]; 
(M=righe e N=colonne), e riempe ogni riga con N valori pari all’indice della riga corrente.
Terminata la fase di inizializzazione dell’array, il programma stampa l’array. [ File bidimensional.cpp */

#include <iostream>
using namespace std;

int main ()
{

int M=5;  //righe
int N=8;  //colonne
int i, j;

int arr[M][N];

for (i=0; i<M; i++)		//riga 1	
{
	
	for (j=0; j<N; j++) //colonna 1	
	{
		arr[i][j]=i;
		cout << arr[i][j] << " "; //stampo subito il valore
	}
	
	cout <<"\n";
}	

}