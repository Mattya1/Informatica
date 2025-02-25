#include "dict-tree.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

//Es 1
//Ritorna il numero di parole nell' albero
unsigned int nbWords(const dictTree& dt){
  if (dt == emptyDictTree)
  {
    return 0;
  }


  int son = nbWords(dt->son);
  int bro = nbWords(dt->brother);
  if (dt->val == '8')
  {
    
    return son + bro+1;
  }

  return son + bro;
  

}

