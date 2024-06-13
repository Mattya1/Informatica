#include "tree-chsib.h"

using namespace tree;

/* Nota: nei commenti usiamo "albero" e "puntatore a un nodo" come sinonimi, scegliendo di volta in volta
la formulazione più adatta a dare la specifica di una funzione. 
Dal punto di vista tecnico, usiamo sempre il tipo Tree sia quando operiamo su un albero, sia quando operiamo, 
a livello concettuale, su un puntatore a un nodo dell'albero. 
Questo approccio e' corretto in quanto un albero (o sottoalbero) è un puntatore a una struct di tipo treeNode:
un albero è identificato univocamente dal puntatore alla sua radice */ 



/*******************************************************************************************************/
// il nodo di un albero è caratterizzato dall'etichetta, il puntatore al primo figlio e il puntatore al prossimo fratello
// NON manteniamo il puntatore al padre, anche se sarebbe comodo per alcune funzioni (ma del tutto inutile per altre)
struct tree::treeNode {
    Label label;    
    treeNode *firstChild;
    treeNode *nextSibling;
};



/*******************************************************************************************************/
// isEmpty restituisce true se l'albero t e' vuoto, false altrimenti
bool tree::isEmpty(const Tree& t)
{ 
   return (t == emptyTree);
}
//OK

/*******************************************************************************************************/
//ausiliaria importante
Tree getNode (const Label l, const Tree& t)
{

   //prima controllo che non sia vuoto e che t sia l'elemento che cerco

   if (isEmpty(t) || l == emptyLabel){
      return emptyTree;
   }

   if (t->label == l){
      return t;
   }

   //cerco prima in profondità con i figli e poi con i fratelli
   Tree child = getNode (l, t->firstChild);
   if (child != emptyTree){
      return child;
   }

   // return getNode (l, t->nextSibling);

   Tree brother = getNode (l, t->nextSibling);
   if (brother != emptyTree){
      return brother;
   }
   
   return emptyTree;
 
}
//OK

/*******************************************************************************************************/
// addElem aggiunge il nodo etichettato con labelOfNodeToAdd come
// figlio del nodo etichettato con labelOfNodeInTree.
// Caso particolare: aggiunta della radice, che si ottiene
// con labelOfNodeInTree uguale a emptyLabel (= nessun padre), e ha successo
// solo se l'albero e' vuoto (in caso contrario restituisce FAIL 
// e non aggiunge nulla).
// Restituisce FAIL se non esiste un nodo nell'albero etichettato 
// con labelOfNodeInTree oppure se nell'albero esiste gia' un nodo 
// etichettato con labelOfNodeToAdd; aggiunge e restituisce OK altrimenti
Error tree::addElem(const Label labelOfNodeInTree, const Label labelOfNodeToAdd, Tree& t)
{

   if (labelOfNodeInTree == emptyLabel) { //se voglio aggiungere alla radice

      if (isEmpty(t)){  // e se è vuota
         t = new treeNode;
         t->label = labelOfNodeToAdd;
         t->firstChild = emptyTree;
         t->nextSibling = emptyTree;

         return OK;
      }
      
      return FAIL;
   }

   //se non c'è il 
   if (!member (labelOfNodeInTree, t)) {return FAIL;}

   //ovvero se ciò che voglio aggiungere è già presente 
   if (member(labelOfNodeToAdd, t)) {return FAIL;}

   treeNode* nodeFather = getNode (labelOfNodeInTree, t);   //nodeFather punta a quello che mi restituisce la get

   //creo il nuovo nodo e lo inizializzo
   Tree newchild = new treeNode;
   newchild->label = labelOfNodeToAdd;
   newchild->firstChild = emptyTree;
   newchild->nextSibling = emptyTree;
      
   if (nodeFather->firstChild == emptyTree){ //se non ha figli
   
      nodeFather->firstChild = newchild; //lo metto direttamente come figlio

   } else {
      // HEADINSERT VA FATTA DOPO IL PRIMO FIGLIO
      treeNode* aux = nodeFather->firstChild->nextSibling;
      nodeFather->firstChild->nextSibling = newchild;
      newchild->nextSibling = aux;

      // // lastInsert
      // Tree lastOne = nodeFather->firstChild;
      // while (lastOne->nextSibling != emptyTree) {
      //   lastOne = lastOne->nextSibling;
      // }

      // // Inseriamo il nuovo fratello dopo l'ultimo
      // lastOne->nextSibling = newchild;

   }
   
   return OK;
}     
//OK(?)

