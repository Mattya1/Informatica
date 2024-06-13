/* . Leggi un array di float da tastiera e stampalo su singola riga. 
Scrivere un programma simile al precedente, ma che lavora su array di float 
e stampa il contenuto dell’array su una sola riga (gestire la virgola nel caso finale). 
Usare N = 5. */

#include <iostream>
using namespace std;

int main ()
{

int i;
int n=5;
float a[n];

for (i=0; i<n; i++){
	cout << "inserisci un valore di a["<< i <<" ]: ";
	cin >> a[i];}

cout<<"i valori contenuti nell'array sono: {"; 

for (i=0; i<(n-1); i++){
cout<< " " << a[i] <<",";}

cout << " " << a[n-1] << " }";
}