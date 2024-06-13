#include <iostream>
#include <cmath>
using namespace std;

struct Punto{		//mettendolo fuori si dice che è globale, lo vedono tutti
	double x;
	double y;
};

//devo mettere come argomento struct (che funzione come fosse int, float...)
// e il nome della variabile
double dist(Punto P, Punto Q)
{
	//ritorno la distanza con teorema di pitagora
	return sqrt((pow((P.x-Q.x),2) + pow((P.y-Q.y),2)));	
}


int main ()
{
	/*Punto p1;
	Punto p2;
	
	cout<< "inserisci le coordinate di P (x;y): ";
	cin >> p1.x >> p1.y;
	
	cout<< "\ninserisci le coordinate di Q (x;y): ";
	cin >> p2.x >> p2.y;*/
	
	int N=4, i;
	Punto arr[N];	//array di punti di forma struct
	double tot=0;
	
	for (i=0; i<N; i++)
	{
		cout << "\nInserisci le coordinate del "<< (i+1)<< " punto: ";
		cin >> arr[i].x >> arr[i].y;
		
		if(i>=1 && i<N){
		tot= tot+ dist(arr[(i-1)], arr[i]);}
		
	}
	
	cout << "\nLa lunghezza della spezzata e' " << tot;
	//d = dist(p1, p2); //passo l'intero punto!

}