/* Scrivere una funzione che, prese come argomenti quattro stringhe, le stampa nell’ordine ricevuto, ciascuna su una
nuova riga e preceduta da un numero progressivo, chiede all’utente un intero n compreso fra uno e quattro e stampa
su una nuova riga il parametro stringa n-esimo preceduto dalla stringa "Scelta effettuata: ": */

#include <iostream>
using namespace std;

void print_menu(string choice1, string choice2, string choice3, string choice4)
{
	
	cout<< "\n1 \t" << choice1
		<< "\n2 \t" << choice2
		<< "\n3 \t" << choice3
		<< "\n4 \t" << choice4;
}

int get_choice(int max)
{
	int scelta;
	
	do
	{
		cout<< "\n\nInserisci una scelta fra 1 e " << max<<"\n";
		cin >> scelta;	
	}
	while (scelta <1 || scelta >max);
	
	return scelta;
}

void print_choice(int n, string ch1, string ch2, string ch3, string ch4)
{
	cout << "\nScelta effettuata: ";
		if (n==1)
			cout << ch1;
		else if (n==2)
			cout << ch2;
		else if (n==3)
			cout << ch3;
		else if (n==4)
			cout << ch4;	
}

int use_menu(string choice1, string choice2, string choice3, string choice4)
{
	print_menu (choice1, choice2, choice3, choice4);
	int n = get_choice(4);
	print_choice(n, choice1, choice2, choice3, choice4);
	
	return n;
}

int main ()
{
	const string s1 = "Prima scelta";
	const string s2 = "Seconda scelta";
	const string s3 = "Terza scelta";
	const string s4 = "Quarta scelta";
	
	use_menu(s1, s2, s3, s4);	
}