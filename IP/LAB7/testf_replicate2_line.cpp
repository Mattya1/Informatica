/*Scrivere una funzione replicate2_line con parametri f, f_c, s, s_c, dove f e s sono di tipo intero e f_c e s_c di tipo carattere.
La funzione stampa su una riga a sé stante f volte f_c, seguito da s volte s_c. 
Ad esempio replicate2_line(3, 's', 7, 'q') stampa sssqqqqqqq*/

#include <iostream>
using namespace std;

void replicate2_line (int f, char f_c, int s, char s_c)
{
	int i;
	for (i=0; i<f; i++)
	{
		cout << f_c;
	}
	for (i=0; i<s; i++)
	{
		cout << s_c;
	}
}

int main()
{
    int f;
    char f_c; 
	cout << "Inserisci il primo carattere e quante volte vuoi replicarlo: ";
	cin >> f_c >> f;
	
    int s;
    char s_c;
	cout << "Inserisci il secondo carattere e quante volte vuoi replicarlo: ";
    cin >> s_c >> s;
	
    replicate2_line(f, f_c, s, s_c);

	return 0;
}