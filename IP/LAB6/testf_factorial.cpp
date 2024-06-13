/* Scrivere una funzione che 
dato come argomento un intero non negativo n restituisce come risultato il suo fattoriale.
Il fattoriale di un numero è definito per induzione come 0! = 1 e (n + 1)! = (n + 1) ∗ n!. 
Quindi, ad esempio 3! = (2 + 1)! =
3 ∗ 2! = 3 ∗ (1 + 1)! = 3 ∗ 2 ∗ 1! = 3 ∗ 2 ∗ (0 + 1)! = 3 ∗ 2 ∗ 1 ∗ 0! = 3 ∗ 2 ∗ 1 ∗ 1. 
In generale n! = n ∗ (n − 1) ∗ (n − 2) ∗ ... ∗ 1. */

#include <iostream>
using namespace std;

int factorial (int n)
{
	if (n<0){
		cout<< "il numero e' negativo";
		return -1;
	}
	else if (n==0){
		return -1;
	}

	int i;
	
	for (i4=(n-1); i>1; i--)
	{
		n=n*i;
	}
	
	return n;
}

int main ()
{

	int num;
	int n;
	cout << "inserisci un numero positivo: ";
	cin >> num;
	
	n=factorial(num);
	
	if (num >=0)
		cout << n << " e' il fattoriale di " << num;
	else
		cout << "erroreee";
		
}