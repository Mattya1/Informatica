// SOSTITUIRE CON Nome Cognome Matricola

#include <iostream>

#include "bag.h"

using namespace bag;
using namespace std;


// DEFINIZIONE DELLA STRUTTURA DATI

const Bag emptyTree = nullptr;

struct bag::Node {
    Elem value;
    Node *left;
    Node *right;
};


// crea una nuova bag vuota
Bag bag::createEmpty()
{
    return emptyTree;     //emptyTree == NULL
}

// ci dice se una bag è vuota
bool bag::isEmpty(const Bag b)
{
    return (b == emptyTree);
}

// inserisce un elemento nella bag
void bag::insert(Bag &b, Elem e)
{
    if (isEmpty(b))
    {
        b = new Node;
        b->left = emptyTree;
        b->right = emptyTree;
        b->value = e;     
    
    } else if (e <= b->value){
        insert(b->left, e);
    } else{
        insert(b->right, e);
    }

}

// FUNZIONI DA IMPLEMENTARE

// stampa gli elementi della bag in ordine decrescente, su un'unica linea, separati da spazi
// non è necessario andare a capo a fine linea
void bag::printInReverseOrder(const Bag b)
{
    //in ordine decrescente vuol dire che vado dal quello in basso a dx e salgo

    if (b->right != nullptr){
        printInReverseOrder(b->right);
    }
    cout << b->value << " ";

    if(b->left != nullptr){
        printInReverseOrder (b->left);
    }
}//FUNZIONA!!!

// restituisce vero se l'elemento v esiste in due o più copie
// NOTA: se un nodo padre ha un elemento uguale al suo nel suo sottoalbero, deve essere il suo figlio sinistro
bool bag::isDuplicate(const Bag b, Elem v)
{
    if(isEmpty(b))
    {
        return false;
    }

    if (v > b->value)
    {
        return isDuplicate(b->right, v);

    } else if (v == b->value && b->left != emptyTree){
        if (b->left->value == v){
            return true;
        }
    } else {
        return isDuplicate(b->left, v);
    }

    return false;
}//FUNZIONA!!!

// restituisce la somma di tutti gli elementi che hanno valore maggiore di v
Elem bag::sumLarger(const Bag b, Elem v)
{
    if (isEmpty(b))
    {
        return 0;
    }
    
    // così includo quelli maggiori stretti
    if (b->value <= v){

        return sumLarger(b->right, v);

    }
    
    int destra = sumLarger(b->right, v);
    int sinistra = sumLarger (b->left, v);
    return sinistra + destra + b->value;


}
