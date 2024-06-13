/* Parabola: scrivere un programma che dati 
un array arr di float, la sua lunghezza N, e tre valori float a, b, c memorizza 
in ogni elemento x-esimo dell’array il valore ax^2+bx+c. Poi stampa l’array */

#include <iostream>
#include <cmath>
using namespace std;

int main ()
{

int i =0;
int n=10;
float arr[n], a, b, c;

cout << "inserisci il valore di a: ";
cin >> a;
cout << "inserisci il valore di b: ";
cin >> b;
cout << "inserisci il valore di c: ";
cin >> c;

cout << "valori nell'intervallo [0,9] della parabola "
<< a <<"x^2 + " << b << "x + " << c<<endl;

for (i=0; i<n; i++){
	arr[i]=i;}
	cout<< arr[0];
for (i=0; i<n; i++){
	cout<<"valore di arr["<<i<<"] = " << (a*pow(arr[i], 2) + b* arr[i] + c)<< endl;}
	

}