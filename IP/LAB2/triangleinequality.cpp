/* Scrivere un programma che verifica se tre numeri reali dati in input possono essere i lati di un triangolo, 
cioè se nessuno di essi è maggiore della somma degli altri due. 
(https://it.wikipedia.org/wiki/Disuguaglianza_triangolare) [ File triangleinequality.cpp] */

#include <iostream>
using namespace std;

int main ()
{

int num1, num2, num3;

cout << "inserisci tre lati: \n";
cin >> num1 >> num2 >> num3;

if (num1 > num2+num3 || num2 > num1+num3 || num3 > num1+num2){
	cout << "Non possono essere lati di un triangolo.";
}
else{
	cout << "Sono lati di un triangolo.";}

}