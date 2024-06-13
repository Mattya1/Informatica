/* Crea un array con N elementi di tipo int. Scrivere un programma che dichiara un array a di N interi e lo “popola” (assegna
valori ai suoi elementi). */

#include <iostream>
using namespace std;

int main ()
{
	
int num =10;
int i;
int a[num];

for (i=0; i < 10; i++){
	 a[i]=num;
	 num--;
}
i=0;

for (i=0; i<10; i++){
cout<<a[i]<<endl;}

	
}