/* Leggi un array di int da tastiera. 
Scrivere un programma che dichiara un array a di N interi e lo “popola” leggendo valori
da input. [ File leggiArrayInt.cpp ] */

#include <iostream>
using namespace std;

int main ()
{

int n=10;
int a[n];
int i;

for (i=0; i<n; i++){
	cout << "Inserisci un intero per a["<<i<<"]: ";
	cin>> a[i]; }
	
for (i=0; i<n; i++){
	cout<<"Valore di a["<< i <<"] = "<< a[i]<<endl;}
	
}