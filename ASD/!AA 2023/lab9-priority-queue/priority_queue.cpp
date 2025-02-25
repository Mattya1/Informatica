/**************************************************************************/
/*          Coda con priorita' implementata come heap binario             */
/**************************************************************************/

#include "priority_queue.h"


// Funzioni ausiliarie che non appartengono al TDD 

// tra i due indici, restituisce quello che corrisponde al timestamp inferiore
int minTimeStamp(priorityQueue::PriorityQueue pq, int index1, int index2)
{
  if (index1 >= pq.size && index2 >= pq.size)
    // entrambi gli indici sono fuori dal limite dello heap
    return -1; 
  if (index1 >= pq.size)
    // il primo e' fuori, restituisco il secondo
    return index2;
  if (index2 >= pq.size)
    // il secondo e' fuori, restituisco il primo
    return index1;
      
  // entrambi sono dentro lo heap, scelgo quello con timestamp inferiore
  if (pq.data[index1].timeStamp < pq.data[index2].timeStamp)
    return index1; 
    else return index2;
}

//FIGLI DI UN NODO:   2*i +1 E 2*i +2
//PADRE DI UN NODO:  [(i-1)/2]

int getIndex (priorityQueue::PriorityQueue& pq, const priorityQueue::Elem &e){

  //devo scorrere la pq e fare i confronti per cercare 'e'
  for (int i =0; i < pq.size; ++i){

    //controllo anche ts, non so se posso avere lo stesso veicolo con ts differenti
    if (pq.data[i].veicolo == e.veicolo){

      //anzi lascio commentato che non si sa mai
      // if (pq.data->timeStamp == e.timeStamp){
        return i;
      // }
    }

  }

  return -1; //caso base, non c'è
}


void  moveDown( priorityQueue::PriorityQueue& pq, priorityQueue::Elem &e) {

  int i = getIndex(pq, e);
  if (i == -1){return;}

  //riscrivo da capo

  while (true)
  {
    //calcolo gli indici dei figli
    int indSx = 2*i + 1; 
    int indDx = 2*i + 2;

    //e del più piccolo
    int minimo = minTimeStamp(pq, indSx, indDx);
    if (minimo == -1){//sono fuori bound
      break;
    }
    //ora so il minimo indice

    priorityQueue::Elem aux = pq.data[i];
    pq.data[i] = pq.data[minimo];
    pq.data[minimo] = aux;

    i=minimo;
  }


  return;
}
//TODO

void moveUp( priorityQueue::PriorityQueue &pq, priorityQueue::Elem &e) {

  // cerco l'indice di e per utilizzarlo e controllare che esista 
  int indElem = getIndex (pq, e);
  if (indElem == -1){
    //e non esiste
    return;
  }
  //OK

  //trovo l'indice del padre di e
  int father = ((indElem-1)/2);
  
  //devo mettere il controllo di non arrovare dopo lo 0
  //essendo l'heap con radice minima, per muoverlo su deve avere ts < del padre
  while (indElem > 0 && e.timeStamp < pq.data[father].timeStamp ){

    //eseguo lo swap  
    priorityQueue::Elem aux = pq.data[father];
    pq.data[father] = e;
    pq.data[indElem] = aux;

    //cambio gli indici di riferimento
    indElem = father;
    father = ((indElem-1)/2);
  }

  //altrimenti / alla fine ritorna

  return;
}
//OK


// Funzioni del TDD PriorityQueue

// crea una PriorityQueue di dimensione dim
priorityQueue::PriorityQueue priorityQueue::createEmptyPQ(int dim) {
  // cout<<"create empty pq"<<endl;
  PriorityQueue pq;
  //creo 'dim' celle di tipo Elem
  pq.data = new Elem [dim];
  pq.maxsize = dim;
  pq.size = 0;

  return pq;
}
//OK

// verifica se una PriorityQueue e' vuota
bool priorityQueue::isEmpty(const PriorityQueue &pq)
{
  return (pq.size == 0);
} 
//OK

// inserisce un Elem in una PriorityQueue (nella posizione corretta) e ritorna TRUE
// nel caso in cui la PriorityQueue sia piena ritorna FALSE
// suggerimento: inserire in fondo e poi chiamare la funzione ausiliaria moveUp(...)
//   per ripristinare proprieta' dell'ordinamento a heap
bool priorityQueue::insert(PriorityQueue &pq, const Elem &elem) {
  //se è piena
  if (pq.size == pq.maxsize){
    return false;
  }

  //la size è sempre uno in più degli indici
  //es size 1 index 0
  pq.data[pq.size] = elem;
  pq.size = pq.size +1;

  moveUp(pq, pq.data[pq.size-1]);

  return true;
}
//TODO

// ritorna FALSE se PriorityQueue e' vuota 
// altrimenti TRUE e l'Elem minimo nella PriorityQueue in res
// (cioe' quello radice in posizione 0)
bool priorityQueue::findMin(const PriorityQueue &pq, Elem &res) {
  if (isEmpty(pq)){return false;}

  res = pq.data[0];
  return true;
}
//OK


// ritorna FALSE se PriorityQueue e' vuota 
// altrimenti TRUE ed elimina l'Elem minimo nella PriorityQueue
// (cioe' quello radice in posizione 0)
// suggerimento: sostituiamo la radice dell'albero con l'ultimo elemento
//   e poi chiamare la funzione ausiliaria moveDown(...)
//   per ripristinare proprieta' dell'ordinamento a heap
bool priorityQueue::deleteMin(PriorityQueue &pq) {  
  if (isEmpty(pq)){return false;}

  pq.data[0] = pq.data[pq.size-1];
  pq.size = pq.size-1;

  moveDown (pq, pq.data[0]);

  return true;
}//TODO
