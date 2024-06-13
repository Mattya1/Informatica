/*Scrivere un programma che chiede all’utente in che anno è nato e stampa quanti anni ha (supponiamo sia nato il 1 Gennaio).
Il programma deve essere scritto in un file chiamato agecalc.cpp. */

#include <iostream>
using namespace std;

int main ()
{

int nato;
const int anno = 2023;

cout << "Inserisci anno di nascita: ";
cin >> nato;

cout << "hai " << anno - nato << " anni."; 

}