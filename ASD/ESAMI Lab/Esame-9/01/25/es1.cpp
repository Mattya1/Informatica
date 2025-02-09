#include "set-dll.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

//Es 1
//Ritorna il numero di coppie nell'insieme
unsigned int nbPairs(const set_list& li){
  if (li == nullptr ) return 0;
  
  unsigned int i = 0;
  pair_list cur = li -> pairs ;
  while( cur  != nullptr ){
 	i ++;
 	cur = cur-> next_pair;
  } 
  
  return i + nbPairs( li -> next ); 
  
}


