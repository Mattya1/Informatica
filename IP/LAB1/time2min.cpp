/*Scrivere un programma che prende in input il numero di ore (compreso fra 0 e 23) e di minuti (compreso fra 0 e 59) e
stampa in output il numero di minuti totali. Il programma deve essere scritto in un file chiamato time2min.cpp.*/

#include <iostream>
using namespace std;

int main ()
{
	
int ore, minuti;

cout << "Inserisci un orario: ";
cin >> ore >> minuti;

cout << "I minuti totali sono " << minuti+(ore*60);
	
}