#ifndef STRINGORDLIST
#define STRINGORDLIST

#include <string>

struct cell {
	std::string data;
	cell *next;
};

typedef cell *ordList;

void insertElement 		(ordList &l, std::string s);
void readList 			(ordList &l);
void printList			(const ordList &l);
unsigned int listSize 	(const ordList &l);
bool isEmptyList		(const ordList &l);
std::string getElement	(const ordList &l, unsigned int i);
void deleteElementAt	(ordList &l, unsigned int i);
bool deleteElementOnce 	(ordList &l, std::string s);
void deleteAllElements	(ordList &l, std::string s);
bool listAreEqual 		(const ordList &l1, const ordList &l2);
ordList concatLists(const ordList &l1, const ordList &l2);


#endif