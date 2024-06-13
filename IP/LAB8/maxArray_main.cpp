#include <iostream>
#include "maxArray_funct.h"

using namespace std;

int main ()
{
	int N = 8;

	int t[N]={45, 89, 77, 12, 1, 65};
	
	cout << "Il numero piu' grande e': " << maxArray (t, N);
	
	return 0;
}