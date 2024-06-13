#include <iostream>
using namespace std;

int main ()
{
	const int N =5;
	int *v;
	
// allocare una quantità di memoria pari a N int, assegnandola a v
	v = new int [N]; 
	
// scrivere nella memoria puntata da v la sequenza di valori 1, 3, 5, ... , 2*N-1 (i primi N dispari)

//la memoria allocata con 'new' è accessibile tramite puntatore. lui stesso è la variabile
	for (int i=0; i<N; ++i)
	{
		v[i] = (2 * i +1);	//i primi N numeri dispari
	}
	
	cout << "\nv contiene: ";
	for (int i=0; i <N; ++i)
	{
		cout <<v[i]<<", ";
	}

//deallocare v
	delete [] v;	//uso [] perchè sono stati riservati più elementi
	v= nullptr;		//punto a nullptr, perchè è in una posizione pericolosa

//allocare una quantità di memoria pari a 2*N int, assegnandola a v
	
	v = new int [2*N];		//quindi 10 elementi
	
	for (int i=0; i<(2*N); ++i)
	{
		v[i] = (2*i+1);	//i primi 2*N numeri dispari
	}
	
	cout << "\nv contiene: ";
	for (int i=0; i <2*N; ++i)
	{
		cout << *(v+i)<<", ";
	}
	
	delete [] v;
	v= nullptr;
	
	return 0;
}

/*
USARE VALGRIND
1- compilare g++ -Wall -std=c++14 -g nomefile.cpp
2- eseguire valgrind --leak-check=full --track-origins=yes -s ./nomefileCOMPILATO
*/