/* Stampa inverso di un array di float. Scrivere un programma che lavora su un array di float e li stampa in ordine inverso
[ File stampaArrayFloat.cpp ]*/

#include <iostream>
using namespace std;

int main ()
{
int lung = 10;
float a[lung];
int i;
float v;
cout << "Inserisci v: ";
cin >> v;

	
for (i=0; i < lung; i ++){
	a[i]=(i*v);}

/*
for (i=lung; i>0; i--){		stampa in ordine inverso
	cout<< a[i]<< endl;}
*/

for (i=0; i < lung; i++){
cout << a [i] <<endl;}

}