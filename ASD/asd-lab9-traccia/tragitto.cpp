#include "tragitto.h"

// verifica se un Tragitto e vuoto
bool tragitto::isEmpty(Tragitto tr) {
  return (tr == tragittoVuoto);
}
//OK

// inserisce una Tappa in un Tragitto
void tragitto::insert(Tragitto &tr, Tappa t) {

  if (isEmpty(tr)){
    tr = new TragittoElem;
    tr->tappa = t;
    tr->next = tragittoVuoto;
    return;
  }

  Tragitto aux = new TragittoElem;
  aux->tappa = t;
  aux->next = tragittoVuoto;
  
  //devo inserire in coda
  Tragitto scorri = tr;
  while (scorri->next!= tragittoVuoto){
    scorri = scorri->next;
  }
  scorri->next= aux;
}
//OK

// ritorna FALSE se il Tragitto e vuoto
// altrimenti rimuove la prima Tappa del Tragitto 
//    e la assegna al secondo parametro e ritorna TRUE
bool tragitto::extract(Tragitto &tr, Tappa &t) {
  if (isEmpty(tr)){
    return false;
  }
  
  //leggi BENE la consegna
  Tragitto aux = tr;
  t = tr->tappa;
  tr = tr->next;

  delete aux;

  return true;
}

// stampa un Tragitto (formato: N volte [distanza citta'])
void printTragitto(tragitto::Tragitto tr) {
  tragitto::Tragitto aux = tr;

  while (aux != tragitto::tragittoVuoto){

    cout << aux->tappa.distanza << " " <<aux->tappa.citta << " ";
    aux = aux->next;
  }
}
//OK
