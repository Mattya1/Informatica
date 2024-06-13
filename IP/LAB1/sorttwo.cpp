/*4. Scrivere un programma che legge due numeri e li stampa in ordine crescente senza confrontarli. Il programma deve essere
scritto in un file chiamato sorttwo.cpp.
[SUGGERIMENTO: se alla media sottraggo la semidistanza, che valore ottengo?] */

#include <iostream>
using namespace std;

int main ()
{
	
int num1, num2;	

cout << "Inserisci due numeri: ";
cin >> num1 >> num2;

cout << "il numero piu' piccolo e' " << ((num1+num2)/2) - ((num2-num1)/2)<< " e il piu' grande e' " << num2;

}