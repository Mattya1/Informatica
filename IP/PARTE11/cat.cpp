#include <iostream>
#include <vector>
#include "cat.h"

using namespace std;

vector<int> cat (const vector<int> &v1, const vector<int> &v2)
{
	vector<int> tot;
	
	for (unsigned int i=0; i<v1.size(); ++i)
	{
		tot.push_back(v1[i]);
	}
	
	for (unsigned int j=0; j<v2.size(); ++j)
	{
		tot.push_back(v2[j]);
	}
	
	return tot;
	
};