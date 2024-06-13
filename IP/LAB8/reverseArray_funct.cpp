#include <iostream>
#include "reverseArray_funct.h"
using namespace std;

//void reverseArray(int source[], int dest[], int size) alternativa
void reverseArray(int *source, int *dest, int size)
{
	for (int i =0; i<(size); i++)
	{
		dest[size-(i+1)] = source[i];
	}
}

void printArray(int *arr, int size)
{
	for (int i=0; i<size; i++)
	{		
		//stampo il contenuto dell'indirizzo puntato da s
		cout << *arr << ", ";
		//incremento s per cambiare posizione dell'array
		arr++;	
	}
}

