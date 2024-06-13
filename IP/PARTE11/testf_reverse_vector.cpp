#include <iostream>
#include <vector>
#include "reverse_vector.h"
#include "iovector.h"

using namespace std;

int main ()
{
	vector <int> luca;
	
	readVectorAlt (luca);
	
	vector <int> giovanni = reverse (luca);
	
	printVector (luca);
	
	printVector (giovanni);
	
	return 0;
}