#include <iostream>
#include "allDiffArrayElements_funct.h"

using namespace std;

int main ()
{
	int N = 10;
	int arr[N]={11,55,2,3,78,77,99,11,56};
	
	cout << boolalpha<< allDiffArrayElements (arr, N);
	
	return 0;
}