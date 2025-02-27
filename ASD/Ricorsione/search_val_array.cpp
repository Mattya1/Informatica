#include <iostream>

using namespace std;
//AGGIUNGI COUT
int pres_array_aux(int val, int* tab, unsigned int beg, unsigned int end)
{
    if(beg>end){
        return false;
    } else if ( beg == end){
        return (val == tab[beg]);
    }

    if (val == tab[beg]) {
        return true;

    } else if (val > tab[beg]){
        return pres_array_aux(val, tab, beg+1, end);

    } else {
        return pres_array_aux(val, tab, beg+1, end);
    }
    
    
}


int search_array(int val, int *tab, int size)
{
    return pres_array_aux(val, tab, 0, size-1);
}

int main (void)
{
    int tab[5]={2,3,2,7,9};
    bool res = search_array(9, tab, 5);
    cout << "Trovato? "  << boolalpha <<  res <<endl;
}