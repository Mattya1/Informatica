#include <iostream>
using namespace std;

void replicate (int N, char c)
{
	int i;
	for (i=1; i<=N; i++)
	{
		cout<<c;
	}
}

void triangle (int lenght)
{
	int i;
	for (i=0; i<=lenght; i ++)
	{	
		replicate(i,'*');
		cout <<"\n";
	}
}

int main ()
{
	int len;
	
	cout<< "Inserisci un numero maggiore di 0: ";
	cin >> len;
	
	if (len >=0)
		triangle(len);
	else
		cout << "errore";
}