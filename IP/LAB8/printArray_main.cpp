#include <iostream>
#include "printArray_funct.h"

using namespace std;

int main ()
{
	int N = 5;
	int v[N]={4,5,9,78,33};
	int b[]={11};
	int c[]={};
	
	printArray (v, N);
	printArray (b, 1);
	printArray (c, 0);

	printArrayWithIndex(v, N);
	printArrayWithIndex(b, 1);
	printArrayWithIndex(c, 0);
	
	//si ottiene lo stesso risultato
	
return 0;
	
}