#include <iostream>
#include "allDiffArrayElements_funct.h"

using namespace std;

bool allDiffArrayElements (int *t, int size)
{
	int conta =0;
	
	//qua ciclo *t, che assegno a comp per essere a comparare
	for (int i=0; i < size; i++)
	{
		int comp = *t;
		conta=0;
				
		//qua comparo comp con tutto l'array
		for (int j=0; j<size;j++)
		{
			if (comp==*t)
			{
				conta++;
				if (conta ==2){
					return false;
				break;}
			}
					
			t++;
					
			//cout <<"\nfine "<<i<<" , "<<j<<" loop";
		}
		
			//resetto la posizione di t alla cella i
			t=((t-size)+i);
		
			t++;
	}

	return true;
	
}