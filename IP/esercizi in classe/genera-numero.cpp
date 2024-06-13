/* creo un programma che genera un num casuale tra 0 e 100 e chiede
all'utente di indovinarlo.
se l'utente indovina stampa un messaggio di complimenti
altrimenti fornisce un aiuto "il numero che proponi è maggiore/minore a quello
che devi indovinare. riprova"
il ciclo si chiude quando l'utente indovina */

#include <iostream>
#include <cstdlib> //rand e srand
#include <ctime>  //time

int main ()
{
// GENERO NUMERO da 0 a MAX-1: [0, MAX-1]
	const int MAX=10;
	const int MIN=2
	srand(time(0));
	
	int number =rand();
	
	std::cout << number << std::endl;
	
	number = MIN+number%(MAX-MIN+1); // rand [0 32767]
	
	//sto generando numeri che vanno da min (in questo caso 2) a 10

	std::cout << number << std::endl;

//CHIEDO ALL'UTENTE DI INDOVINARE NUMERO (CON UN MAX DI TENTATIVI)



}