//Scrivere un programma che legge tre numeri reali e li stampa in ordine decrescente.

#include <iostream>
using namespace std;

int main ()
{

float num3, num2, num1, aux;
//inizializzo le variabili
num3=num2=num1=aux=0;

cout << "Inserisci tre numeri reali: "<< endl;
cin >> num1 >> num2 >> num3;
//aux = ausiliario, lo utilizzo per "spostare" i valori
aux = num2;

if (num1 < num2){
    aux = num1;
    num1=num2;
    num2=aux;
}

if (num1 < num3){
    aux=num1;
    num1=num3,
    num3=aux;
}

if (num2<num3){
    aux=num2;
    num1=num3;
    num3=aux;
}

cout << "Numeri in ordine decrescente: "<< num1 <<", "<< num2 <<", "<<num3;

}