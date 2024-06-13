/* Scrivere una funzione con un argomento intero n che restituisce un booleano, true se n è palindromo, ovvero se le sue cifre
(in base 10) lette da destra a sinistra corrispondono alle cifre lette da sinistra a destra (altrimenti restituisce false, ma questo
è sottinteso visto che per una espressione di tipo bool sono possibili due soli valori).
[ File testf_is_palindrome.cpp ] */

#include <iostream>
using namespace std;

bool isPal(int n)
{
	int k,inv=0;
	int mod=0;
	
	k=n;
	
	while (k!=0){		
	mod = k%10;		
	inv= inv*10;
	inv= inv+mod;
	k=k/10;}
	
	if (n==inv)
		return true;
	else
		return false;
	
}

int main ()
{
	int num;
	cout << "Inserisci un numero positivo: ";
	cin >> num;
	
	if (isPal(num)==true)
		cout << "E' palindromo";
	else
		cout << "Non e' palindromo";
	
	return 0;
	
}