/* 1. Scrivere una funzione void square(int n) con un parametro di tipo intero che stampa un quadrato vuoto con i lati composti
di 'x' di dimensioni pari all’argomento. Se l’argomento è negativo o 0 non stampa nulla ma solleva un’eccezione di tipo
string con un messaggio "Errore valore < 1". Ad esempio con n=7 stamperà: */

#include <iostream>
using namespace std;


void square (int n)
{	
	if (n<=0){
		int err = -1;
		throw err;
	}
	
	//ora devo creare il quadrato
	int i, j;
	for	(i=0; i<n; i++)//serve a mandare a capo
	{
		for (j=0; j<n; j++) //serve per fare le 'x '
		{
			if (i==0|| i==n-1 ||j==0||j==n-1) //così stampa la x sopra, sotto e i lati
				cout << "x ";
			else
				cout << "  ";
		}
		
		cout<< "\n";
	}
	
	
}

int main ()
{
	
	cout << "Inserisci il lato del quadrato: ";	
	int lenght;
	cin >> lenght;
	
	try
	{
		square(lenght);	
	}
	catch (int& err)
	{
		cout << "Lunghezza non valida";		
	}
	
	return 0;
}