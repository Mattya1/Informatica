/* Scrivere una funzione che riceve un argomento intero hm, legge hm numeri reali e ne restituisce la media. Usare le eccezioni
per gestire i casi di errore. */

#include <iostream>
using namespace std;

float average(int hm){
	
	int i;
	
	if (hm <0){
	int err=0;
	throw err;}
		
	float sum =0;
	
	for (i=0; i <hm; i++)
	{
	
		cout << "\nInserisci un numero ";
		float x;
		cin >> x;
		sum = sum+x;
	}
	return (sum/hm);
	
}

int main ()
{
	try {
		int how_many;
	
		cout << "Di quanti numeri vuoi fare la media?";
		cin >> how_many;
	
		cout<<"\nLa media e' " << average(how_many);
	}
	catch(int& err) {
		cout << "\nerrore";
	}
}