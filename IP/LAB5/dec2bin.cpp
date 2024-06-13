#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	const int N=10;
	int num=0;
	
	cout<< "Inserisci un numero tra 0 e 1024: ";
	cin >> num;
	
	if (num<0 || num >= pow(2,N)){
		cout << "Numero NON valido";
	return -1;}
	
	int binary [N];
	
	for (int i=N-1; i >=0; --i)
	{
		//cout<<"\ncella " << i << endl;
		binary[i]= num%2; 
		num=num/2;
	}
	
	cout<< "\nConvertito: ";
	
	for (int i=0; i<N-1; ++i)
	{
		cout<<binary[i]<< ", ";
	}
	cout << binary[N-1];
	
	return 0;
}