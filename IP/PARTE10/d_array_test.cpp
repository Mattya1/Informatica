//FILE DI TEST
#include <iostream>
#include "d_array.h"
using namespace std;

int main ()
{
	//il "tipo" è din array, perchè dichiaro che fa parte della classe!
	dynamic_array luca;		//dichiaro array
	
	read_d_array (luca);	//lo creo e popolo
	
//	cout << "\n";
//	print_d_array(luca);	//lo stampo
	
//fino a qua non ho deallocato la memoria usata per luca.store, risulta errore.

	cout<<"\nelimino: ";
	delete_d_array(luca); //ORA ho eliminato la memoria.
	
	cout<<"\nricreo e popolo con il valore 2.7";
	create_d_array(luca, 5, 2.7);
	
	print_d_array(luca);
	
/*	cout<<"\n\nin posizione 3 andrà un 8";
	set_d_element(luca, 3, 8);
	
	print_d_array(luca);
	
//"gioco" ancora un po' con l'array prima di eliminare la memoria
	
	//voglio un elemento dell'array
	
	cout<< "\nl'elemento 2 dell'array è ";
	
	
	try{
		cout << get_d_array_element(luca, 9);
	} catch (const char* azzz) {
//lo catcho così perchè sollevato con throw 'messaggio', ovvero un arr di char
		
	cout << "\nErrore: "<< azzz <<endl; }
	
	
	cout << "\n";
	print_d_array(luca);

*/
	
	dynamic_array giorgio;
	
	read_d_array (giorgio);
	
	delete_d_array (giorgio);
	
	create_d_array (giorgio, 9, 87);
	
	print_d_array (giorgio);
	
	dynamic_array sum;
	
	concat_d_arrays(giorgio, luca, sum);
	
	print_d_array (sum);
	
	sort_d_array (sum);
	
	print_d_array(sum);
	
	delete_d_array(luca);
	delete_d_array(giorgio);
	delete_d_array(sum);
	return 0;
}