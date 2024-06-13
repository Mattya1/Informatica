#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
/*true se è positivo e primo false se è negativo/non primo
verifico se n è divisibile per un numero da 2 a radice di n */

	int i;
	if (n<=1)
		return false; //non continua a seguire le istruzioni
	
	for (i=2; i<=sqrt(n); i++)
	{
		if (n%i==0)
			return false;	//se n dovesse essere divisibile per uno di questi num non sarebbe primo
	}
	
	return true; //va fuori dal loop, perchè vuol dire che è primo
}

int main ()
{
	int i;
	int testare[]={1,2,4,5,10,15,18,19,25,30,33,36};

  /*int testare[n];	
	cout << "inserisci lunghezza";
	cin >> n;
	cout<< "\ninserisci numeri: ";
	for (i=0; i<n; i++)
	{
		cin >> testare [i];
	} */
	
	for (i=0; i<12; i++)
	{
		if (isPrime(testare[i]))
			cout << testare[i] << " e' un numero primo"<< endl;
		else
			cout << testare[i] << " non e' un numero primo"<< endl;
	}

return  0;
}