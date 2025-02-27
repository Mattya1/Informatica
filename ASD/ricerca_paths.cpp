#include<iostream>
using namespace std;


//calcola il numero di percorsi unici possibili in una griglia n x m
// https://www.youtube.com/watch?v=ngCos392W4w
int numPaths (int n, int m)
{
    if (n == 1 || m == 1)
    {
        return 1;
    
    } else {
        return numPaths (n-1, m) + numPaths (n, m-1);
    }
}


int main (void)
{
    int n, m;
    cin >> n >> m;
    int res = numPaths (n, m);
    cout << "\nRisultato: " << res;
}