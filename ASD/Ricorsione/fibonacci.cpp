#include <iostream>

using namespace std;

unsigned int fibonacci (unsigned int n)
{
    // cout << "fibo: " << n << endl;

    if (n == 0 || n == 1)
        return 1;
    else 
        return fibonacci (n-1) + fibonacci (n-2);
}

int main (void)
{
    unsigned int res;
    int num;
    cout << "Inserisci un numero: ";
    cin >> num;
    res = fibonacci(num);
    cout << "Risultato di fibonacci: " << res<<endl;

}