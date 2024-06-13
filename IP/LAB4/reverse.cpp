/* Scrivere un programma reverse che legge N interi in un array source (vedi leggiArrayInt), 
e poi copia in un array dest gli elementi di source in ordine inverso.
Quindi stampa source e dest (lasciando una riga vuota in mezzo per chiarezza). [ File reverse.cpp ] */

#include <iostream>
using namespace std;

int main ()
{

int n, i, p;
cout << "inserisci n: ";
cin >> n;

int source[n];
int dest[n];

//inserisco i valori 
for (i=0; i<n; i++)
{
	cin>> source[i];
	
	p=(n-1)-i;
	//qua scambio
	dest[p]=source[i];
	
}

for (i=0; i<n; i++)
{
	cout<<"i valori contenuti in source sono: {"; 

	for (i=0; i<(n-1); i++){
		cout<< " " << source[i] <<",";}

	cout << " " << source[n-1] << " }";
}
cout <<" "<< endl;

for (i=0; i<n; i++)
{
	cout<<"i valori contenuti in dest sono: {"; 

	for (i=0; i<(n-1); i++){
		cout<< " " << dest[i] <<",";}

	cout << " " << dest[n-1] << " }";
}

}