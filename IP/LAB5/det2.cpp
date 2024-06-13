//data matrice di float 2x2, trovare il determinante
/*data una matrice abcd
a	b
c 	d	il determinante è: ad-bc */
#include <iostream>
using namespace std;

int main()
{
	float A [2][2];
	
	//i righe, j colonne
	for (int i=0; i <2; i++)
	{
		for (int j=0; j<2; j++)
		{
			cout <<"inserisci elemento "<< i<<" "<<j<<": ";
			cin >> A [i][j];
		}
	}
	
	float det= ((A[0][0] * A [1][1])-(A[0][1] * A [1][0]));
	cout << "il determinante e': "<< det;
	
	return 0;
}