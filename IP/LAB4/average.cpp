/* Media: scrivere un programma che legge N valori reali, li memorizza in un array di lunghezza N, 
e ne stampa la media*/

#include <iostream>
using namespace std;

int main ()
{

int i=0;
int n=0;
float a[n];
float sum = 0;

cout << "inserisci numero di valori: ";
cin >> n;

for (i=0; i<n; i++){
	cout << "inserisci un valore di a["<< i <<" ]: ";
	cin >> a[i];
	sum = (sum + a[i]); }
	
cout<<"i valori contenuti nell'array sono: {"; 

for (i=0; i<(n-1); i++){
cout<< " " << a[i] <<",";}

cout << " " << a[n-1] << " }\n";

cout << "la media e': "<< (sum/n);

}