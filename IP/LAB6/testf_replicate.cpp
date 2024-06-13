/* Scrivere una funzione chiamata replicate, che restituisce void. 
La funzione riceve come argomenti un numero intero N> 0 e un carattere c, 
e stampa N volte il carattere c. 
Se il numero non è strettamente positivo, la funzione non stampa niente*/

#include <iostream>
using namespace std;

void replicate (int N, char c)
{
	int i;
	for (i=1; i<=N; i++)
	{
		cout<<c;
	}
	cout<<"\n";
}

int main ()
{
	int x;
	cin >> x;
	
	char c;
	cin >> c;
	
	replicate(x,c); 
}