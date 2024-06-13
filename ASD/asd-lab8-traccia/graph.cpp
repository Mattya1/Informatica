#include <iostream>

#include "graph.h"
using namespace graph;

struct HalfEdge {   //è la struct degli elementi della lista di adiacenza
  vertexNode *connectedTo = emptyGraph; //vertice che collega
  Weight weight;  //"peso" tra i ptr
  HalfEdge *next = nullptr;  //prossimo elemento
};

struct graph::vertexNode {  //la struct dei vertici
  Label label;
  bool isVisited = false; //flag di controllo
  HalfEdge* edgeList = nullptr; //puntatore alla lista 
  vertexNode *next = emptyGraph; //prossimo elemento

};

/**********************************************************************/
/*               Funzione da implementare                             */
/**********************************************************************/
// Restituisce il grafo vuoto
Graph graph::createEmptyGraph(){
  Graph grafo = emptyGraph;
  return grafo;
}
//OK

Graph getVertex (Label l,const Graph& g){    //graph e vertexnode sono la stessa cosa
   
  if (isEmpty(g)) {return emptyGraph;}
  
  //parto da g e scandisco
  Graph aux = g;

  while (aux!= emptyGraph){
    if (aux->label == l){
      return aux;
    }

    aux = aux->next;
  }

  return emptyGraph; //caso base
}
//OK

//è utile dopo la visit o numEdges, comunque funzioni che ispezionano tutto
void flagRestore (const Graph& g)
{
  Graph aux = g;
  
  while (aux != nullptr){
    aux->isVisited = false;
    aux = aux->next;
  }
  return;

}
//OK

// Aggiunge nuovo vertice con etichetta la stringa.
// Se non è gia presente, ritorna true, altrimenti fallisce e ritorna false 
bool graph::addVertex(Label l, Graph& g){
  Graph aux = getVertex(l, g);
  if (aux != emptyGraph && aux->label == l){
    return false;
  }
  
  Graph newVertex = new vertexNode; //creo e inizializzo il nuovo vertice 
  newVertex->label = l;

  //aggiungo il vertice in testa
  aux = g;
  newVertex->next = aux;
  g = newVertex;
  
  return true; //ce l'ho fatta

}
//OK

// Aggiunge nuovo arco tra i due vertici con etichette le due stringe e peso
// l'intero. Fallisce se non sono presenti tutti e due i nodi o se l'arco
// tra i due e' gia' presente. Se fallisce ritorna false,
// altrimenti ritorna true
bool graph::addEdge(Label from, Label to, Weight w, Graph& g){
  //controlli
  if (isEmpty(g)) {return false;}

  Graph start, dest;
  start = getVertex(from, g);
  if (start == emptyGraph) {return false;} //non c'è
  
  dest = getVertex (to, g);
  if (dest==emptyGraph) {return false;} //non c'è

  //DA FARE ANCORA
  if (areAdjacent (from, to, g)) {return false;} //c'è già un collegamento

  //FINE CONTROLLI, CI SONO ENTRAMBI E NON SONO COLLEGATI
  //start punta a from e dest a to
  
  HalfEdge *firstArch = new HalfEdge;  //lo metto nella lista di start
  firstArch->connectedTo = dest;
  firstArch->next = start->edgeList;
  firstArch->weight = w;

  //INSERISCO IN TESTA
  start->edgeList = firstArch;

  //ora stesso procedimento per il prossimo
  HalfEdge *secondArch = new HalfEdge;
  secondArch->connectedTo = start;
  secondArch->next = dest->edgeList;
  secondArch->weight = w;

  dest->edgeList = secondArch;

  return true;  //ce l'ho fatta
}
//OK

// Restituisce true se il grafo e' vuoto, false altrimenti
bool graph::isEmpty(const Graph& g){
  return (g == emptyGraph);
}
//OK

