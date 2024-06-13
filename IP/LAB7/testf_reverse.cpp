/*Scrivere una funzione con un parametro intero k che restituisce il numero ottenuto leggendo k da destra verso sinistra. Ad esempio su 17 restituisce 71, su 27 458 restituisce 85472 e così via.*/

#include <iostream>
using namespace std;

int reverse (int k)
{
	int sign =1;
	
	if (k<0)
	{
		sign = -1;
		k= -k;
	}
	
	int inv = 0;
	
	while (k!=0)
	{
		int mod = k%10;
		k=k/10;
		inv=inv*10;
		inv=inv+mod;		
	}
	
	return (inv*sign);
}

int main ()
{
	int z;
	cout << "Inserire un numero intero: ";
	cin >> z;
	
	cout << "\nRovesciando " << z << " si ottiene " << reverse(z);
	
	
}