#include <iostream>
#include <vector>
#include "sequentialSearch_vector.h"
using namespace std;

int sequentialSearch_vector (vector <int> &v, int item)
{
	/*int loc = -1;
	bool found =false; */
	
	for (unsigned int i =0; i<v.size(); ++i)
	{
		if (v[i]==item){
			//found = true;
			//loc = i;
			return i;
		}
	}	
	
	/*return loc;*/ return -1;
};