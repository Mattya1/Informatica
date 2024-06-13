/* Scrivere una funzione senza argomenti 
che legge lettere minuscole finchè l’utente non inserisce un carattere che non è una lettera minuscola, 
e restituisce l’ultima in ordine alfabetico 
(ovvero quella che numericamente è la massima) */

#include <iostream>
using namespace std;

char last_letter()
{
	cout << "Inserisci una lettera minuscola ";
	char last;
	
	do{
	
		cin >> last;
	}	
	while (last < 'a' || last >'z');
	
	char c = 'a';
	 
	do{	
		
		if (c > last)
			last = c;
			
		cout << "Inserisci una lettera minuscola (o altro carattere per terminare)";
		cin >> c;
	
	}while (c >= 'a' && c<='z');

	return last;
}

int main ()
{

char last;
last = last_letter();
cout << "La lettera piu' grande inserita e' " << last;

}