// Ritorna il numero di vertici del grafo
unsigned int graph::numVertices(const Graph& g){
  unsigned int i =0;

  //se è vuota non ha vertici
  if (isEmpty(g)){return i;}  
  
  Graph aux = g;
  //altrimenti itero semplicemente
  i=1;
  while (aux->next != emptyGraph){
    ++i;
    aux= aux->next;
  }

  return i;
}
//OK

// Ritorna il numero di archi del grafo
unsigned int graph::numEdges(const Graph& g){
  if (isEmpty(g)) {return 0;}

  //metto tutte le flag a false, non si sa mai
  flagRestore (g);

  //uso aux per scorrere i vertici
  Graph aux = g;

  //inizio dal primo vertice
  unsigned int count =0;
  
  while (aux!= nullptr)
  {
    //uso edge per scorrere gli archi
    HalfEdge *edge = aux->edgeList;
    //ogni volta devo marcarli, altrimenti segno i doppi collegamenti
    aux->isVisited = true;
    while (edge != nullptr){
      
      //se non è stato visitato lo conto
      if (edge->connectedTo->isVisited == false){
        count = count+1;}
      
      //vado al prossimo arco
      edge = edge->next;
    }
    //vado al prossimo vertice
    aux = aux->next;
  }
  //IMPORTANTE devo rimettere le flag a false
  flagRestore (g);
  
  return count;
}
//OK

// Calcola e ritorna (nel secondo parametro) il grado del vertice.
// Restituisce un valore falso se il vertice non esiste,
// altrimenti ritorna true
bool graph::nodeDegree(Label l, unsigned int& degree, const Graph& g) {
  
  //caso vuoto
  if (isEmpty(g)){  
    degree =0;
    return false;
  }

  //caso in cui non c'è quel vertice
  Graph aux = getVertex(l, g);
  if (aux==emptyGraph){
    degree = 0;
    return false;
  }
  
  //caso in cui ci sia ma non ha edges
  if (aux->edgeList==nullptr){
    degree =0;
    return true;
  }

  //se invece le ha
  degree=0;

  //molto semplice
  HalfEdge *conta = aux->edgeList;
  while (conta != nullptr){
    degree++;
    conta = conta->next;
  }

  return true;
}
//OK

// Verifica se due vertici sono adiacenti (ovvero se esiste un arco)
bool graph::areAdjacent(Label v1, Label v2, const Graph& g) {
  //scorro prima una lista e poi l'altra
  //scorrerle contemporanteamente sarebbe inutilmente complesso (complessità peggiore O(n), con n lunghezza lista)
  
  if (isEmpty(g)){return false;}

  //controllo che ci sia il primo elemento
  Graph firstVertex;
  firstVertex = getVertex (v1, g);
  if (firstVertex == emptyGraph){
    return false;
  }

  //controllo che ci sia il secondo elemento
  Graph secondVertex = getVertex (v2, g);
  if (secondVertex == emptyGraph){
    return false;
  }

  //ora so che ci sono entrambi
  HalfEdge* check = nullptr;
  //inizio a scorrere la lista del primo
  if (firstVertex->edgeList != nullptr){
    check = firstVertex->edgeList;
  }

  while (check != nullptr){
    if (check->connectedTo == secondVertex){
      return true; //C'è un collegamento tra i due vertici
    }
    //altrimenti vado avanti
    check = check->next;
  }

  return false;
}
//OK

// Ritorna la lista di adiacenza di un vertice
// corrispondente alla lista dei label dei vertici adiacenti
list::List graph::adjacentList(Label v1, const Graph& g) {

  //creo nuova lista
  list::List l = list::createEmpty();

  if (isEmpty(g)) {return l;}
  
  //itero sulla lista di adiacenza del vertice
  //e ogni volta salvo le label nella lista
  Graph aux = getVertex(v1, g);
  if (aux == emptyGraph && aux->edgeList == nullptr ){
    return l;
  }

  HalfEdge *edge = aux->edgeList;

  while (edge!=nullptr)
  {
    //ogni vertice che incontro viene aggiunto alla lista
    list::addFront(edge->connectedTo->label, l);
    edge = edge->next;
  }

  return l;

}
//OK

