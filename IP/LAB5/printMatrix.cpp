//readmatrix + print matrix
#include <iostream>
using namespace std;

int main ()
{
	int M=3, N=4;
	int matrix[M][N];
	
	cout << "inserisci "<<M*N<<" elementi: "<<endl;
	for (int i=0; i<M; ++i)
	{
		for (int j=0; j<N; ++j)
		{
			cin >> matrix[i][j];
		}
	}
	
	cout << ""<<endl;
	for (int i=0; i<M; ++i)
	{
		for (int j=0; j<N; ++j)
		{
			cout <<matrix[i][j]<<"\t";
		}
		cout << ""<< endl;
	}
	
	return 0;
}