/* Scrivere un programma che calcola circonferenza e area di un cerchio, dopo aver chiesto e letto i dati necessari. Supponiamo
π = 3.14. Il programma deve essere scritto in un file chiamato circle.cpp. */

#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	
const int pi =3.14;
int raggio;

cout << "Inserisci il raggio: ";
cin >> raggio;

cout<< "L'area e' "<< pi*pow(raggio, 2);
	
}