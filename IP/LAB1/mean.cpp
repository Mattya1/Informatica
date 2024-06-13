/* Scrivere un programma che legge due interi e ne stampa la media (come numero reale). Ad esempio sull’input 1 e 2 stampa
1.5. Il programma deve essere scritto in un file chiamato mean.cpp. */

#include <iostream>
using namespace std;

int main ()
{
	
int num1, num2;
float media, somma;

cout << "Inserisci due numeri interi: ";
cin  >> num1 >> num2;	
somma = num1+num2;
media = (somma/2);

cout << "La media e' " << media;
	
}