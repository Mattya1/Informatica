#include <iostream>
#include "selectVar_funct.h"

using namespace std;

char* selectVar(char& a, char& b, char& c){
    char* p = nullptr;
    char ans;

    cout << "Scegli fra queste variabili "
         << " Potrai cambiare idea in seguito e sceglierne una diversa che preferisci" << endl;

    cout << "Vuoi la prima (y/n)? contiene " << a << ": ";
    cin >> ans;

    if (ans == 'y' || ans == 'Y')
        p = &a; // assegno a p l'indirizzo di a
    else {
        cout << "\nPreferisci la seconda (y/n)? contiene " << b << ": ";
        cin >> ans;

        if (ans == 'y' || ans == 'Y')
            p = &b; // assegno a p l'indirizzo di b
        else {
            cout << "\nPreferisci la terza (y/n)? contiene " << c << ": ";
            cin >> ans;

            if (ans == 'y' || ans == 'Y')
                p = &c; // assegno a p l'indirizzo di c
        }
    }
    return p;
}
