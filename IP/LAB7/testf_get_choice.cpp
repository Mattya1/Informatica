/*Scrivere una funzione con un argomento intero max che chiede all’utente di inserire una scelta compresa fra uno e max
finché l’utente non ne inserisce una accettabile e la restituisce.*/

#include <iostream>
using namespace std;

int get_choice(int max)
{
	int scelta;
	
	do
	{
		cout<< "Inserisci una scelta fra 1 e " << max<<"\n";
		cin >> scelta;	
	}
	while (scelta <1 || scelta >max);
	
	return scelta;
}

int main ()
{
	cout << get_choice(7);

	return 0;	
}