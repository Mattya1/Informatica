#include <iostream>
using namespace std;
//es su liste semplici, ordinate e senza ripetizioni

struct cell{
    int data;
    cell *next=nullptr;
};

typedef cell* list;

bool recursive_removeElemFromOrderedList(list &l, int x)
{
    if(l == nullptr){return false;}

    if(l->next->data == x){
        cell* aux = l->next;
        l->next = aux->next;
        delete aux;
        return true;
    }
    return recursive_removeElemFromOrderedList(l->next, x);


}

bool recursive_isElementInOrderedList(const list &l, int sear)
{
    if (l == nullptr){return false;}

    if (l->data == sear) {return true;}
    return recursive_isElementInOrderedList (l->next, sear);
}
//OK

bool insertElemInOrderedList (list& l, float s)
{
    if (l == nullptr || s <= l->data){
        list newCell = new cell;
        newCell->data = s;
        newCell->next = l;
        l = newCell;
        
        return true;
    }
        
    return insertElemInOrderedList(l->next, s);

}
//OK

void recursive_printList(list& l)
{
    if (l == nullptr){ return;}
    
    cout << l->data;

    if (l->next != nullptr) {cout << " ";}
        else {cout << ".";}
    
    recursive_printList (l->next);
    
}
//OK

void recursive_deleteAllElementsFromList (list& l)
{
   
    if (l == nullptr){return;}
    cell* next = l->next;
    delete l;
    //elmino pian piano che vado aventi, come un treno
    recursive_deleteAllElementsFromList (next);
    //dopo aver eliminato tutto, devo impostare a null
    l = nullptr;

}
//OK

void recursive_reversePrintList(list& l)
{
    if (l == nullptr) { return; }

    if (l->next != nullptr) {
        recursive_reversePrintList(l->next);
        cout << " ";
    }
    
    cout << l->data;
}
//OK

int main ()
{
    float num;
    list l = nullptr;

    while (true){
        cout << "\nInserisci un numero, o -1 per terminare: ";
        cin >> num;
        
        if (num != -1) {
            insertElemInOrderedList (l, num);
        } else {
            break;
        }
    }

    cout <<"\nSTAMPA ORDINATA\n";
    recursive_printList(l);
    
    cout <<"\n\nSTAMPA REVERSED\n";
    recursive_reversePrintList(l);

    // cout <<"\n\nELIMINO TUTTO";
    // recursive_deleteAllElementsFromList(l);
    // cout << ((l == nullptr) ? "\nLa lista e' vuota" : "\nNon e' vuota") << endl;

    int x;
    cout <<"\nChe elemento cerchi? ";
    cin >> x;
    cout << (recursive_isElementInOrderedList(l, x) ? "\nTrovato" : "\nNon trovato")<<endl;

    cout << "\nChe elemento vuoi rimuovere? ";
    cin >>x;
    cout << (recursive_removeElemFromOrderedList(l, x) ? "\nEliminato" : "\nNon eliminato (non c'è(?))") <<endl;

    recursive_printList(l);


    return 0;
}