/* Scrivere una funzione che dati due float base e altezza, restituisce l’area del rettangolo di base base e altezza altezza. La
funzione deve verificare che base e altezza siano valori positivi ed in caso contrario sollevare una eccezione di tipo int.*/

#include <iostream>
using namespace std;

float area (float base, float altezza)
{
	if (base <= 0 && altezza <= 0)
	{
		int err =3;
		throw err;
	}
	else if (base <= 0)
	{
		int err = 1;
		throw err;
	}
	else if (altezza <=0)
	{
		int err =2;
		throw err;
	}
	
	return (base*altezza);
}

int main ()
{
	float b, h;
	cout << "Inserisci la base: "; 
	cin >> b;
	
	cout << "\nInserisci l'altezza: ";
	cin >> h;
	
	try{
		float a = area (b, h);
		cout << "l'area e' " << a;
	}
	catch(int& err){
		if (err == 3)
			cout << "Base e altezza non valide";
		else if (err == 2)
			cout << "Altezza non valida";
		else if (err==1)
			cout << "Base non valida";
	}
	
	}