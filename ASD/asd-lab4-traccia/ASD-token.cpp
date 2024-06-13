//FILE DA MODIFICARE
#include <iostream>
#include "ASD-token.h"

using namespace std;

/**************************************************/
/*      funzioni da implementare                  */
/**************************************************/

//funzione che estrae il prossimo token della string st
//lo mette in tok e modifica st,
//ritorna true se c'era un token da estrarre,
//ritorna false se non c'era niente da estrarre e si e arrivato alla fine di st,
//solleva una eccezione di tipo string se legge un token di tipo sconosciuto
bool nextToken(string &st, token &tok) {
  
  //controllo che non sia vuota
  if (st.empty()){
    return false;
  }

  for (int i =0; i <= st.length(); ++i){ //itero nella stringa da 0 a max, cercando token
    
    //guardo cosa sono e faccio i token
   switch (st[i]) {
    case '(':
      tok.k = PARENTESI_APERTA;
    case ')':
      tok.k = PARENTESI_CHIUSA;
    case '+':
      tok.k = OP_SOMMA;
    case '-':
      tok.k = OP_SOTTRAZIONE;
    case '*':
      tok.k = OP_MOLTIPLICAZIONE;
    }
  }


  return true;
}

