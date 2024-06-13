#include <iostream>
#include "reverseArray_funct.h"
using namespace std;

int main ()
{
	const int N =8;
	int source[N]={23,1,2,3,4,5,6,7};
	int dest[N] = {0,0,0,0,0,0,0,0};
	
	cout << "\nsource: ";
	printArray (source, N);
	cout << "\ndestination: ";
	printArray (dest, N);
	
	reverseArray(source, dest, N);
	
	cout<< "\n\nflipped\nsource: ";
	printArray (source, N);
	cout <<"\ndestination: ";
	printArray (dest, N);
	
	return 0;
}