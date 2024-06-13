#include <iostream>
#include <string>
#include "string_ord_list.h"
 
using namespace std;
 
int main ()
{
	ordList lista = nullptr;
	
	// cout << "\ninserisco"<<endl;
	// insertElement (lista, "primo");

	// cout << "\ninserisco";
	// insertElement (lista, "secondo");

	// cout << "\ninserisco";
	// insertElement (lista, "terzo");
	
	// printList (lista);
	
	// cout <<"\nIinserisco con read";
	
	readList (lista);
	
	printList (lista);
	
	// cout << "\nLa lista e' lunga: "<< listSize(lista)<<endl;
	
	// cout<< "\nLa lista 1 e' vuota?: "
		// << boolalpha << isEmptyList (lista);	
	
	ordList lista2 = nullptr;
	
	// cout<< "\nLa lista 2 e' vuota?: "
		// << boolalpha << isEmptyList (lista2);
	
	// cout<< "\nL'elemento 5 e': " << getElement (lista, 5);
	
	// deleteElementAt (lista, 3);
	
	// printList (lista);
	
	// deleteAllElements (lista, "luca");

	// printList (lista);
	
	readList (lista2);
	
	cout << "\nAre equal?"<< boolalpha <<
	listAreEqual (lista, lista2)<<endl;
	
	ordList unione = concatLists (lista, lista2);
	
	printList(unione);
	
	
	
	
	
	
	
	
	
	return 0;
}