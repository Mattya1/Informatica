#include <iostream>
#include "arrayIncludedInArray_funct.h"

using namespace std;

bool arrayIncludedInArray (int *arr1, int size1, int *arr2, int size2)
{
	int comp=0;
	
//ho bisogno di 2 cicli per scorrere gli elementi del primo array nel secondo
//in questo ciclo gli elementi del primo array
	for (int i=0; i<size1; i++)
	{
	
		//qui ciclo gli elementi del secondo
		for (int j=0; j<size2; j++)
		{
			//qui comparo
			if (*arr1 == *arr2){
				//cout << *arr1<< ", "<<*arr2<<" =="<<endl;
				comp++;}
				//cout << comp<<endl;}
			/*else
				cout << *arr1<<", "<<*arr2<<" not =="<<endl;*/

			arr2++;
		}
		//devo riportare arr2 a 0
		arr2=arr2-size2;
		
		arr1++;
	}
	
	if (comp == size1)
		return true;
	else
		return false;	
	
}