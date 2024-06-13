//programma che prende in input 20 numeri interi e li stampa in ordine decrescente

#include <iostream>
using namespace std;

int main ()
{
	const int N = 20;
	int v[N], i;
	
	cout << "Inserire valori dell'array: ";
	for ( i =0; i<N; ++i)
	{
		cin >> v[i];
	}
	
	cout << "\ni valori inseriti nell'array sono: ";
	for (i=0; i<N-1; ++i)
	{
		cout<<v[i]<< ", ";
	}
	cout<< v[N-1];
	
	//selectionsort
	int greatestIndex;
	for (int i=0; i<N; ++i)
	{
		greatestIndex = i;
		
		for (int j=i+1; j<N; ++j)
		{
			if (v[j] < v[greatestIndex]){
				greatestIndex = j;}
		}
	
		v[i] = v[greatestIndex];
	}
	
	//stamparray
	cout << "\nvalori nell'array ordinati: ";
	for (i=0; i<N-1; ++i)
	{
		cout<<v[i]<< ", ";
	}
	cout<<v[N-1];
	
	return 0;
}