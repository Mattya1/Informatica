#include <iostream>
#include <vector>
#include "cat.h"
#include "iovector.h"

using namespace std;

int main ()
{
	vector<int> first;	
	vector<int> second;

	cout<<"inserisci i valori del primo array: ";
	readVectorAlt (first);
	
	cout<<"\ninserisci i valori del secondo array: ";
	readVectorAlt (second);
	
	printVector (first);
	printVector (second);
	
	vector<int> total = cat(first, second);
	
	printVector (total);
	
	return 0;
}