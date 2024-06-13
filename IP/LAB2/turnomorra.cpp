/* Scrivere un programma che implementa un turno di gioco di forbice-carta-sasso, ovvero che legge in input la mossa dei due
giocatori (ogni mossa è un carattere ’f’, ’c’, ’s’, quindi due caratteri) e restituisce in output chi ha vinto seguendo le regole
del gioco ("Giocatore 1 hai vinto!" oppure "Giocatore 2 hai vinto!"). Il programma deve controllare che i giocatori abbiano
inserito uno dei tre caratteri validi.*/

#include <iostream>
using namespace std;

int main ()
{
    char gioc1, gioc2;

    cout << "mossa giocatore 1: "<< endl;
    cin >> gioc1;

//con il ciclo while controllo l' corretto dei valori
    while (gioc1 != 'f' && gioc1 != 's' && gioc1 != 'c')
    {
        cout << "valore non valido, riprova: ";
        cin >> gioc1;
    }

    cout << "mossa giocatore 2: "<< endl;
    cin >> gioc2;

    while (gioc2 != 'f' && gioc2 != 's' && gioc2 != 'c')
    {
        cout << "valore non valido, riprova: "<<endl;
        cin >> gioc2;
    }    

//controllo prima il caso di parità, e poi confronto gli altri
    if (gioc1 == gioc2){
        cout << "parita'! "<<endl;
    }
    else if (gioc1 == 'f'){
        if(gioc2 == 'c'){
            cout << "Giocatore 1 hai vinto!"<<endl;
        }
        else {
            cout << "Giocatore 2 hai vinto!"<<endl;
        }
    }
    else if (gioc1 == 's'){
        if (gioc2 == 'f'){
            cout << "Giocatore 1 hai vinto!" <<endl;
        }
        else {
            cout << "Giocatore 1 hai vinto!" <<endl;
        }
    }

}