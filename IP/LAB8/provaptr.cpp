/* (Puntatori) Scrivete un programma in cui usate i puntatori per accedere alle locazioni di variabili. Siete incoraggiati a
migliorare i messaggi di stampa minimali proposti nell’esercizio in modo da capire più facilmente quali valori state stampando, ad esempio aggiungendo frasi come indirizzo di s1 == oppure valore di p ==. A inizio esecuzione si ha s1="Hello" e
s2="World" mentre a termine esecuzione s1="Ciao" e s2="Mondo". Tutte le modifiche per sostituire le stringhe sono effettuate
tramite il puntatore p. Analizzare i valori e gli indirizzi restituiti e verificare che il comportamento sia corretto. */

#include <iostream>
using namespace std;

int main (){
	string s1 = "Hello", s2 = "World";
	
	cout << "Variabile s1: " << s1 << "\tindirizzo: " << &s1 << endl;
	cout << "Variabile s2: " << s2 << "\tindirizzo: " << &s2 << endl;
	
	string* p = &s1; 	//inizializzata all'indirizzo di s1
						//p = Hello - s1 = Hello
	
	cout  << "\nsto operando nell'area di s1"<< endl;
	cout << "\np contiene " << p <<
		"\nmentre con *p si ottiene " << *p;	
	
	*p = "Ciao";		//p = Ciao - s1 = Ciao
	
	cout << "\np contiene " << p <<
		"\nmentre con *p si ottiene " << *p<<endl;		

	p = &s2;			//p = World -
	
	cout  << "\nsto operando nell'area di s2"<< endl;

	cout << "\np contiene " << p <<
		"\nmentre con *p si ottiene " << *p;	

	*p= "Mondo";		//p = Mondo
	
	cout << "\np contiene " << p <<
		"\nmentre con *p si ottiene " << *p<<endl;	
	
	cout << "\nVariabile s1: " << s1 << "\tindirizzo: " << &s1 << endl;
	cout << "Variabile s2: " << s2 << "\tindirizzo: " << &s2 << endl;

return 0;	
	
}