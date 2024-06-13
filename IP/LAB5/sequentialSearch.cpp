/* Scrivere un programma che effettui la 
ricerca dell’elemento item (un intero) nell’array v (array di 15 interi letti da input).
[ File sequentialSearch.cpp ] */

#include <iostream>
using namespace std;

int main ()
{

	int n = 15;
	int item, v[n], i;
	
	int loc = -1;
	bool found = false;

	cout << "inserisci item da cercare: ";
	cin >> item;

	cout <<"\n" << "inserisci l'array: ";

	for (i=0; i<n; i++)
	{
		cin >> v[i];
	}

	for (i=0; i<n; i++)
	{
		if (v[i] == item){
			found=true;
			loc = i;
			break;		//cosi' esco dal loop, altrimenti loc cambierebbe
		}
	 
	}

	if (found==true){
		cout << item << " e' stato trovato in posizione " << loc;}
	else{
		cout << item << " non e' stato trovato";}
}