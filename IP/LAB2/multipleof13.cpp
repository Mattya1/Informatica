// Scrivere un programma che legge un numero intero da input e stampa se è o no divisibile per 13. [ File multipleof13.cpp]

#include <iostream>

using namespace std;

int main ()
{

int num;

cout << "inserisci un numero"<< endl;
cin >> num;

if (num%13 == 0){
    cout << num << " e' divisibile per 13.";
}
else{
    cout << num << " non e' divisibile per 13.";
}
}