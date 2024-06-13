// FILE DA MODIFICARE
#include <iostream>
#include <fstream>
#include "ASD-doubly-linked-list.h"

using namespace list;
using namespace std;

/*Descrizione da come e' fatta  la struttura node. */
/*I dettagli interni non saranno visibili dal main*/
struct list::node {  
  Elem info;
  node *prev;
  node *next;
};

/**************************************************/
/*      funzioni da implementare                    */
/**************************************************/
  
/* crea la lista vuota */
void list::createEmpty(List& li){

	node *sent = new node;
	sent->next = sent;
	sent->prev = sent;

	//sent->info non contiene nulla
	li = sent;	
}

/* "smantella" la lista (tranne la sentinella) */
void list::clear(List& li){
	
	node *sent = li;
	node *aux = li->next; //punta già a dopo la sentina
	node *curr = nullptr;
	
	while (aux->next != sent)
	{
		curr = aux;
		aux = aux->next;
		delete curr;		
	}
	aux = nullptr;
	curr = nullptr;
	sent->next = sent;
	sent->prev = sent;
	
}

/* restituisce true se la lista e' vuota */
bool list::isEmpty(const List& li){
	
	node *aux = li;
	if (aux->next == aux) {
		return true;
	} else {
		return false;
	}	
}

/* restituisce la dimensione della lista */
unsigned int list::size(const List& li){
	
	//node *sent = li;
	// node *sent = li;
	node *aux = li;
	unsigned int conta = 0;
	
	while (aux->next != li)
	{
		conta ++;
		aux = aux->next;
	}
	
  return conta;
  
  // return 10;
}

/* restituisce l'elemento in posizione pos */
/* se pos non e corretta, solleva una eccezione di tipo string*/
Elem list::get(unsigned int pos, const List& li){
	
	unsigned int dim = size(li);
	
	if (pos >= dim){
		throw std::string ("Index>=size");
	}
	
	node *sent = li;
	node *aux = sent;
	
	for (unsigned int i = 0; i<pos; ++i)
	{
		aux = aux->next;
	}
		
  return aux->info;
}

/* modifica l'elemento in posizione pos */
/* se pos non e' corretta, solleva una eccezione di tipo string*/
void list::set(unsigned int pos, Elem el, const List& li){

	unsigned int dim = size(li);
	
	if (pos >= dim)
		throw std::string ("Index>=size");

	node *sent = li;
	node *aux = sent->next;
	if (pos == 0){
		aux->info = el;
	} else{
		
		for (unsigned int i=0; i < pos; ++i)
		{
			aux = aux->next;
		}
		
		aux->info = el;
	}
}

/* inserisce l'elemento in posizione pos*/
/*shiftando a destra gli altri elementi */
/*se pos non e' corretta, solleva una eccezione di tipo string*/
void list::add(unsigned int pos, Elem el, const List& li){
	
	unsigned int list_size = size(li);
	//controllo limiti di pos(<0 non lo può essere, è unsigned)
	if (pos > list_size)
		throw std::string ("Pos > Index");
	
	if (pos == 0)
		addFront (el, li);
	else if (pos == list_size)
		addRear (el, li);
	else {	
	
		node* newNode = new node;
		node* aux = li->next; //skippo la sentinella
		node* back = nullptr;
		
		for (unsigned int i = 0; i< pos; ++i)
		{
			back = aux;
			aux = aux->next; 
		}
		
		back->next = newNode;	//elem pos-1 punta al nuovo
		aux->prev = newNode;	
		
		newNode ->next = aux;	//punta a 
		newNode ->prev = back;
		newNode ->info = el;
		
	}

}

/* inserisce l'elemento alla fine della lista */
void list::addRear(Elem el, const List& li){
	
	//quindi per accedere all'ultimo elem accedo da sent->prev
	
	node* sent = li;	//sentinella
	node* aux = sent->prev;	//ex ultimo
	node* newNode = new node;
	
	newNode->prev = aux;
	newNode->next = sent;
	newNode->info = el;
	
	aux->next = newNode;
	sent->prev = newNode;
}

/* inserisce l'elemento all'inizio della lista */
void list::addFront(Elem el, const List& li) {
	
	node* newNode = new node;
	node* sent = li;
	node* aux = sent->next;
	
	newNode->prev = sent;
	newNode->next = aux;
	newNode->info = el;
	
	aux->prev = newNode;
	sent->next= newNode;
	
}

/* cancella l'elemento in posizione pos dalla lista */
/* se pos non e' corretta, solleva una eccezione di tipo string*/
void list::removePos(unsigned int pos,const List& li){
	
	unsigned int list_size = size(li);
	//controllo limiti di pos
	if (pos >=list_size){
		throw std::string ("Pos >= Index");
	}
	
	node* aux = li->next;
	// node* curr = nullptr;
	
	for (unsigned int i=0; i<pos; ++i) 
	{
		// curr = aux;
		aux = aux->next;
	}
	
	aux->prev->next = aux->next;
	aux->next->prev = aux->prev;
	delete aux;

}

/* cancella tutte le occorrenze dell'elemento elem*/
/*se presenti, dalla lista */
void list::removeEl(Elem el,const List& li){

	node* sent= li;
	node* aux= sent->next;
	node* cur= sent;
	// node* dopo= nullptr;
	
	
	while (aux->next != sent)
	{
		if (aux->info == el)
		{
			cur->next = aux->next;
            aux->next->prev = cur;
            delete aux;
            aux = cur->next; 
			
        }
			
		cur = aux; 
		aux = aux->next;
		
	}
	
	
}

/**************************************************/
/*      funzioni implementate                    */
/**************************************************/
  
/* riempie una lista da file */
void list::readFromFile(string name_file, const List& li){
  ifstream infile;
  string read_data;
  infile.open(name_file);
  while (getline (infile,read_data)){
    if(read_data.length()>0){
      addRear(stoi(read_data),li);
    }
  }
}

/* riempie una lista da standard input */
void list::readFromStdin(const List& li){
  cout << "Inserire una sequenza di numeri separati da spazi seguiti da END per terminare\n";
  string read_data;
  cin>>read_data;
  while(read_data!="END"){
    addRear(stoi(read_data),li);
    cin>>read_data;
  }
}

/* stampa la lista */
void list::print(const List& li){
  if(li==li->next){
    cout<<"vuota";
  }
  List cur = li->next;  // q "salta la sentinella" e va alla testa della lista
  while (cur != li) {   
    cout << cur->info;
    cur= cur->next;
    if(cur!=li) cout<<" <-> ";
  }
  cout<<endl;
}

/* produce una string contenendo la lista*/
std::string list::tostring(const List& li){
  string out="";
  if(li==li->next){
    out+="vuota";
  }
  List cur = li->next;  // q "salta la sentinella" e va alla testa della lista
  while (cur != li) {   
    out+=to_string(cur->info);
    cur= cur->next;
    if(cur!=li) out+=" <-> ";
  }
  return out;
}
