/* . Scrivere una funzione computeRectInfo(...) con 4 argomenti di tipo double: l1, l2, area, e perimentro. I due ultimi parametri
sono usati per fornire in output i valori di area e perimento del rettangolo di lunghezza l1 e altezza l2. Nel caso in cui l1
e/o l2 siano negativi sollevare un’eccezione di tipo string con il messaggio opportuno (3 messaggi possibili).
[SUGGERIMENTO: Ricordiamo che il passaggio per riferimento consente ad una funzione di "ritornare" più valori di output.]
[ File testf_RectInfo.cpp ] */

#include <iostream>
using namespace std;


void computeRectInfo(double l1, double l2, double& area, double& perimetro)
{
	//controllo
	if (l1 < 0 && l2 <0){
		int err = -3;
		throw err;
	}else if (l1 <0){
		int err = -2;
		throw err;
	}else if (l2 <0){
		int err =-1;
		throw err;
	}
	
	area = l1*l2;
	
	perimetro= (l1+l2)*2;	
}

int main ()
{
	double lato1, lato2;
	double area =0;
	double perimetro=0;
	
	cout<<"Inserisci i due lati: ";
	cin >> lato1 >> lato2;
	
	try{
	
	computeRectInfo(lato1, lato2, area, perimetro);
	
	cout << "L'area e' " << area << "\nIl perimetro e': " << perimetro;
	
	}
	catch (int& err)
	{
		if (err ==-3)
			cout << "Entrambi i lati non validi";
		else if (err==-2)
			cout << "Lato 1 non valido";
		else if (err ==-1)
			cout << "Lato 2 non valido";
	}
		
	
return 0;	
}