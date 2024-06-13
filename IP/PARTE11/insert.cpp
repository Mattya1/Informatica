#include <iostream>
#include <vector>
#include "iovector.h"
#include "insert.h"

using namespace std;
//devo inserire un valore in posizione i, e spostare i valori a dx di i di 1
void insert (vector <int> &v, unsigned long int i, int val)
{
	if (i > v.size())
		throw string ("Index out of range.");

	v.push_back(v.back()); //sposto l'ultimo elemento indietro

	for (unsigned long int j = v.size()-1 ; j >i; --j)
	{
		v[j]= v[j-1];  //parto dal fondo e imposto quello dopo == a quello prima, e decremento fino alla posizione i
	}
	
	v[i] = val; //ora sostituisco
	
};