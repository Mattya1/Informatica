#include <iostream>
#include "shiftRightArray_funct.h"

using namespace std;

void shiftRightArray (int *t, int size)
{
	
	int temp = t[size-1];
	
	for (int i = size - 1; i > 0; --i)
	{
        t[i] = t[i - 1];
    }	
	
	t[0]=temp;

}