/* */


#include <iostream>
using namespace std;

struct Point {
double x;
double y;
};

void swapPoint(Point& P1, Point& P2)
{
// scambiare i valori x e y tra P1 e P2
	double x;
	x= P1.x;
	P1.x = P2.x;
	P2.x = x;
	x=P1.y;
	P1.y = P2.y;
	P2.y= x;
}

void printPoint(const Point& P)
{
	// stampare le coordinate x e y di P
	cout << "(" << P.x << " , "<< P.y << ")"<<endl;
}

int main ()
{
	// dichiarare due punti P1 e P2
	Point P1, P2;

	// assegnare valori a scelta a P1 e P2
	P1 = {10.5, 7.4};
	P2 = {12, 78};
	// stampare P1 e P2 usando printPoint(...)
	cout << "\nP1: ";
	printPoint(P1);
	cout << "\nP2: ";
	printPoint(P2);
	// scambiare valori P1 e P2 usando swapPoint(...)
	swapPoint(P1, P2);
	// stampare P1 e P2 usando printPoint(...) (per osservare risultato);
	cout << "\nswapped P1: ";
	printPoint(P1);
	cout << "\nswapped P2: ";
	printPoint(P2);
	
	return 0;
}
