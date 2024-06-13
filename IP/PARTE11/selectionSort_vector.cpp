#include <iostream>
#include <vector>
#include "selectionSort_vector.h"
using namespace std;

void selectionSort_vector (vector <int> &v, bool ascending)
{
	unsigned int index=0;
	
	for (unsigned int i=0; i < v.size(); ++i)
	{
		index=i;
		
		for (unsigned int j = i+1; j<v.size(); ++j)
		{
			if (ascending == true)
			{
				if (v[j] < v[index])
					index = j;
			
			}else if (ascending == false){
			
				if (v[j] > v[index])
					index = j;
			}
		}
		
		int temp = v[i];
		v[i] = v[index];
		v[index]= temp;
	}
};