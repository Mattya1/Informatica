//void read array!
#include <iostream>
#include "d_array.h"
using namespace std;
//passo dynamic_array per RIFERIMENTO (posso modificare direttamente, senza creare una copia)

//dynamic_array è il "tipo", e d il nome dell'array
//i campi sono 	double *store e unsigned int size;
void read_d_array(dynamic_array &d)
{
	int s = -5;
	
	while (s<=0)
	{
		cout << "Inserisci la dimensione dell'array: "<<endl;
		cin >> s;
	}
	
	d.size = s;

// allocare s double assegnando l'area di memoria riservata al campo store di d
	d.store = new double [s];
	
	for (int i=0; i<s; ++i)
	{
		cout<<"\nInserisci il "<< i+1 << "o valore: ";
		cin >> d.store[i];
	}

}