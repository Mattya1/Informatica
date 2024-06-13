/* Scrivere una funzione con due parametri di tipo intero che stampa il trapezio rettangolo fatto di 'x' con le basi lunghe
quanto gli argomenti, e l’altezza pari alla differenza fra le basi più uno. Ad esempio su 5 e 9 stamperà:
(che è alto 5 = 9 − 5 + 1). 
Si noti che data la scelta dell’altezza a ogni riga bisogna stampare un carattere in più rispetto alla precedente */

#include <iostream>
using namespace std;

void trapezio (int maggiore, int minore)
{
	if (maggiore <=0 && minore <=0){ //controllo misure
		int err = -3;
		throw err;
	}
	else if (maggiore<=0){
		int err = -1;
		throw err;
	}
	else if (minore <=0){
		int err =-2;
		throw err;
	}
	else if (minore >maggiore){
		int err = -4;
		throw err;
	}
	
	int altezza = (maggiore-minore)+1;
	
	int i, j, q;
	for (i=0; i<altezza; i++) //gestisce gli a capo
	{
		for (j=0; j<minore; j++)
		{
			cout << "x";	
		}
		
		for(q=0; q< i; q++)
		{
			cout << "x";	
		}		
		
		cout << "\n";
	}
	
}

int main ()
{
	
	cout << "Inserisci la base maggiore: ";
	int magg;
	cin >> magg;
	
	cout << "Inserisci la base minore: ";
	int min;
	cin >> min;
	
	try
	{
		trapezio (magg, min);	
	}
	catch (int& err)
	{
		if (err ==-3)
			cout<< "Entrambe le basi non sono valide";
		else if (err == -1)
			cout << "Base maggiore non valida";		
		else if (err ==-2)
			cout << "Base minore non valida";
		else if (err ==-4)
			cout << "Base minore maggiore della base minore";
	}	
	
	return 0;
}