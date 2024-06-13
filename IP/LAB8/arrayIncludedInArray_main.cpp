#include <iostream>
#include "arrayIncludedInArray_funct.h"

using namespace std;

int main ()
{
	int N=6, M=10;
	
	int t1[N]={1 ,89,66,57,4 ,8};
	int t2[M]={31,1 ,89,21,66,57,4,8,27,45};
	
	cout << "Il primo array è contenuto nel secondo? "<<
			boolalpha << arrayIncludedInArray(t1, N, t2, M);
	
	return 0;
	
}