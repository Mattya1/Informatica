/* 0. Scrivere un programma che legge N interi in un array a di int (vedi leggiArrayInt). 
Quindi con un opportuno messaggio di output stampa il numero P dei numeri pari contenuti nell’array 
ed il numero D di quelli dispari 
(P e D sono quindi entrambi valori interi). [ File nPari.cpp ] */

#include <iostream>
using namespace std;

int main ()
{

int n, pari, dispari, i;
pari=dispari=0;
cout << "inserisci valore di n: ";
cin >> n;

int a[n];

cout << "inserisci i numeri: ";
for (i=0; i<n; i++)
{
	cin >> a[i];
	
	if (a[i]%2 == 0){
	pari++;}
	else{
	dispari++;}
}

cout << "ci sono " << pari << " numeri pari e " << dispari << " numeri dispari.";
	
}