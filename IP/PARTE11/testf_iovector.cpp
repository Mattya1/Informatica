#include <iostream>
#include <vector>
#include "iovector.h"

using namespace std;

int main ()
{
	vector<int> luca;
	
	//readVector (luca);
	
	readVectorAlt (luca);
//l'eccezione si potrebbe catchare con <stdexcept>, ma non lo abbiamo fatto
	
	
	printVector (luca);
	
	return 0;
}