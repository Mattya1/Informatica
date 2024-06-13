#include <iostream>
#include "countDigitsInArray_funct.h"

using namespace std;

int countDigitsInArray (char *arr, int size)
{
	int count=0;
	
	for (int i=0; i<size; i++)
	{
		if (*arr>='0' && *arr>'9')
		{
			count++;
		}
		
//il * serve per accedere al valore della cella di memoria, 
//quindi in questo caso non lo metto perchè devo spostare il ptr
		arr++;
	}
	
	return count;
}