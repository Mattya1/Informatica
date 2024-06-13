#include <iostream>

using namespace std;


const int N = 5;

void f (int* array)
{
	cout << "Dimensione del parametro = " << sizeof(array) << endl;
	//probabilmente devo fare un ciclo
}


int main ()
{
	int v[N];
	int *p = v;
	
	cout << "Dimensione di v = " << sizeof(v) << endl;
	//La dimensione di v è calcolata come N * sizeof(int), e in questo caso è 5 * sizeof(int).
	cout << "Dimensione di p = " << sizeof(p) << endl;
	//La dimensione di p è la dimensione di un puntatore a intero, che è tipicamente 8 byte
	
	f(v);
	//Quando passi l'array v alla funzione f, stai passando un puntatore, e quindi sizeof(array) all'interno di f restituirà la dimensione di un puntatore, non la dimensione dell'array originale.

return 0;	
}