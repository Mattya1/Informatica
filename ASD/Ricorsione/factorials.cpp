#include <iostream>

using namespace std;



unsigned fact(unsigned int n)
{
    if (n==0) {
        return 1;

    } else{
        return n*fact(n-1);
    }
}

int main (void)
{
    int num;
    cout << "Inserisci un numero: ";
    cin >> num;
    unsigned int res = fact(num);
    cout << "Risultato del fattoriale: " << res << endl;
}
