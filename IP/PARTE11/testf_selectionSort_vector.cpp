#include <iostream>
#include <vector>
#include "selectionSort_vector.h"
#include "iovector.h"
using namespace std;

int main ()
{
	vector <int> luca;
	
	readVector (luca);
	
	printVector (luca);
	
	cout<<"\nascending"<<endl;
	selectionSort_vector (luca, true);
	
	printVector (luca);
	
	cout <<"\ndescending"<<endl;
	selectionSort_vector (luca, false);
	
	printVector (luca);
	
	return 0;
}