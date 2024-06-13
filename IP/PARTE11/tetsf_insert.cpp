#include <iostream>
#include <vector>
#include "iovector.h"
#include "insert.h"

using namespace std;

int main()
{
	try {
		vector <int> vecty;
		
		// insert (vecty, 2, 45); //ins a v vuoto
		
		readVectorAlt (vecty); //lo popolo
		
		// cout<< "pos 0"<<endl;
		insert(vecty, 0, 96);  //ins in pos zero
		
		// cout<< "pos finale"<<endl;

		insert(vecty, vecty.size(), 96);  //ins in coda (dopo ultima pos)
		
		// cout<< "pos 4"<<endl;

		insert(vecty, 4, 96);  //ins in pos generica
		
		printVector(vecty);
		
	} catch (string e) {
		cout << "\n" << e;
	
	}
		
	return 0;
}