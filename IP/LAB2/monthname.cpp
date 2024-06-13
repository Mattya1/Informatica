/*Scrivere un programma che legge un numero intero compreso fra 1 e 12 e stampa il nome del 
mese corrispondente (1==gennaio. . . ). Implementare usando lo switch. 
Se il numero non è compreso fra 1 e 12 stampa un messaggio di errore ed esce.*/

#include <iostream>
using namespace std;

int main ()
{

int mese;

cout << "Inserisci un mese da 1 a 12: ";
cin >>  mese;

while (mese < 1 || mese > 12 ){
    cout << "Valore errato, riprova: ";
    cin >> mese;
}

switch (mese)
{
case 1:
   cout << "Gennaio";
    break;

case 2:
    cout << "Febbraio";
    break;

case 3:
    cout << "Marzo ";
    break;

case 4:
    cout << "Aprile ";
    break;

case 5:
    cout << "Maggio ";
    break;

case 6:
    cout << "Giugno ";
    break;
case 7:
    cout << "Luglio ";
    break;
case 8:
    cout << "Agosto ";
    break;
case 9:
    cout << "Settembre ";
    break;
case 10:
    cout << "Ottobre ";
    break;
case 11:
    cout << "Novembre ";
    break;
case 12:
    cout << "Dicembre ";
    break;
default:
    break;
}

}