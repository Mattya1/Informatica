/* Scrivere una funzione con tre parametri di tipo float che li moltiplica fra loro, divide il risultato ottenuto per ciascuno degli
argomenti in successione e restituisce un booleano che vale vero se il risultato dell’operazione è 1.
[ File testf_is_one.cpp ] */

#include <iostream>
using namespace std;

bool isOne (float a, float b, float c)
{
	
	float mult = a * b * c;
	
	mult = mult/a;
	mult = mult/b;
	mult = mult/c;
	
	if (mult == 1)
		return true;
	else
		return false;
}

int main ()
{
	float a,b,c;
	
	cout << "inserisci tre numeri reali: ";
	cin >> a >> b >>c;
	
	bool d = isOne(a,b,c);
	
	if (d)
		cout << "il risultato e' 1";
	else
		cout << "il risultato non e' 1";
	
	return 0;	
}