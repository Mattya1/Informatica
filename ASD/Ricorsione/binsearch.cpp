#include <iostream>

using namespace std;

// bin search
bool bin_search (int val, int *tab, int init, unsigned end)
{
    cout << "Ricerca tra " << init << " e " << end << endl;

    if (init >= end){ 
        return (init == val);
    } 
    
    int mid = (end+init)/2;

    // se il valore in mezzo è quello che cerco ok, altrimenti vedo dove cercare
    if (tab[mid] == val){
        return true;

    } else if (val < tab[mid]){
        return bin_search (val, tab, init, mid-1);

    } else {
        return bin_search (val, tab, mid+1, end);
    }

    return false;
}

int main (void)
{
    int tab[10]={1,5,7,8,9,15,17,20,22, 33};
    bool res = bin_search(20, tab, 0, 9);

    cout << "Trovato? " << boolalpha << res << endl;
}

