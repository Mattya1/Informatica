#include "set-dll.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

//Es 2
//Aggiunge una coppia (v1,v2) all'insieme
//Se la coppia e' gia' presente, non fa nulla
void addPair(set_list& li, int v1, int v2) {

  pair_list pair = new pair_node;
  pair ->v1 = v1;
  pair ->v2 =v2;
if (  li == nullptr ){
    set_list lista = new set_node;
    lista ->sum = v1+v2;
    lista -> pairs = pair;
    li = lista;
    return;
}

set_list current = li;
while ( current != nullptr ){
  pair_list cur_pair = current -> pairs;
  if (  current -> sum == v1+v2 ){
    while  ( cur_pair!= nullptr ){
      if ( cur_pair -> v1 == v1 &&  cur_pair -> v2 == v2 )return;
      cur_pair = cur_pair -> next_pair;
    }
    pair_list attuale = current ->pairs;
    attuale -> prev_pair =  pair;
    pair -> next_pair = attuale ;
    current -> pairs = pair;
    return;
  }

current = current -> next;


}
    set_list lista = new set_node;
    lista ->sum = v1+v2;
    lista -> pairs = pair;
    li -> prev = lista;
    lista -> next = li;
    li = lista;
    return;


}
