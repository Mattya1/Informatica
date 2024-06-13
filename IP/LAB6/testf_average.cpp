/*Scrivere una funzione che riceve un argomento intero hm,
legge hm numeri reali e ne restituisce la media */

#include <iostream>
#include <cstdlib>
using namespace std;

float average (int hm)
{
	if (hm <=0){
		cout << "errore\n";
		exit(0);
	}

	float sum = 0;
	int i;
	float x;
	
	for (i=0; i<hm; i++)
	{
		cout <<"\ninserisci un numero ";
		cin >> x;
		sum = sum +x;
	}
	
	return (sum/hm);
}

int main ()
{
	cout << "Di quanti numeri vuoi fare la media?";
	int how_many;
	cin >> how_many;
	
	float avg= average(how_many);
	
	cout <<"\nLa media e' " << avg;
}