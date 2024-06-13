#include <iostream>
using namespace std;

unsigned fibonacci (unsigned num)
{
    if (num == 0 || num ==1){return 1;}

    return fibonacci(num-1)+fibonacci(num-2);
}

int main ()
{
    unsigned n;
    cout <<"Inserisci un numero: ";
    cin >> n;

    cout << "\nIl risultato e' " << fibonacci(n)<<endl;
    return 0;
}