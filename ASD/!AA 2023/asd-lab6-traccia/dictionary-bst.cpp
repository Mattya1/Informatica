#include "dictionary.h"

using namespace dict;

//STRUCT TO BE COMPLETED
// *** NON AGGIUNGETE IL PUNTATORE AL PADRE ALLA STRUCT!!!! *** 
struct dict::bstNode {
  
  Elem label;
  bstNode* left = nullptr;
  bstNode* right = nullptr;

};

//Funzione da implementare
bool dict::isEmpty(const Dictionary& d){
  return (d == emptyDictionary);
}
   
//Funzione da implementare
Dictionary dict::createEmptyDict(){

  Dictionary newNode = emptyDictionary;

  return newNode;
}

//Funzione da implementare
Error dict::insertElem(const Key k, const Value v, Dictionary& d){
  
  // if (search(k, d) == emptyValue){
    if (d == emptyDictionary){
      d = new bstNode; //inizializzo
      d->label.key = k;
      d->label.value = v;
      d->left = nullptr;
      d->right = nullptr;
      return OK;
    } else if(k < d->label.key){
      return insertElem (k, v, d->left);
    } else {
      return insertElem (k, v, d->right);
    }
  // }
  
  return FAIL;

}

//Funzione da implementare
Value dict::search(const Key k, const Dictionary& d){
  if (!isEmpty(d)){
    if (d->label.key == k){
      return (d->label.value);
    } else if ( k < d->label.key) {
      return search(k, d->left);
    } else {
      return search(k, d->right);
    }
  }

  return emptyValue;

};

Dictionary deleteMin (Dictionary& d){

  if (d->left == emptyDictionary){
   Dictionary minval = d;
   d = d->right;
   return minval;
  } else {
    return deleteMin (d->left);
  }
  
};

//Funzione da implementare
Error dict::deleteElem(const Key k, Dictionary& d){
  
  if (isEmpty(d)){ //se è vuoto stop
    return FAIL;
  }
 
  //devo cercare il MINIMO del ramo sinistro
  if ( k < d->label.key) {
    return deleteElem(k, d->left);
   
   //devo cercare il MINIMO del ramo destro
  } else if (k > d->label.key) {
    return deleteElem(k, d->right);

  } else if ((d->left == emptyDictionary) && (d->right == emptyDictionary)) {
  //da qua i casi se d->label.key == k (sono nel posto giusto)
    
    d = emptyDictionary;  //se non ha figli
    return OK;
  } else if ( d->left == emptyDictionary) {
  //se ha solo il  figlio destro
    Dictionary aux = d; 
    d = d->right;
    delete aux;
    return OK;

  } else if ( d->right == emptyDictionary) {
  //se ha solo il  figlio sinistro
    Dictionary aux2 = d;
    d = d->left;
    delete aux2;
    return OK;

  } else {
    //se non mi appogiassi a una var ausiliaria copierei solo l'indirizzo
    //invece io devo copiare i DATI
    Dictionary minimo = deleteMin (d->right);
    d->label = minimo->label;
    delete minimo;
    return OK;

  }


  return FAIL;

}

//Funzione da implementare
void print(const Dictionary& d) {
  
  if (d!= emptyDictionary){
    print (d->left);    //stampo tutto a sinistra
    cout << "      " << d->label.value<<endl;
    print (d->right);   //stampo tutto a destra
  }

}

/****************************************************************/
/*              FUNZIONE IMPLEMENTATE                           */
/****************************************************************/
Dictionary readFromFile(string nome_file){
  ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
  if (!ifs) {cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n"; return emptyDictionary;}  
  return readFromStream(ifs);
}

Dictionary readFromStdin(){
  cout << "\nInserire una sequenza di linee che rispettano la sintassi key: value.<enter>\nDigitare CTRL^ D per terminare l'inserimento\n";
  Dictionary d = readFromStream((std::cin));
  // Questa serve per aggirare un bug di alcune versioni attuali di glibc.
  clearerr(stdin);
  return d;
}

Dictionary readFromStream(istream& str){
  Dictionary d = emptyDictionary; 
  string key, kcopy;
  string value;
  getline (str, key, ':'); 
  getline (str, value); 
  while (!str.eof())  
    {        
      kcopy = key;
      removeBlanksAndLower(kcopy); 
      insertElem(kcopy, value, d);
      getline (str, key, ':'); 
      getline (str, value); 
    }
  str.clear();
  return d;
}
