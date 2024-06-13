#include <iostream>
using namespace std;

unsigned fact (unsigned n)
{

    if (n == 0){
        return 1;
    } else {
        return (n * fact( n-1));
    }

};


int main ()
{
    unsigned n;
    cout <<"Inserisci un numero: ";
    cin >> n;

    cout << "\nIl fattoriale e' : " << fact(n)<<endl;

    return 0; 

};