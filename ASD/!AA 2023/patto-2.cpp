#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
    int a, b, c, d;
    while (true)
    {
        cout<< "\ninserisci a: ";
        cin >> a;
        cout<< "\ninserisci b: ";
        cin >> b;
        cout<< "\ninserisci c: ";
        cin >> c;
        cout<< "\ninserisci d: ";
        cin >> d;

        int hash = ((a+b+c+ (d*d))% 7);

        cout << "il valore della chiave hash e':" << hash;
    }
    return 0;
}