/*******************************************************************************************************/
// deleteElem (versione iterativa) rimuove dall'albero il nodo etichettato con la Label l
// e collega al padre di tale nodo tutti i suoi figli
// Restituisce FAIL se si tenta di cancellare la radice e questa ha 
// dei figli (non si saprebbe a che padre attaccarli) oppure se non esiste 
// un nodo nell'albero etichettato con la Label; cancella e restituisce OK altrimenti
Error tree::deleteElemI(const Label l, Tree& t)
{
   if (isEmpty(t) || l == emptyLabel) {return FAIL;}

   if (!member(l, t)) {return FAIL;}

   Label fatherLabel = father (l, t);   //prendo l'etichetta del padre

   treeNode* elemToDelete = getNode (l, t);     //prendo puntatore all'elemento da eliminare

   treeNode* padre = getNode (fatherLabel, t);

   if (padre->firstChild == elemToDelete){   //se è il primo figlio
      padre->firstChild = elemToDelete->nextSibling;
      delete elemToDelete;
      return OK;
   }

   treeNode* aux = padre->firstChild; //punto al prinmo figlio

   //scorro fino a che non trovo quello da eliminare
   while (aux->nextSibling != elemToDelete){
      aux = aux->nextSibling;
   }

   aux->nextSibling = elemToDelete->nextSibling; //collego l'elemento precedente a quello successivo
   
   delete elemToDelete;

   return OK;     
}
//TODO


/*******************************************************************************************************/
// deleteElem (versione ricorsiva): stesso comportamento della versione iterativa, ma implementata ricorsivamente
// (può anche non essere ricorsiva la deleteElemR, ma deve fare uso di funzioni ausiliarie ricorsive)
Error tree::deleteElemR(const Label l, Tree& t)
{
     return FAIL;    
}
//TODO


/*******************************************************************************************************/
// father restituisce l'etichetta del padre del nodo con etichetta l se il nodo esiste nell'albero 
// (o sottoalbero) t e se il padre esiste. 
// Restituisce la costante emptyLabel altrimenti
Label tree::father(const Label l, const Tree& t)
{
//struttura molto simile alla getNode
   if (isEmpty(t) || l == emptyLabel) {
        return emptyLabel;
   }

   //se ha un figlio E la label del primogenito è quella cercata
   if (!isEmpty(t->firstChild) && t->firstChild->label == l) {
     //returno la label del padre
      return t->label;
   }

   //cerco prima in profondità con i figli
   Label parent = father(l, t->firstChild);
   if (parent != emptyLabel) {
      return parent;
   }

   // cerco poi i fratelli
   return father(l, t->nextSibling);

}
//OK



/*******************************************************************************************************/
// children restituisce una lista di Label, contenente le etichette 
// di tutti i figli nell'albero t del nodo etichettato con l
// La lista può essere implementata usando una qualunque delle strutture dati viste a lezione
// (non un Vector!!!): si riusi una implementazione del TDD list, adattandola 
// a elementi di tipo string (nelle precedenti esercitazioni gli elementi erano int)
list::List tree::children(const Label l, const Tree& t)
{
   list::List lst = list::createEmpty();

   if (isEmpty(t)) {return lst;} //vuota

   treeNode* child = getNode (l, t);
   unsigned int i=0;

   while (child->nextSibling != emptyTree){
      lst.list[i] = child->label;
   }

   child = child->firstChild;

   return lst;
}
//TODO


/*******************************************************************************************************/
// degree restituisce il numero di archi uscenti dal nodo etichettato con l; restituisce -1 se non esiste 
// nessuna etichetta l nell'albero
int tree::degree(const Label l, const Tree& t)      //CONTA IL NUMERO DEI FIGLI
{
   //    //se non ha figli allora 0
   // if (isEmpty(t)){
   //    return 0;
   
   Tree aux = getNode(l, t);//prendo il nodo
   if (isEmpty(aux)){
      return 0;
   } 

   // } 
   //altrimenti punto al primo figlio e conto
   aux = aux->firstChild;
   int count = 1;
   while (aux->nextSibling != emptyTree){
      count++;
      aux = aux->nextSibling;
   }

   return count;
}
//OK


/*******************************************************************************************************/
// ancestors (versione ricorsiva) restituisce una lista di Label, contenente le etichette 
// di tutti gli antenati del nodo l ESCLUSA l'etichetta del nodo stesso
// La lista può essere implementata usando una delle strutture dati viste a lezione
// (non un Vector)
// (può anche non essere ricorsiva la ancestorsR, ma deve fare uso di funzioni ausiliarie ricorsive)
list::List tree::ancestorsR(const Label l, const Tree& t)
{
   list::List lst = list::createEmpty();
   return lst;
}
//TODO


/*******************************************************************************************************/
// ancestors (versione iterativa) restituisce una lista di Label, contenente le etichette 
// di tutti gli antenati del nodo l ESCLUSA l'etichetta del nodo stesso
// La lista può essere implementata usando una delle strutture dati viste a lezione
// (non un Vector)
list::List tree::ancestorsI(const Label l, const Tree& t)
{
   list::List lst = list::createEmpty();
   return lst;
}
//TODO


/*******************************************************************************************************/
// leastCommonAncestor restituisce l'etichetta del minimo antenato comune 
// ai nodi etichettati con label1 e label2
Label tree::leastCommonAncestor(const Label label1, const Label label2, const Tree& t)
{
   return emptyLabel;
}
//TODO


