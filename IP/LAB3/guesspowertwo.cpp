/*Scrivere un programma che chiede all’utente un numero intero e lo legge. Poi chiede all’utente di provare a indovinarne il
quadrato e se l’utente inserisce il valore giusto gli dice "Bravo!" ed esce, altrimenti gli propone di riprovare finché l’utente
non riesce ad indovinare.
[ File guesspowertwo.cpp ]*/

#include <iostream>
#include <cmath>
using namespace std;

int main ()
{

int num, potenza;
cout << "Inserisci un numero: ";
cin >> num;

cout << "indovinane il quadrato: ";

while (potenza != pow(num, 2)){

cin >> potenza;}

cout << "Bravo!";
	
}