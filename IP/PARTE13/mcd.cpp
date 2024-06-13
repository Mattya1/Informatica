#include <iostream>

//calcolo dell'MCD con Euclide
unsigned MCD (unsigned m, unsigned n)
{
    if (m < 0 || n<0){return -1;}

    if (m == n) {return m;
    
    } else if ( m > n) {
        return MCD (m-n, n);
    
    } else if ( m < n ) {
        return MCD (m, n-m);
    }

}

int main ()
{
    unsigned num1, num2;
    std::cout <<"Inserisci due numeri: ";
    std::cin >> num1 >> num2;

    std::cout << "\nL'MCD e': " << MCD(num1, num2)<<std::endl;
    
}