#include <iostream>
#include <vector>
#include "reverse_vector.h"
using namespace std;

vector<int> reverse (const vector <int> &v)
{
	vector<int> dest;
	
	for (int i=v.size()-1; i>=0; --i)
	{
		dest.push_back(v[i]);
	}
	return dest;
};
