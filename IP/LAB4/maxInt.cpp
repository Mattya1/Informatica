/* Scrivere un programma che legge N=5 interi e li salva in un array di int. 
Quindi stampa il valore massimo contenuto nell’array e il numero di volte in cui questo appare. 
Il programma appena avviato non stampa nessun messaggio e resta in attesa dei 5 valori interi separati da spazio. 
Premere invio dopo l’ultimo intero inserito. [ File maxInt.cpp ]

Suggerimenti:
per trovare il massimo dell’array e il numero di volte in cui questo appare ci sono (almeno) due soluzioni:
• una che percorre l’array due volte, una volta per cercare il numero massimo e una altra per contare quante volte è
presente
• un’altra che percorre l’array una sola volta ed ogni volta che trova un massimo (relativo) conta poi quante volte e
presente sino a che non trova un altro massimo (se esiste). L’ultimo massimo trovato è quello definitivo.

Per fornire in input N interi è possibile inserirli separandoli da spazio e premere una solo volta invio alla fine, non è necessario
premere invio dopo ogni intero.

L’output, su due righe, è:
28
"maxVal = " seguito dal valore massimo
"maxCount = " seguito dal numero di volte in cui questo appare
Esempio di esecuzione:
9 11 11 3 -23
maxVal = 11
maxCount = 2 */

#include <iostream>
using namespace std;

int main ()
{
	
int i, maxVal, maxCount;
i=maxVal=maxCount=0;
int n=5;
int a[n];

for (i=0; i<n; i++)
{		
	cin >> a[i];			//inserisco dati

	if (a[i] > maxVal){		//caso 1 è maggiore
	maxVal = a[i];
	maxCount=1;}
	
	else if (a[i] == maxVal){ //caso 2 è uguale (aumento count)
	maxCount++;}
}

cout << "maxVal = " << maxVal <<endl;
cout << "maxCount = "<< maxCount<<endl;

}