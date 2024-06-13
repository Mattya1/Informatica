//programma che verifica se una matrice è simmetrica
#include <iostream>
using namespace std;

int main ()
{
	int N;
	cout << "Inserisci il lato della matrice: ";
	cin >>N;
	
	//matrice
	int matrix [N][N];
	
	//inserisco dati nella matrice
	for (int i=0; i<N; ++i)
	{
		for (int j=0; j<N; ++j)
		{
			cout <<"\ninserisci elemento "<< i<<" "<<j<<": ";
			cin >> matrix [i][j];
		}
	}
	
	//controllo simmetria
	cout << "\ncontrollo simmetria: ";
	
	//i righe, j colonne
	for (int i=0; i<N; ++i)
	{
		for (int j=0; j<N; ++j)
		{
			if (matrix[i][j] != matrix [j][i])
			{
				cout<< "Non e' simmetrica";
				return -1;
			}
		}		
	}
	
	cout << "La matrice e' simmetrica";
	
	
	return 0;
}