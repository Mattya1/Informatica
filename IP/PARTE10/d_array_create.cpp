//funzione che modifica un array con dimensione 0, ne modifica la dimensione e lo ripopola con 1 valore.
#include <iostream>
#include "d_array.h"
using namespace std;

void create_d_array(dynamic_array &d, int size, double value)
{
	try{
		char choice;
		//devo controllare che l'array sia vuoto
		if (d.size==0){

			d.size = size; //nuova dimensione
			
			d.store = new double [size];
//tradotto, d.store è un array di double lungo size

			//inizializzo tutti gli elementi a value
			for (int i=0; i<size; ++i){
				d.store[i] = value;}
			

		} else if (d.size>0){
			cout << "l'array non e' vuoto. procedere all'eliminazione? (y/n)";
			cin>> choice;
			
			if (choice=='y')
				delete_d_array(d);
			else{
				cout<<"\nnon eliminato";}		
			
		} else {
			throw -1;
		}
		
	}catch (int e) {
		cout <<"dimensione negativa";
	}
	
}