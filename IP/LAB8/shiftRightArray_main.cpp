#include <iostream>
#include "shiftRightArray_funct.h"
using namespace std;

int main ()
{
	int N=8;
	int t[N]={14,89,5,63,22,77,45,21};
	
	shiftRightArray(t, N);
	
	for (int i=0; i<N-1; i++)
	{
		cout << t[i]<< ", ";
	}
	cout << t[N];
	
	return 0;
}