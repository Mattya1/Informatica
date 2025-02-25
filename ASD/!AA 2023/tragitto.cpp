#include "tragitto.h"

// verifica se un Tragitto e vuoto
bool tragitto::isEmpty(Tragitto tr) {
  cout << "isempty tragitto";
  return (tr == tragittoVuoto);
}

// inserisce una Tappa in un Tragitto
void tragitto::insert(Tragitto &tr, Tappa t) {
  //penso funzioni come un grafo
  cout<<"insert";

  if (isEmpty(tr)){
    tr->tappa = t;
    tr->next = nullptr;
    return;
  }

  //else inserisco in testa
  Tragitto aux = tr;
  tr->tappa = t;
  tr->next = aux;

  return; 

}
  // TO DO

// ritorna FALSE se il Tragitto e vuoto
// altrimenti rimuove la prima Tappa del Tragitto 
//    e la assegna al secondo parametro e ritorna TRUE
bool tragitto::extract(Tragitto &tr, Tappa &t) {
  // TO DO
  return true;
}

// stampa un Tragitto (formato: N volte [distanza citta'])
void printTragitto(tragitto::Tragitto tr) {
  // TO DO
}
