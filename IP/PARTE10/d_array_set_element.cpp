//La funzione assegna 'value' all’elemento con indice 'index' di d.store
#include <iostream>
#include "d_array.h"
using namespace std;

void set_d_element(dynamic_array &d, unsigned int index, double value)
{
	try{
		if (index>d.size || index < 0){
		throw -1;}
		
		d.store[index] = value;
		
	} catch (int e) {
		cout << "\nIdex out of range.";
	}
}