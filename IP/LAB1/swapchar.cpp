/*Scrivere un programma che scambia i valori di due variabili di tipo char, lette da input, e stampa i valori prima e dopo lo
scambio. Il programma deve essere scritto in un file chiamato swapchar.cpp.*/

#include <iostream>
using namespace std;

int main ()
{

//utilizzo il aus per "tenere da parte" i valori
char num1, num2, aux;

cout << "Inserisci due caratteri: "<< endl;
cin >> num1 >> num2;

aux = num1;
num1 = num2;
num2 = aux;

cout << "primo numero: " << num1 << endl;
cout << "secondo numero: "<< num2;
 
}