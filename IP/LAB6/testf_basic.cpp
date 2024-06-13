// Esercizi di riscaldamento

#include <iostream>
using namespace std;

//e non riceve alcun argomento e non restituisce alcun valore
void hello ()	
{
	cout << "Hello, world\n";
}

//e riceve un argomento di tipo int e non restituisce alcun valore 
void hellomany (int n)
{
	cout <<"Hello, we are " << n << endl;
}

//non riceve alcun argomento e restituisce un valore di tipo int
int gimmefive()
{
	return 5;
}

//riceve un argomento di tipo int e restituisce un valore di tipo int
int prossimo (int n)
{
	return n+1;
}

//e riceve due argomenti di tipo int e restituisce un valore di tipo int
int somma (int a, int b)
{
	return a+b;
}



int main ()
{

hello();

hellomany(5);

cout << gimmefive() << endl;

cout << prossimo(4) <<endl;

cout << somma(2,3) << endl;



}