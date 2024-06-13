//leaks.cpp
#include <iostream>
using namespace std;

int main ()
{
	const int N = 5;
	int *p, *v;
	
// allocare una quantità di memoria pari a N int, assegnandola a v
	v=new int [N];

// allocare una quantità di memoria pari a N int, assegnandola a p
	p=new int [N];
	
	int caso;
	cout << "scegli il caso: ";
	cin >> caso;
	
	if (caso == 1){
	//CASO 1 UNICO CORRETTO
	delete [] v;
	v = nullptr;
	
	delete [] p;
	p = nullptr;	
	}else if (caso == 2){
	
	//CASO 2
	v = new int [N];
	delete [] v;
	delete [] p;			
	} else if (caso == 3){
		
	//CASO 3
	p = v;
	delete [] v;
	} else if (caso == 4) {
		
	//CASO 4
	delete [] v;
	v = nullptr;
	delete [] p;
	p =	nullptr;
	
	}
	
	return 0;
}