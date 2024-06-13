/* Scrivere una funzione che dati due float base e altezza, 
restituisce l’area del rettangolo di base base e altezza altezza.
La funzione deve verificare che base e altezza siano valori positivi 
ed in caso contrario ritorna rispettivamente -1 e -2 (ritornare -3 se entrambi invalidi). 
Testare i vari casi con input opportuni */

#include <iostream>
using namespace std;

float area(float base, float altezza)
{
	if (base <0 && altezza <0)
		return -3;
	else if (base <0)
		return -1;
	else if (altezza <0)
		return -2;
	else
		return (base*altezza);
}

int main ()
{
	float b, h;
	cin >> b >> h;
	
	
	float a;
	
	a= area(b,h);
	
	if (a==-1)
		cout << "base non valida";
	else if (a==-2)
		cout << "altezza non valida";
	else if (a==-3) 
		cout << "base e altezza non valide";
	else
		cout << a;
		
}