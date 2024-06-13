#include <iostream>
#include "isPresentInArray_funct.h"

using namespace std;

bool isPresentInArray (int *t, int size, int x)
{
	bool ans = false;
	for (int i = 0; i<size; i++)
	{
		if (*t == x){
			ans = true;
			break;}
	
		t++;
	}
	return ans;
} 