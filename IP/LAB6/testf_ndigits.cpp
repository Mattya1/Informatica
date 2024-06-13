#include <iostream>
using namespace std;

int getLenght(int num)
{	
	int conta=0;
	while (num>0)
	{
		num=num/10;
		conta++;
	}
	
return conta;
}

int main ()
{
	int test[]={1,15, 5789, 123456789, 55, 8898};
	int i;
	
	for (i=0; i<6; i++)
	{
		cout << "la lunghezza di "<< test[i]<< " e' "<<getLenght(test[i])<<endl;
	}
}
	
