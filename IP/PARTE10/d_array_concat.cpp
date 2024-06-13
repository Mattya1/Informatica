//creo un array che è l'unione di altri 2 (lungh t1+t2)
#include <iostream>
#include "d_array.h"
using namespace std;

void concat_d_arrays(const dynamic_array &t1, const dynamic_array &t2, dynamic_array &t3)
{
	
	t3.size = (t1.size+t2.size);
	
	cout << "\ndimensione: "<< t3.size;
	
	t3.store = new double [t3.size];
	
	for (unsigned int i=0; i<t1.size; ++i)
	{
		t3.store[i]=t1.store[i];}

	for (unsigned int i=0; i<t2.size; ++i)
	{
		t3.store[t1.size+i]=t2.store[i];}
	
}