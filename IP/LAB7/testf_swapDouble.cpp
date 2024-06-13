/* 1. Scrivere una funzione di nome swapDouble che prende due argomenti a e b di tipo double, e quando viene chiamata ne
scambia i valori, e restituisce void. */

#include <iostream>
using namespace std;

void swapDouble(double& x, double& y)
{
	double a, b;
	
	a = y;
	b = x;
	cout << a << " " <<b;

}

int main ()
{
	double a=10.5;
	double b=66.8;
	cout << a << " " <<b<<endl;
	
	swapDouble(a, b);	
	return 0;	
	
}