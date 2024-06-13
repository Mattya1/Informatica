/* Scrivere un programma che effettui la ricerca dell’elemento item (un intero) 
nell’array v (array di 15 interi ORDINATI letti da input).
[ File binarySearch.cpp ] */

#include <iostream>
using namespace std;

int binarySearch(const int list[], int lenght, int item)
{

	int first =0;
	int last = lenght - 1;
	int mid;
	bool found = false;

	while (first<=last && !found)
	{

		mid=(first+last)/2;
		if (list[mid]==item){
		found = true;}
		
		else if (list[mid]>item){
			last=mid-1;}			//item è nella prima metà
		else{
			first=mid+1;}			//item è nella seconda metà
		
	}
	
	if (found==true){
		return mid;}
	else{
		return -1;}

}



int main ()
{

	int n = 15;
	int i, v[n], item;

	cout << "inserisci v gia' ordinato: ";

	for (i=0; i<n; i++)
	{
		cin >> v[i];
	}
	
	cout << "\ninserisci cio' che vuoi cercare: ";
	cin >> item;
	

// inserire codice se ho voglia di ordinare v 

/* binarySearch funziona solo su seq. ordinate!
faccio una funzione a parte per farlo.
il concetto di base è che 

*/

	int esito = binarySearch(v, n, item);
	
	if (esito != -1){
		cout << "il valore che cerchi è nella posizione :"<< esito+1;}
	else{
		cout << "il valore che cerchi non c'e'";}
	

}