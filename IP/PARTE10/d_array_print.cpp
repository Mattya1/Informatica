#include <iostream>
#include "d_array.h"
using namespace std;

//l'array viene passato come const così non si può modificare
void print_d_array(const dynamic_array &d)
{
	double *p = d.store;
	
	cout <<"\n";
	
	for (unsigned int i=0; i<d.size; ++i)
	{
		cout << *(p+i);
		if (i<d.size-1)
			cout<< ", ";
	}	
	cout << endl;
}