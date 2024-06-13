//prende un elemento dall'array
#include <iostream>
#include <string>
#include "d_array.h"
using namespace std;

double get_d_array_element(const dynamic_array &d, unsigned int index)
{
	if (index>d.size || index < 0){
		throw "Index out of range";}
//facendo così, l'errore viene sollevato come array di char
//va catchato con const char* err 
		
	return d.store[index];
}