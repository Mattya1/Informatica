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

int main (void)
{
    int n, m;
    cout << "Inserisci due numeri: ";
    cin >> n >> m;
    unsigned int res = mcd (n, m);

}