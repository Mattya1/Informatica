/* Scrivere un programma che legge un numero intero e ne stampa il valore assoluto (ovvero il numero senza segno, ad esempio
se leggo −7 devo stampare 7, (non usare funzioni matematiche di libreria cmath). [ File absval.cpp ] */

#include <iostream>
using namespace std;

int main ()
{

int num;

cout << "Inserisci un numero: ";
cin >> num;

if (num >=0){
cout << "e' gia' positivo.";}
else{
cout << "Il suo valore assoluto e' " << num*-1;} 

}