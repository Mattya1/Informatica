#include <iostream>
#include <string>
#include "string_list.h"

using namespace std;

int main ()
{
	//definisco una lista
	list lista = nullptr;
	
	// headInsert (lista, "primo");
	
	
	// tailInsert (lista, "ultimUno");

	read(lista);

	tailInsert (lista, "ultimo");

	headInsert(lista, "primo");

	cout << "\nprint\n";
	print(lista);	
	
	cout << "\nLa dimensione della lista e' di "<< 
	size(lista)	<< " elementi."<<endl;
	
	cout << "Verifichiamo se è 'lista' e' vuoto: ";
	cout << boolalpha <<isEmpty (lista);
	
	list secondlist = nullptr;
	cout << "\nVerifichiamo se è 'secondlist' e' vuoto: ";
	cout << boolalpha << isEmpty (secondlist);
	
	cout << "\nIl "<< 4 << "^ elemento e' : " << 
	getElem (lista, 4)<<endl;
	
	insertAt (lista, "pappoppero", 5);
	cout <<endl;
	print(lista);
	
	deleteAt(lista, 3);
	
	cout << "\nL'elemento 6 è stato eliminato? "<<
	boolalpha << deleteOnce (lista, "6")<<endl;
	
	deleteAll (lista, "3");
	
	
	
	
	
	
/*	deleteList (lista);
	cout << "Verifichiamo se è 'lista' e' vuoto: ";
	cout << boolalpha <<isEmpty (lista);
	*/

	
	return 0;
}