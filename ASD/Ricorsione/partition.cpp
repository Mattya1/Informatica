#include <iostream>

using namespace std;
// write a function that counts the number of ways 
//you can partition n objects using parts up to m (assuming m>=0)

// ITA in quanti modi puoi splittare n oggetti in parti grandi fino a m?


int partition (int n, int m)
{
    cout << "Partition di " << n << " " << m << endl;
    if (n == 0)
    {
        return 1;

    } else if ( m == 0 || n < 0) {
        return 0;
    
    } else {

        return partition (n-m, m) + partition(n, m-1);
    }


}


int main (void)
{
    int n, m;
    cin >> n >> m;
    int res = partition (n, m);
    cout << "\nRisultato: " << res;
}

