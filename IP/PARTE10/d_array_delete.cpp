//void delete array, così LIBERO la memoria occupata
#include <iostream>
#include "d_array.h"
using namespace std;

void delete_d_array(dynamic_array &d)
{
	try
	{
		if (d.size>0){
			delete [] d.store;
			d.size=0;
			cout << "\ndeleted."<<endl;
		} else {
			throw -1;
		}
	}
	catch(int e){
		cout << "\nArray gia' eliminato."<<endl;
	}
	
}