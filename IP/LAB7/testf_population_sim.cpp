/* La crescita della popolazione in una città può essere stimata a partire dalla popolazione iniziale, aumentata di una certa percentuale (le nascite al netto delle morti) e di un numero (le persone che ci si trasferiscono al netto di quelle che
l’abbandonano).
Scrivere una funzione che presi come argomenti un intero non negativo (la popolazione iniziale), la percentuale di nascite
al netto delle morti come intero fra −100 e 100 e il numero di persone che si trasferiscono nella città al netto di quelle che
l’abbandonano, restituisce un intero pari al numero di abitanti dopo un anno.
Si noti che sia la percentuale di nascite al netto delle morti che il numero di persone che si trasferiscono nella città al netto
di quelle che l’abbandonano possono essere negativi, positivi o nulli.
Nei casi particolari in cui il risultato della simulazione fornisca un numero negativo la funzione ritorna zero.
[ File testf_population_sim.cpp ]
[SUGGERIMENTO: si noti che tutti i parametri sono interi, per cui usando moltiplicazione e divisione fra interi (nel giusto
ordine) il risultato sarà ancora un intero.] */

#include <iostream>
using namespace std;

int nascitePercent (int nascite, int morti)
{
	//faccio diventare nascite-morti un double, e lo converto poi in int
    if (nascite >0)
		return static_cast<int>((static_cast<double>(nascite - morti) / nascite) * 100);
	else{
		return 0;
	}
	
}

int oneYear (int popolazione, int netto, int trasferiti)
{
	int result;
	
	result = (popolazione*netto)+trasferiti;	
	
	
	if (result <= 0)
		return 0;
	else
		return result;
}

int main ()
{
	int population;
	cout << "Inserisci la popolazione: ";
	cin >> population;
	
	int nati;
	cout << "\nInserisci le nascite: ";
	cin >> nati;
	
	int morti;
	cout << "\nInserisci le morti: ";
	cin >> morti;
	
	int nuovi;
	cout << "\nInserisci i trasferimenti: ";
	cin >> nuovi;
	
	int netto = nascitePercent(nati, morti);
		
	cout << "la crescita in un anno sara' di " << oneYear (population, netto, nuovi) << " persone";	
	
	return 0;
}