/******************************************************/
//uso una funzione ausiliaria per non sprecare tempo a fare sempre i controlli
bool pathAux (Graph& start, Label v2, list::List& path, Weight& weight){
  //questo è un algoritmo DFS (va in profondità)

  //se è la destinazione che cerco ritorno true
  if (start->label == v2){
    return true;
  }

  //se è flaggata a false (sicuramente lo è, altrimenti non ci sarei entrato (vedi secondo if))
  //la flaggo a true
  if (start->isVisited == false){
    start->isVisited = true;
  }

  //inizio a scandire la lista di adiacenza di start
  HalfEdge *scan = start->edgeList;

  while (scan != nullptr)
  {
    //se non sono mai stato nell'elemento collegato,
    if (scan->connectedTo->isVisited == false){
      
      //allora richiamo la funzione, e se returna true (ho trovato la label di destinazione)
      if (pathAux(scan->connectedTo, v2, path, weight))  {
        
        //aggiungo la label del vertice che ho appena visitato alla lista della path
        list::addFront(scan->connectedTo->label, path);
        weight = weight + scan->weight; //aggiorno il peso (i km)
        return true;
      }
    }
    //altrimenti continuo la scansione
    scan = scan->next; 
  } 
  //caso base
  return false;
}
//OK


// Calcola, se esiste, un cammino tra due vertici
// Il primo argomento è il vertice di partenza
// Il secondo argomento è il vertice di arrivo
// Il terzo argomento conterrà la lista delle etichette degli
// vertici visitati sul cammino (senza il vertice di partenza, ne il vertice
// di arrivo)
// Si assume che il chiamante fornisca inizialmente una lista vuota.
// Il quarto argomento è il peso del cammino
// La funziona ritorna false, se il vertice di partenza è uguale al vertice
// di arrivo, o se non c'e un cammino tra i due vertici, altrimenti
// ritorna true
bool graph::findPath(Label v1, Label v2, list::List& path, Weight& weight, const Graph& g) {

  //se il graph è vuoto false
  if (isEmpty(g)) {return false;}

  //flaggo tutto a false
  flagRestore(g);
  //metto a 0 il peso, essendo che mi viene passata per riferimento
  //il peso si sommerebbe al risultato della chiamata precedente
  weight =0;

  //se voglio andare da Genova a Genova posso, e il peso è 0
  if (v1 == v2){
    weight = 0;
    return true;
  }

  //controllo che entrambi i vertici esistano
  Graph start = getVertex (v1, g);
  if (start == emptyGraph){
    return false;  
  }

  Graph destination = getVertex (v2, g);
  if (destination == emptyGraph){
    return false;
  }

  //autoesplicativa
  return pathAux(start, v2, path, weight);

}
//OK

// Svuota un grafo
void graph::clear(graph::Graph& g){

  Graph aux = g;
  HalfEdge* edge = aux->edgeList;
  HalfEdge* cur = edge;

  while (edge!= nullptr){
    cur = edge;
    delete cur;

    edge = edge->next;

  }
}
//TODO
//non posso provarla, non va il main di test manuali

// Stampa il grafo
// Per ogni vertice stampa su una riga l'etichetta del vertice seguito di ':'
// poi le etichette dei vertici adiacenti con fra parentesi il peso associato,
// separate da virgole
void graph::printGraph(const graph::Graph& g) {
  
  if (isEmpty(g)){return;}
  
  Graph ver = g;

  while (ver != nullptr)
  {
    cout << "\n" << ver->label <<": ";

    HalfEdge* edge = ver->edgeList;
    while (edge != nullptr)
    {
      cout << edge->connectedTo->label;
      if (edge->next == nullptr){
        cout << ".";
      }else {
        cout << ",";
      }

      edge = edge->next;
    }
    
    ver = ver->next;

  }
  cout << endl;
}
//OK
