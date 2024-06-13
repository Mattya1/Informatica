#include <iostream>
#include "countDigitsInArray_funct.h"

using namespace std;

int main ()
{
	int N = 5;
	char v[N]={'0','a','S','6','u'};
	
	int result = countDigitsInArray (v, N);
	cout << "\nIl numero di cifre è: " << result;
	
	return 0;
}