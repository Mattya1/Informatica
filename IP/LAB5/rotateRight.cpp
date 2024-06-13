#include <iostream>
using namespace std;

int main ()
{
	int D=4, temp;
	int arr[D]={1, 10, 15, 18};
	
	temp=arr[D-1];	
	
	//copio il contenuto dell'indice minore in quello maggiore
	for (int i = D; i>0; --i)
	{
		arr[i]=arr[i-1];
		//cout<<arr[i]<<endl;
	}
	
	arr[0]=temp;
	
	cout<<"\ncontiene: ";
	for (int i=0; i<D-1; ++i)
	{
		cout<<arr[i]<< ", ";
	}
	cout<<arr[D-1];
	
	return 0;
}