#ifndef STRINGLIST
#define STRINGLIST
#include <string>

struct cell{	//elemento della lista
	std::string data;
	cell *next;
};

typedef cell *list;

void headInsert (list &l, std::string s);
void tailInsert (list &l, std::string s);
void read		(list &l);
void print		(const list &l);
unsigned int size (const list&l);
bool isEmpty 	(const list &l);
std::string getElem (const list  &l, unsigned int i);
void insertAt 	(list &l, std::string s, unsigned int i);
void deleteAt 	(list &l, unsigned int i);
bool deleteOnce (list &l, std::string s);
void deleteAll	(list &l, std::string s);
// void deleteList (list &l);


#endif