#include <iostream>
#include <vector>
#include <string>
#include "phoneBook.h"

using namespace std;

int main ()
{
	/*phoneBook rubrica;
	
	//devo passare i campi come stringa PD
	push_contact_in_phoneBook(rubrica, "pazzo", "luca", "3923430088");
	push_contact_in_phoneBook(rubrica, "gesualdo", "sexy", "3923434488");

					//il nome del file sempre come stringa
	read_phoneBook_from_file(rubrica, "readPhoneBookName.txt");
	
	write_phoneBook_to_file(rubrica, "writePhoneBookName.txt");

	cout << "\nbefore sorting:"<<endl;
	print_phoneBook(rubrica);
	
	sort_phoneBook_by_surnames(rubrica);
	
	cout << "\nnow sorted for surname:"<<endl;
	print_phoneBook(rubrica); */
	
	
	//main di chatgpt x fare prima
	
	    phoneBook myPhoneBook;

    // Aggiungiamo alcuni contatti di test
    push_contact_in_phoneBook(myPhoneBook, "Rossi", "Mario", "1234567890");
    push_contact_in_phoneBook(myPhoneBook, "Bianchi", "Luigi", "0987654321");

    // Stampiamo la rubrica
    cout << "Rubrica telefonica:" << endl;
    print_phoneBook(myPhoneBook);

    // Leggiamo la rubrica da un file
    read_phoneBook_from_file(myPhoneBook, "readPhoneBookName.txt");

    // Ordiniamo la rubrica per cognomi
    sort_phoneBook_by_surnames(myPhoneBook);

    // Stampiamo nuovamente la rubrica
    cout << "\nRubrica telefonica ordinata per cognomi:" << endl;
    print_phoneBook(myPhoneBook);

    // Cerchiamo un contatto per cognome
    unsigned long int pos;
    string searchSurname = "Rossi";
    if (find_phoneBook_contact_by_surname(myPhoneBook, searchSurname, pos)) {
        cout << "\nContatto trovato: " << endl;
        cout << "Posizione: " << pos << endl;
        cout << "Cognome: " << myPhoneBook[pos].surname << ", Nome: " << myPhoneBook[pos].name << ", Numero: " << myPhoneBook[pos].phoneNumber << endl;
    } else {
        cout << "\nContatto con cognome " << searchSurname << " non trovato." << endl;
    }

    // Aggiungiamo un nuovo contatto
    add_contact_to_phoneBook(myPhoneBook, "Verdi", "Giuseppe", "9876543210");

// cout<<"\nciuppala"<<endl;
    // Scriviamo la rubrica aggiornata su un file
    write_phoneBook_to_file(myPhoneBook, "writePhoneBookName.txt");
	
	
	
	return 0;
}