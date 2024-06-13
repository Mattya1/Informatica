//selectionsort di array
#include <iostream>
#include "d_array.h"
using namespace std;

void sort_d_array (dynamic_array &d)
{
//loop grande: seleziona l'elemento i e controlla chi è più piccolo nella zona restante (destra)
	for (unsigned int i=0; i<d.size-1; ++i)
	{
		int smallestIndex =i;
	//loop mini: parte da i+1 e cerca l'elemento più piccolo della zona unsortata
		for (unsigned int j=i+1; j < d.size; ++j)
		{
			//comparo e cambio smallestindex
			if (d.store[j]<d.store[smallestIndex])
				smallestIndex=j;
		}
		
		int temp= d.store[i];
		d.store [i] = d.store[smallestIndex];
		d.store [i] = temp;
		
	}
}