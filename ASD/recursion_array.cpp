#include <iostream>

using namespace std;

int sum_arr_rec(int* tab, unsigned int size)
{
    cout << "sum_array_rec " << size <<endl;
    if (size == 0)
        return 0;
    else
        return tab[size-1] + sum_arr_rec(tab, size-1);
}

int sum_array(int* tab, unsigned int size)
{
    int count = 0;
    for (unsigned int i = 0; i < size; i++)
    {
        count= count + tab[i];
    }
    return count;
}


int main (void)
{
    int tab[5]={2,3,6,7,9};
    int sum = sum_arr_rec(tab, 5);
    cout << "Risultato: " << sum << endl;

    return 0;
}