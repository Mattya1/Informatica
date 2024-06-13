#include <iostream>
using namespace std;

unsigned coeffBin (unsigned n, unsigned k)
{
    if (k>n){throw string ("eh no zio pera");}

    if(k==0 || n==k) {return 1;}

    return (coeffBin(n-1, k-1) + coeffBin (n-1, k)) ;

}

int main ()
{
    unsigned n, k;
    cout << "Inserisci due numeri: ";
    cin >> n >>k;

    try{
    cout << "\nIl coefficente binario e': "<< coeffBin (n ,k)<<endl;
    }catch (string){
        cout << "k>n";
    } 
    return 0;
}