#include <iostream>
#include "maxArray_funct.h"

using namespace std;

int maxArray (int *t, int size)

{
	int max=0;
	
	for (int i=0; i<size; i++)
	{
		if (*t > max)
			max = *t;
		
		
		t++;
	}
	
	return max;
	
}