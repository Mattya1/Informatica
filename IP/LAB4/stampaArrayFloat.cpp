/* Stampa inverso di un array di float. Scrivere un programma che lavora su un array di float e li stampa in ordine inverso
[ File stampaArrayFloat.cpp ] */

#include <iostream>
using namespace std;

int main ()
{
int i;
float a[5] = {2.4, 5.67, 34, 28.456, 846.42};

for (i=4; i>0; i--){
 cout << a[i]<< endl;}

}