/* 8. Scrivere una funzione di nome divide che prende quattro argomenti interi a, b, q e r, restituisce void, quando viene chiamata
assegna a q il quoziente tra a e b (risultato della divisione intera) e a r il resto.
[ File testf_divide.cpp ] */

#include <iostream>
using namespace std;

void divide(int a, int b, int& q, int& r) 
{
    q = a / b;
    r = a % b;	
}

int main ()
{
	int a, b, q, r;
	cout << "Inserisci 2 numeri reali: ";
	cin >> a >>b;
	
	divide(a, b, q, r)0;
	
	cout << a << "/"<<b<< " = " << q << "," << r;
	
	return 0;
	
}