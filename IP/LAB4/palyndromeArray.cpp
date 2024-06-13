/* Scrivere un programma che legge un array a e calcola un valore di tipo bool che vale true se l’array è palindromo. Poi stampa
un messaggio che comunica il risultato all’utente. [ File palyndromeArray.cpp ] */

#include <iostream>
using namespace std;

int main ()
{

int n=5;
int a[n];
int rev[n];
int i, m;

bool pali = true;

cout << "inserisci i valori: ";
//inserisco valori nel primo array e li copio inveriti
for (i=0; i<n; i++)	
{
	cin >> a[i];
	m=(n-1)-i;		//n-1 xk altrimenti partirebbe dalla posizione 5, che non esiste
	
	rev[m]=a[i];
}

//stampo entrambi gli arr da 0 a n-1, e li confronto pian piano
for (i=0; i<n; i++)
{
	if (a[i]==rev[i]){
	pali = true;}
	else{
	pali = false;
	break;}	
}
if (pali ==true){
	cout<< "e' palindromo";
}
else{
	cout << "non e'  palindromo";
}

}