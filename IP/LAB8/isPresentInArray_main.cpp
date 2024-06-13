#include <iostream>
#include "isPresentInArray_funct.h"

using namespace std;

int main ()
{
	int N=5, x=45;
	int v[N]={0,11,45,98,88};
	
//boolalpha serve per printare true/false al posto di 1/0
	cout<< boolalpha << isPresentInArray(v, N, x);
	
	return 0;	
}