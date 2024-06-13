#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "phoneBook.h"

using namespace std;

void push_contact_in_phoneBook(phoneBook &B, string surname, string name, string number)
{
	
	contact NewContact;
	//devo creare un contatto di tipo struct, non phonebook, perchè è il vector
	
	NewContact.surname = surname;
	NewContact.name = name;
	NewContact.phoneNumber = number;
	
	B.push_back(NewContact); //e poi pusho lo struct nel vect
	
};

void print_phoneBook (const phoneBook &B)
{
	
	for (unsigned long int i = 0; i<B.size(); ++i)
	{
		cout<< B[i].surname << " "
			<< B[i].name << " "
			<< B[i].phoneNumber <<endl;
	}
	
};

void read_phoneBook_from_file(phoneBook &B, string fileName)
{
	ifstream infile;
	infile.open ("readPhoneBookName.txt"); //apro il file
	
	int numb =0;
	infile >> numb; //la 1^ cosa scritta è il num degli elem
	
	contact cont; //nuovo contatto
	
	while (infile >> cont.surname >> cont.name >> cont.phoneNumber)
	{
		B.push_back(cont);
	}
	
	infile.close();
	
};

void write_phoneBook_to_file(const phoneBook &B, string fileName)
{
	ofstream outfile;
	outfile.open ("writePhoneBookName.txt");
	
	for (unsigned long int i =0; i<B.size(); ++i)
	{
		outfile << B[i].name << " "
				<<B[i].surname <<  " "
				<<B[i].phoneNumber <<endl;
		
	}
	
	outfile.close();
	
};

void sort_phoneBook_by_surnames(phoneBook &B)
{
	//devo fare un selectionsort
	
	for (unsigned int i =0; i<B.size()-1; ++i)
	{
		int index = i;
		
		for (unsigned int j = i+1; j<B.size(); ++j)
		{
			if (B[j].surname < B[index].surname)
				index = j;		
		}

//non posso storare un tipo contact in un int, quindi temp diventa di tipo struct contact		
		contact temp = B[i];	
		B[i] = B[index];
		B[index] = temp;
	}
	
};

bool find_phoneBook_contact_by_surname (const phoneBook &B, string s, unsigned long int &pos)
{
	//binarysearch assume che il vector sia ordinato
	
	int low = 0;
	int high = (B.size()-1);
	
	while (low <= high)
	{
		int mid = low + ((high - low) /2);
		
		if (B[mid].surname == s){ //S SAREBBE TARGET
			pos = mid;			
			return true;
			
		} else if (B[mid].surname < s) {
			low = mid +1;
		} else if (B[mid].surname > s){
			high = mid -1;
		}
	}
	
	return false; //se non l'ho trovato
	
};

void shift_phoneBook(phoneBook &B, unsigned long int pos)
{
	
	if (pos >= B.size()|| pos <0){
	throw string ("out of range");}
	
	B.push_back(B.back()); //aggiungo un posto alla fine
	for (unsigned long int i = B.size()-1; i> pos; --i)
	
	{
		B[i] = B[i-1];
	}
};

void add_contact_to_phoneBook (phoneBook &B, string surname, string name, string number)
{
	
	contact NewContact;
	
	NewContact.surname = surname;
	NewContact.name =name;
	NewContact.phoneNumber = number;
	
	if (B.size()==0){
		B.push_back(NewContact);
		return;
	}
	//scopro la posizione in cui dovrebbe stare
	unsigned long int pos =0;
	find_phoneBook_contact_by_surname (B, surname, pos);

	
	shift_phoneBook (B, pos);
	B[pos] = NewContact;

	
};