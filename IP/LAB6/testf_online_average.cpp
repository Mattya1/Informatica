#include <iostream>
using namespace std;

double onlineAverage()
{
	double media=0;
	float num;
	int conta=0;
	char risp;
	
	while(risp !='n')
	{
		cout<< "\ninserisci un numero: ";
		cin >> num;
		media= media+num;
		conta++;
		cout << "vuoi continuare? y/n:";
		cin >> risp;
	}
	
	media=media/conta;
	return media;
}

int main ()
{
	double mid=onlineAverage();
	cout << "la media e' "<<mid ;	
}