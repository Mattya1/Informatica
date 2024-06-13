#include <iostream>

using namespace std;

int main ()
{
	const int N = 5;
	float v [N];
	int i;
	
// Dichiaro un puntatore a float e lo inzializzo con il valore di v
	float *p = v;
	
	cout << "Inserisci 5 numeri: ";

	for (i=0; i<N; i++){
		cin >> *p;
		p++;
	}
	
	p = v; //serve a far puntare il primo elemento di v
	
	for (i=0; i<N; i++){
		cout << *p << ", ";
		p++;
	}
	
	float sum=0;
	p = v; //serve a far puntare il primo elemento di v

	for (i=0;i<N;i++)
	{
		sum = sum + *p;
		p++;		
	}
	
	cout << "La media è: " << sum/N;
	
	return 0;	
}