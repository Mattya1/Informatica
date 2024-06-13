/* Scrivere una funzione con due argomenti reali x e sqrt_x che restituisce un valore booleano, true se sqrt_x è la radice
quadrata di x, ovvero se il quadrato di sqrt_x coincide con x.
Per testare la funzione usate come dati 25.3268614564 la cui radice quadrata è 5.03258 (se preferite altri valori, vi conviene partire da un numero con cifre decimali e farne il quadrato, in modo da evitare errori di approssimazione dovuti ai
troncamenti). [ File testf_is_sqroot.cpp ] */

#include <iostream>
#include <cmath>
using namespace std;

bool isroot (float sqrt_x, float x)
{
	
	//per comparare i float si usa fabs
	if (fabs((sqrt_x * sqrt_x) - x) < 0.00001) {
        return true;
    } else {
        return false;
	}
	
}

int main ()
{
	float radice, num;
	
	cout << "Inserisci la radice: ";
	cin >> radice;
	
	cout << "Inserisci il numero: ";
	cin >> num;
	
	bool d = isroot(radice, num);
	
	if (d)
		cout << radice << " e' la radice di " << num;
	else
		cout << radice << " non e' la radice di " << num;
	
	return 0;	
	
}