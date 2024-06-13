//qua TUTTE LE FUNZIONI
#include <iostream>
#include "my_vector.h"
using namespace std;

my_vector create_my_vector(unsigned int capacity)
{
		
	if (capacity <=0){
	throw string ("create_my_vector: capacity fornita non positiva");}
	
	my_vector v;
	
	v.capacity = capacity; //assegno la lunghezza massima
	v.size = 0; //size =0 perchè non è ancora popolato
	v.store = new double [capacity];
	return v;
};

void print_my_vector_status(const my_vector &v)
{
	cout<< "\n**********************"
		<< "\nmy_vector size\t= " << v.size
		<< "\nmy_vector capacity = " << v.capacity
		<< "\nmy_vector store\t= { ";
		
		if(v.size==0){
			cout <<" "; 
		}else{
			
			for (unsigned int i=0; i<v.size; ++i)
			{
				cout<<v.store[i];
					if (i<v.size-1)
						cout<<", ";
			}
		}

	cout << " }" <<	"\n**********************" << endl;
};

void push_back_my_vector_element(my_vector &v, double x)
{
	if (v.size == v.capacity){
		throw string ("push_back_my_vector_element: Impossibile inserire elemento in Array pieno");}
	
	v.store[v.size] = x;
	++v.size;
	
};

double pop_back_my_vector_element(my_vector &v)
{
	if (v.size == 0){
		throw string ("pop_back_my_vector_element: Impossibile estrarre elemento da Array vuoto");}
	double last_element = v.store [v.size-1];
	--v.size;
	
	return last_element;
};

void set_my_vector_element(my_vector &v, double value, unsigned int index)
{
	if (v.size==0)
		throw string ("set_my_vector_element: Impossibile impostare un elemento di un My_Vector vuoto");
	
	if (index<0 || index>=v.size)
		throw string ("set_my_vector_element: Indice fornito non ammissibile");
	
	v.store [index] = value;
};

double get_my_vector_element(const my_vector &v, unsigned int index)
{
	if (v.size==0)
		throw string ("get_my_vector_element: Impossibile impostare un elemento di un My_Vector vuoto");
	
	if (index<0 || index>=v.size)
		throw string ("get_my_vector_element: Indice fornito non ammissibile"); 

	return v.store [index];
};

void resize_my_vector(my_vector &v, unsigned int new_capacity)
{
	if (new_capacity<=0){
	throw string ("resize_my_vector: new_capacity fornita non positiva");}
	
	double *p = new double [new_capacity];

	
	if (v.size <= new_capacity){	//se new_capacity > v.size (quindi anche di v.store)
		for (unsigned int i=0; i<v.size; ++i)
		{
			p[i] = v.store[i];
		}
		
	} else if (v.size > new_capacity) {
		for (unsigned int i=0; i<new_capacity; ++i)
		{
			p[i] = v.store[i];
		}
		
		v.size = new_capacity;
	}

	if (v.capacity > 0){
		delete [] v.store;	//eliminio vecchia memoria
		v.store = p;	//assegno a store la nuova memoria
		v.capacity = new_capacity; //aggiorno la capacity
	}
	
};

void safe_push_back_my_vector_element(my_vector &v, double x)
{
	if (v.capacity ==0){
		v.capacity=1;
	} else if (v.capacity ==v.size) {
		resize_my_vector(v, v.capacity * 2);}
		
	v.store[v.size] = x;
	++v.size;

};

void destroy_my_vector(my_vector &v)
{
	if (v.capacity > 0){
		delete [] v.store;
		v.size=0;
		v.capacity = 0;
	}
	//altrimenti, se capacity == 0 non serve 
};

bool looks_consistent_my_vector(const my_vector &v)
{
	return (v.store != 0 && v.size >0 && v.size < v.capacity && v.capacity >0);
};

void sort_my_vector(my_vector &v)
{
	//selectionsort
	for (unsigned int i=0; i< v.size; ++i)
	{
		unsigned int smallestElement = i;
		
		for (unsigned int j=i+1; j< v.size; ++j)
		{
			if (v.store[j] < v.store [smallestElement])
			{
				smallestElement = j;
			}
		}
		
		double temp = v.store[i];
		v.store[i] = temp;
		v.store[smallestElement] = v.store [i];
	}

};