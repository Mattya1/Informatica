#include <iostream>
#include <cmath>
using namespace std;

void shiftLeft (int arr[], int D, int S)
{
	//primo loop per definire quanti shift fare
	for (int j=0; j<S; ++j)
	{
		//qua faccio effettivamente lo shift
		for (int i=0; i<D; ++i)
		{
			arr[i]=arr[i+1];
		}
		
		arr[(D-1)-j]=0;	//in questo modo dopo shift elimino l'1 cifra a dx per ogni shift
	}

}

void shiftRight (int arr[], int D, int S)
{	
	
	for (int j=0; j<D; ++j)
	{
		int temp=arr[(D-1)-j];
		
		for (int i = D; i>0; --i)
		{
			arr[i]=arr[i-1];
		}
		
		arr[0]=temp;
	}
	
}

int main ()
{
	int D=4, S;
	int arr[D]={1, 10, 15, 18};
	cout<<"inserisci lo shift";
	cin >> S;	
	
	if (abs(S)<D){
		
		if (S>=0)
			shiftRight(arr, D, S);
		else
			shiftLeft(arr, D, abs(S);
		
	}
	else if (abs(S)>D)
		cout
	else if (abs(S)>=D)
		cout<<"\nvettore vuoto";
	
	
	
	return 0;
}