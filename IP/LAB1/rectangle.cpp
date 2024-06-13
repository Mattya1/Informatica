/*Scrivere un programma che calcola perimetro e area di un rettangolo, dopo aver chiesto e letto i dati necessari. Il programma
deve essere scritto in un file chiamato rectangle.cpp */

#include <iostream>
using namespace std;

int main ()
{

int lat1, lat2;

cout << "Inserire il primo lato: ";
cin >> lat1;

cout << "Inserire il secondo lato: ";
cin >> lat2;

cout << "Il perimetro e' " << (lat1+lat2)*2 << endl;
cout << "L'area e' :" << lat1*lat2 << endl;


}