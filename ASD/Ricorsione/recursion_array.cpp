#include <iostream>

using namespace std;

// versione 2
int sum_arr_aux2(int* tab, unsigned int beg, unsigned int end)
{
    cout << "Sum array aux 2: " << beg << " " << end <<endl;
    if (beg > end){
        return 0;

    } else if (beg == end){

        return tab[beg];
    
    } else {

        unsigned int mid = beg+(mid+beg)/2;
        
        return sum_arr_aux2(tab, beg, mid) + sum_arr_aux2(tab, mid+1, end);
    }

}

// versione 1
int sum_arr_aux(int* tab, unsigned int beg, unsigned int end)
{
    cout << "SUm array aux: " << beg << " " << end << endl;
    if(beg>end){
        return 0;
    } else {
        return tab[beg] + sum_arr_aux(tab, beg+1, end);
    }
}

int sum_array(int* tab, unsigned int size)
{
    return sum_arr_aux2(tab, 0, size-1);
}


int main (void)
{
    int tab[5]={2,3,6,7,9};
    int sum = sum_array(tab, 5);
    cout << "Risultato: " << sum << endl;

    return 0;
}