/*******************************************************************************************************/
// member restituisce true se il nodo etichettato con la label l appartiene all'albero t e false altrimenti
bool tree::member(const Label l, const Tree& t)
{ 
   if (isEmpty(t)){     //è vuoto?
      return false;
   }

   if (member (l, t->firstChild)){ //l'ho trovato tra i figli?
      return true;   //bene
   }

   if (member (l, t->nextSibling)){ //l'ho trovato tra i fratello
      return true;   //bene
   }

   return false;  //allora non c'è
}
//TODO


/*******************************************************************************************************/
// numNodes restituisce il numero di nodi nell'albero t mediante una visita ricorsiva in depthfirst
int tree::numNodes(const Tree& t)
{
   if (isEmpty(t)){return 0;} 

   int counter = 1; //conto questo nodo qua

   counter = counter + numNodes(t->firstChild);    //prima vado in profondià con i figli
   counter = counter + numNodes(t->nextSibling);   //poi lateralmente i fratelli

   return counter;
}
//OK


/*******************************************************************************************************/
// createEmptyTree restituisce l'albero vuoto
Tree tree::createEmpty()
{
   Tree newtree = emptyTree;
   return newtree;
}
//OK


/*******************************************************************************************************/
// Mi serve una funzione ausiliaria per stampare come richiesto a lezione
// perchè devo tenere conto del livello a cui sono per modificare l'indentazione
void printAux (int level, const Tree& t)
{
   //se sono a una foglia o è effettivamente vuoto returno
   if (isEmpty(t)) {return;}

   //itero di volta in volta per aggiungere più "--"
   for(int i =0; i < level; ++i){
      cout << "--";
   }

   cout << t->label<< endl;

   //siccome voglio che la stampa sia DFS, 
   //prima stampo i figli
   printAux (level++ , t->firstChild );
   //poi i fratelli
   printAux (level , t->nextSibling );

}
//OK

/*******************************************************************************************************/
// Visualizzazione possibilmente strutturata come visto a lezione
void printTree(const Tree& t) {
   //devo farmi aiutare da un'altra funzione perchè mi serve una var
   //in più per fare un identazione come richiesta nel testo
   printAux (1, t);
}
//OK

/****************************************************************/
// Questa funzione NON richiede di conoscere come e' fatta la struttura dati che implementa l'albero: usa solo addElem e quindi e' ad 
// un alto livello di astrazione
// Vantaggi: codice compatto, leggibile, riutilizzabile per qualunque implementazione del TDD Tree
// Svantaggi: inefficiente: la addElem cerca ogni volta il nodo con etichetta fatherLabel, mentre basterebbe una chiamata sola per 
// trovarlo e poi si potrebbero attaccare tutti i figli a esso, senza ripetere la dispendiosa ricerca nell'albero; per renderla 
// efficiente dovrei pero' accedere direttamente alla struttura dati chiamando qualche funzione ausiliaria che operi 
// sui nodi dell'albero, rinunciando a scrivere codice modulare, chiaro e ad un ragionevole livello di astrazione... 
// Non esiste un'opzione migliore tra le due: se il codice deve essere efficiente, è opportuno scrivere una funzione ad hoc per 
// una determinata implementazione; se il codice deve essere riutilizzabile, bisogna limitarsi a usare le funzioni offerte dall'
// interfaccia del TDD in modo che la funzione continui ad andare bene anche se cambia l'implementazione
Tree readFromStream(istream& str)
{
    Tree t = createEmpty(); 
    string line;
    Label rootLabel, fatherLabel, childLabel;
    getline(str, line);  
    istringstream instream;            // uso una variabile di tipo istringstream per poter scandire i pezzi di ogni riga usando >>
    instream.clear();
    instream.str(line);
    instream >> rootLabel;             // il primo elemento che si incontra nel file e' l'etichetta della radice, per convenzione su come deve essere fatto il file
    addElem(emptyLabel, rootLabel, t); // la si inserisce nell'albero vuoto, indicando che il padre non c'e' (primo argomento emptyLabel)
    getline(str, line);                // poi si iniziano a scansionare le righe seguenti
    instream.clear();
    instream.str(line);
    while (!str.eof())  
        {        
	instream >> fatherLabel; // in ogni riga del file, il primo elemento e' l'etichetta del nodo padre e gli altri sono le etichette dei figli
        removeBlanksAndLower(fatherLabel); // normalizzo l'etichetta del padre
        while (!instream.eof())            // finche' la riga corrente non e' terminata
            { 
            instream >> childLabel;              // leggo la prossima etichetta
            removeBlanksAndLower(childLabel);    // la normalizzo
            addElem(fatherLabel, childLabel, t); // e la attacco al padre
            }
        getline(str, line);  
        instream.clear();
        instream.str(line);
        }
    str.clear();
    return t;
}



/****************************************************************/
Tree readFromFile(string nome_file)
{
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    if (!ifs) {cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n"; return createEmpty();}  
    return readFromStream(ifs);
}

