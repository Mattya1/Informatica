#include <iostream>
#include <string>
#include "string_list.h"

using namespace std;

void headInsert (list &l, std::string s)
{
	cell *aux = new cell;	//creo var ausiliaria di tipo ptr a cell 
	aux -> data = s; //inserisco x nel campo info
	aux -> next = nullptr;; 
	
	if (l == nullptr) {
        l = aux;
    } else {
        // Se la lista non è vuota, il nuovo nodo diventa la nuova testa e punta al nodo precedente della lista
        aux->next = l;
        l = aux;
    }
	// l = aux; //ora aux è la testa della lista
};

void tailInsert (list &l, std::string s)
{
	cell *newCell = new cell; //devo creare la memoria
	newCell->data = s;
	newCell->next = nullptr; //altrimenti è vagante
	
	if (l==nullptr){
		headInsert(l, s); //quindi se la lista è vuota, diventa la testa
	} else {
		cell *current = l; 
		//creo un ptr per scorrere la lista a partire dalla testa, head
		
		//scorro finchè non trovo un next che non punta a nulla, che quindi è l'ultimo elemento
		while (current->next != nullptr)
		{
			current = current->next;
			//sposto il puntatore alla cella successiva
		}
		
		current -> next = newCell; //ora metto newCell come ultimo elemento
	}	
	
};

void read (list &l)
{
	string imput;
	
	while (true)
	{
		cout << "\nInserisci un valore: ";
		cin >> imput;
		
		if (imput == "stop" || imput == "STOP!" || imput == "n"){
			break;
		}
		
		tailInsert(l, imput);
		
	}
};

void print (const list &l)
{
	cell *conta;
	conta = l;
	
	cout << "la lista contiene: ";
	
	while (conta != nullptr)
	{
		cout << conta->data <<" ";
		conta = conta->next;
	}
	cout <<endl;
};

unsigned int size (const list &l)
{
	unsigned int count =0;
	
	cell *search = l; //creo un puntatore 
	
	while (search != nullptr)
	{
		count ++;
		search = search->next;
	}
	
	return count;
};

bool isEmpty (const list &l)
{
	if (l==nullptr)
		return true;
	else
		return false;
};

string getElem (const list &l, unsigned int i)
{
	cell *search = l;
	
	for (unsigned int j =0; j<i; ++j)
	{
		search = search->next;
	}
	
	return search->data;
	
};

void insertAt (list &l, string s, unsigned int i)
{
	
	if (l == nullptr){
		throw string ("\nLa lista e' vuota!");
	} else if ( i > size(l) || i < 0){
		throw string ("\nIndice non valido!");
	}

	if (i==0){
		headInsert (l, s);
	} else if (i == size(l)) {
		tailInsert(l, s); 
	} else {
		//creo memoria per il nuovo slot e lo inizializzo
		cell *NewCell = new cell; 
		NewCell->data = s;
		NewCell->next = nullptr;
		
		cell *prima = nullptr; //creo un ptr per tenere quello prima
		cell *current = l; //questo per dove sono ora
		unsigned int conta =0;
		
		while (current->next != nullptr && conta < i)
		{
			prima = current;
			current = current->next;
			conta ++;
		}
		
		//newcell deve stare tra "prima" e "current"		
		NewCell->next = current; //newcell punta a current
		prima->next = NewCell; //prima punta a newcell

		//NON DEVO DEALLOCARE MEMORIA O PUNTATORI
	}
};

void deleteAt (list &l, unsigned int i)
{
		if (l==nullptr){
		throw string ("\nList is empty");
	} else if (i<0 || i > (size(l))) {
		
		throw string ("\nIndex out of bounds");
	}
	
	cell *current = l;
	cell *aux = nullptr;
	
	if (i==0){
		l= current->next;
		delete current;
	}
	
	for (unsigned int j =0; j<i; ++j)
	{
		aux = current;
		current = current ->next;
	}
	
	aux->next = current->next;
	delete current;	

};

bool deleteOnce (list &l, string s)
{
	if (l==nullptr){
		throw string ("\nList is empty");
	}
	
	cell *current =l;
	cell *aux= nullptr;
	
	while (current!= nullptr)
	{
		if (current->data == s){
			
			if (aux == nullptr)
			{
				l= current->next;
			} else {
				
				aux->next = current->next;
				
			}
			delete current;
			return true;
		}
		aux = current;
		current = current->next;
	}
	
	return false;
	
};

void deleteAll (list &l, string s)
{
	unsigned int count=0;
	
	if (l==nullptr){
		throw string ("\nList is empty");
	}
	
	cell *current = l;
	cell *aux = nullptr;
	
	while (current != nullptr)
	{		

		if (current->data == s) //se l'ho trovato
		{
			if (aux==nullptr){ //vuol dire che è la testa della lista
				
				l=current->next;
				
			} else {
				
				aux->next =current->next;
			}
			
			delete current; //è quello che viene eliminato
			count++;
			
			current = aux->next; //lo sposto all'elem successivo

			//quello prima punta a dopo quello da elminare
			
		} else { //altrimenti continuo scansione
			
			aux = current;
			current = current->next;			
		}	
	}
	
	if (count >0)
		cout << "\n" << count << " elemento/i eliminati."<<endl;
	else 
		cout << "\nNessun elemento eliminato."<<endl;
	
};

/*
void deleteList(list& l) {
	
    while (l != nullptr) {
        cell* temp = l;
        l = l->next;
        delete temp;
    }
};


*/