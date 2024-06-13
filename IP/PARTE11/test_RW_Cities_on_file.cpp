#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct city {
	string name;
	int inhabitants;
};

typedef vector <city> cities;
//serve per dare nomi alternativi a tipi di dato esistenti troppo ingombranti

void write_cities_to_file (const cities &vect, string citiesToWrite)
{
	ofstream outfile;
	outfile.open(citiesToWrite); //apro il file
	
    if (!outfile) {
        cerr << "Error opening file for writing: " << citiesToWrite << endl;
        return;
    }

	
	for (unsigned int i=0; i< vect.size(); ++i)
	{
		outfile << vect[i].name << " "<< vect[i].inhabitants <<endl;
	}
	
	outfile.close(); //chiudo il file
}

void read_cities_to_file (cities &vect, string citiesToRead)
{
	ifstream infile; //infile è l'oggetto che si usa per leggere i dati
	infile.open(citiesToRead); //apro il file
	
    if (!infile) {
        cerr << "Error opening file for reading: " << citiesToRead << endl;
        return;
    }

	
	int numb=0;
	infile>> numb; //qua prendo il 5 di inizio file (numero delle città)
	
//infile >> data; legge una stringa dal file fino a uno spazio e la mette nella variabile a destra	
	
	city newCity; //newCity è una variabile di tipo city
	
	//leggo nome e popolazione di ogni città nel file con un loop
	
	for (int i=0; i<numb; ++i)
	{
		infile >> newCity.name >> newCity.inhabitants;
		vect.push_back(newCity);
	}	
	
/*	posso usare anche while, nel caso non sapessi il numero di città

	while (infile >>newCity.name >> newCity.inhabitants){
		vect.push_back(newCity);}
*/
	infile.close(); //chiudo il file
}

int main ()
{
	cities luca;	//vector di struct "city" denominato luca
	
	read_cities_to_file(luca, "citiesToRead.txt");
	write_cities_to_file(luca, "citiesToWrite.txt");
	
	return 0;
}