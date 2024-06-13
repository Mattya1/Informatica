/* . Scrivere un programma che chiede all’utente un numero reale e lo legge salvandolo in una variabile di tipo float. Quindi,
ne fa una copia (in un’altra variabile di tipo float) e in cascata (ovvero usando il risultato di ciascuna operazione come
argomento per la successiva), lo divide per 4.9, per 3.53 e per 6.9998. Poi, sempre in cascata, moltiplica per 4.9, per 3.53 e
per 6.9998. Infine confronta il risultato ottenuto con il numero iniziale e se rappresentano due numeri reali diversi stampa
"moltiplicare NON e' l'inverso di dividere". [ File checkprecision.cpp ] */

#include <iostream>
using namespace std;

int main ()
{

int num;
cout<< "inserisci un numero\n";
cin >> num;

float a = num;

float b = a;

a= b/4.9;

b= a/3.53;

a = b/6.9998;

b = a*4.9;

a=b*3.53;

b=a*6.998;

if (num != num){
	cout<< "Moltiplicare NON e' l'inverso di dividere";}
	else{
	cout << "lo e'";}


}