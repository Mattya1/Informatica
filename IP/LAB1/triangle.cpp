/* Scrivere un programma che calcola l’area di un triangolo, dopo aver chiesto e letto i dati necessari. Il programma deve essere
scritto in un file chiamato triangle.cpp */

#include <iostream>
using namespace std;

int main ()
{

float base, altezza;

cout << "Inserisci la base: ";
cin >> base;

cout << "Inserisci altezza: ";
cin >> altezza;

cout << "L'area e' " << (base*altezza)/2 ;

}