#include <iostream>

using namespace std;

unsigned int mcd(unsigned int m, unsigned int n)
{
    cout << "MCD " << m << " " << n << endl;

    if (m == n)
        return m;
    else if (m>n)
        return mcd(m-n, n);
    else
        return mcd(m, n-m);

}


unsigned fact(unsigned int n)
{
    if (n==0)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}

unsigned int fibonacci (unsigned int n)
{
    cout << "fibo: " << n << endl;

    if (n == 0)
    {
        return 1;
    } 
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n-2)+fibonacci(n-1);
    }
}

int main (void)
{
    unsigned int res = fact(5);
    cout << "Risultato del fattoriale: " << res<<endl;
    res = fibonacci(5);
    cout << "Risultato di fibonacci: " << res<<endl;
    res = mcd(13, 5);
    cout << "Risultato mcd: " << res<<endl;

}