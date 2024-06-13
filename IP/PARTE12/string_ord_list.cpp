#include <iostream>
#include <string>
#include "string_ord_list.h"
 
using namespace std;
 
void insertElement (ordList &l, string s)
{
	cell *newCell = new cell;
	newCell -> data = s;
	newCell -> next = nullptr;
	
	cell *current =l;
	cell *aux = nullptr;
	
	while ((current!= nullptr )&& (current->data < s))
	{
		aux = current;
		current = current->next;
	}
	newCell->next = current;
	
	if (current == l)
		l = newCell;
	else
		aux->next = newCell;
	
};

void readList (ordList &l)
{
	string imput;
	
	while (true)
	{
		cout << "\nInserisci un dato da inserire: ";
		cin >> imput;
		
		if (imput == "STOP!" || imput == "n"){
			break;
		}
		
		insertElement (l, imput);
	}
	
};

void printList (const ordList &l)
{
	cell *conta;
	conta = l;
	
	cout << "\nLa lista contiene: ";
	
	while (conta != nullptr)
	{
		cout << conta->data <<" ";
			 // << &conta->data<<endl;

		conta = conta->next;

	}
	cout <<endl;
};

unsigned int listSize (const ordList &l)
{
	unsigned int size =0;
	cell *scan=l;
	
	while (scan->next != nullptr)
	{
		size++;
		scan = scan->next;
	}
	
	return size;
};

bool isEmptyList (const ordList &l)
{
	if (l==nullptr)
		return true;
	else
		return false;
};

string getElement (const ordList &l, unsigned int i)
{
	// string elem;
	if (i<0 || i> listSize(l)){
		throw string ("\nError: Index out of bound");
	}
	
	cell *search =l;
	
	for (unsigned int j=0; j<i; ++j)
	{
		search = search->next;
	}
	
	return search->data;
	
	// return elem;
};

void deleteElementAt (ordList &l, unsigned int i)
{
	if (i<0 || i> listSize(l)){
		throw string ("\nError: Index out of bound");
	}
	
	cell *current = l;
	cell *aux = nullptr;
	
	for (unsigned int j=0; j<i; ++j)
	{
		aux = current;
		current = current->next;
	}	
	
	aux->next = current -> next;
	delete current;
	current = aux;	
	
};

bool deleteElementOnce (ordList &l, string s)
{
	cell *scan =l;
	cell *aux = nullptr;
	
	while (scan!=nullptr)
	{
		if (scan->data == s)
		{
			if (aux == nullptr){
				l= scan->next;
			
			} else {
				aux->next = scan->next;
			}
			delete scan;	
			
			return true;
		}
		
		aux = scan;
		scan = scan ->next;
		
	}
	
	
	return false;
};
	
void deleteAllElements (ordList &l, string s)
{
	cell *current=l;
	cell *aux = nullptr;
	
	while (current!= nullptr && current->data <=s)
	{
		if (current->data == s){
			
			if (aux == nullptr)
			{
				l=current->next;
				delete current;
				current = l;
			
			} else {
				aux->next = current->next;
				delete current;
				current = aux ->next;
			}
		}
		
		aux = current;
		current = current->next;
	}	
};

bool listAreEqual (const ordList &l1, const ordList &l2)
{
	cell *list1 = l1;
	cell *list2 = l2;
	
	while (list1 != nullptr && list2 != nullptr)
	{
		if (list1->data != list2->data)
			return false;
		
		list1 = list1->next;
		list2 = list2->next;
		
	}
	
	return true;
};

ordList concatLists (const ordList &l1, const ordList &l2)
{
	ordList luca;
	
	if (l1== nullptr)
		return l2;
	else if (l2 == nullptr)
		return l1;
	
	
	cell * curr
	
	
	return luca;
	
};

