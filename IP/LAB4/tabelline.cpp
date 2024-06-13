/* Scrivere un programma che definisce un valore costante, N pari a 10.
Dichiara poi un array bidimensionale tavolaPitagorica di dimensioni N×N, e lo riempie dei valori della tavola pitagorica,
dove l’elemento (i, j) contiene il prodotto tra i+1 e j+1 (perché?).
Infine chiede all’utente una coppia di valori tra 1 e 10 (verificare che siano entrambi nell’intervallo altrimenti richiederli
entrambi), e restituisce il loro prodotto – ottenuto consultando la tavola pitagorica come una look-up table, e non eseguendo
la moltiplicazione. [ File tabelline.cpp ] */

#include <iostream>
using namespace std;

int main ()
{

int N = 10;
int tavolaPitagorica [N][N];
int i, j, v1, v2;

for (i=0; i<N; i++)			//prima righe
{
	for (j=0; j<N; j++)		//poi colonne
	{
		tavolaPitagorica[i][j]=((i+1)*(j+1));
		
		// cout << tavolaPitagorica[i][j] << " ";

	}
	
	// cout <<"\n";
}

cout << "Inserisci una coppia di valori tra 1 e 10:  ";
cin >> v1 >> v2;

while (0>v1 || v1>10 || 0>v2 || v2>10)
{
	cout << "riprova: ";
	cin >> v1 >> v2;
}

cout << "il prodotto e': " << tavolaPitagorica[v1][v2] ;
}