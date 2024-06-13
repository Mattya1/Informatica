#include <iostream>
#include <vector>
#include "sequentialSearch_vector.h"
#include "iovector.h"
using namespace std;

int main ()
{
	vector <int> luca;
	
	readVector (luca);
	printVector (luca);
	
	cout << "\nitem e' in indice "<< sequentialSearch_vector (luca, 55);
	
	return 0;
}