#include <iostream>
#include "printArray_funct.h"

using namespace std;

//passo il puntatore al primo elemento di s
void printArray(int *s, int size)
{
	cout << "\nPrint Array"<<endl;

	for (int i=0; i<size; i++)
	{		
		//stampo il contenuto dell'indirizzo puntato da s
		cout << *s << ", ";
		//incremento s per cambiare posizione dell'array
		s++;	
	}
}

//passo tutto s mettendo "[]"
void printArrayWithIndex(int s[], int size)
{
	cout << "\nPrint Array With Index"<<endl;
	for (int i=0; i<size; i++)
	{	
		//stampo s iterandolo direttamente
		cout << s[i] << ", " ;	
	}

}