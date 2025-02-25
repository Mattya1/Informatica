#include "dictionary.h"

#include <math.h> // sqrt()

using namespace dict;

struct dict::cell {
    Elem elem;
    cell* next;
};


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
int h1(Key s) // funzione di hash che considera unicamente il valore ascii del primo carattere della chiave (se esiste) e restituisce il resto della divisione di tale valore per tableDim 
{
   if (s.empty()){
      throw ("Key not valid");
   }
   //int() è una funzione converte un carattere qualsiasi in valore ASCII 
   return ( int(s[0]) % tableDim);
}


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
int h2(Key s) // funzione di hash che somma il codice ascii di ogni carattere nella chiave e restituisce il resto della divisione di tale somma per tableDim 
{
 // implementare la funzione richiesta e modificare il return 
   if (s.empty()){
      throw ("Key not valid");
   }

   unsigned int val =0;
   for (unsigned i =0; i<s.length(); ++i){
      val = val + int(s[i]);
   }

 return (val%tableDim);
}


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
int h3(Key s) // funzione di hash diversa da h1 ed h2, che progettate e implementate voi seguendo qualche criterio che vi sembra ragionevole
{
 // implementare la funzione richiesta e modificare il return 

   //potrei usare la size in qualche modo
   if (s.empty()){
      throw ("Key not valid");
   } 
   
   unsigned int val = ((s.length()  * int (s.back())) % tableDim);

   return val;
}

/****************************************************************/
/*    FUNZIONE DA MODIFICARE PER FARE ESPERIMENTI DIVERSI       */
/****************************************************************/
int h(Key s)
{
   return h1(s); // modificare questa chiamata per sperimentare l'utilizzo delle funzioni di hash h1, h2, h3, definite prima
}


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
Error dict::deleteElem(const Key k, Dictionary &s)
{

   int index = h(k);

   cell* cur = s[index];
   cell* aux = cur;

   while (cur->next != nullptr)
   {
      if (cur->elem.key == k){
         
         //controllo se in testa
         if (aux != nullptr){
            aux->next = cur->next;
         } else {
            
            s[index] = cur ->next;            
         }         
         
         delete cur;

         cout << "\nEliminato"<<endl;

         return OK;
      }

      aux = cur;
      cur = cur->next;
   }
   cout << "\nElemento non presente"<<endl;
   return FAIL;  	
}


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
Value dict::search(const Key k, const Dictionary &s)
{

   int index = (h(k)); //calcolo l'indice di appartenenza
   cell* cur = s[index];   //e ci entro dentro

   while (cur != nullptr){    //è lista semplice, e controllo che QUESTO elem non sia vuoto
      if (cur->elem.key == k ){
         // cout<<"\ntrovato"<<endl;
         return cur->elem.value;
      }
      
      cur = cur->next;
   }
   // cout << "\nNon presente"<<endl;
   return emptyValue;  	
}


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
Error dict::insertElem(const Key k, const Value v,  Dictionary &s)
{
   // cout << "prima";
   if (search (k, s)!= emptyValue){ //emptyvalue è ciò che viene restituito se non viene trovato
      return FAIL;      //quindi se lo cerca ed è già inserito dà fail
   }
   // cout << "dopo";   
   int index = h(k); //calcolo l'indice dell'array

   //ora aggiungo l'elemento
   cell* newCell = new cell;
   newCell->elem.key = k;
   newCell->elem.value = v;
   newCell->next = s[index];
   s[index] = newCell;
   
   return OK;
}


/****************************************************************/
Dictionary dict::createEmptyDict()
{
   Dictionary d = new Dictionary[tableDim];
   for (int i=0; i < tableDim; ++i)
      d[i]=emptyBucket;
   return d;
}


/****************************************************************/
Dictionary readFromFile(string nome_file)
{
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    if (!ifs) {cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n"; return createEmptyDict();}  
    return readFromStream(ifs);
}


/****************************************************************/
Dictionary readFromStdin()
{
    cout << "\nInserire una sequenza di linee che rispettano la sintassi key: value.<enter>\nDigitare CTRL^ D per terminare l'inserimento\n";
    Dictionary d = readFromStream((std::cin));
    // Questa serve per aggirare un bug di alcune versioni attuali di glibc.
    clearerr(stdin);
    return d;
}


/****************************************************************/
Dictionary readFromStream(istream& str)
{
    Dictionary d = createEmptyDict();     
    string key, kcopy;
    string value;
    getline (str, key, ':'); 
    getline (str, value); 
    while (!str.eof())  
        {     
        kcopy = key;
        removeBlanksAndLower(kcopy);   
        insertElem(kcopy, value, d); // FINCHE' NON IMPLEMENTATE LA INSERTELEM, NON PUO' FUNZIONARE CORRETTAMENTE: la insertElem e' la prima funzione che dovete implementare
        getline (str, key, ':'); 
        getline (str, value); 
        }
    str.clear();
    return d;
}


/****************************************************************/
int printBucket(Bucket b) // stampa il contenuto di un bucket e restituisce il numero di elementi contenuti nel bucket stesso
{  
   int counter = 0;
   while(b!=emptyBucket) {
        counter++;
        cout << (b->elem).key << ": " << (b->elem).value << "\n"; 
	b=b->next;
	}
   return counter;	
}


/****************************************************************/
void print(const Dictionary &s)
// stampa il contenuto del dizionario ed anche informazioni su come sono stati organizzati gli elementi
{
int bucketDim[tableDim];
int totalElem = 0;
for (unsigned int i=0; i<tableDim; ++i)
   {
    cout << "\nBucket " << i << "\n\n";
    bucketDim[i] = printBucket(s[i]);
    totalElem += bucketDim[i]; 
   }
float means = totalElem/(float)tableDim;
float standardDevSum = 0;
for (unsigned int i=0; i<tableDim; ++i)
     standardDevSum += (bucketDim[i]-means)*(bucketDim[i]-means);
   
/* Lo scarto tipo, deviazione standard, o scarto quadratico medio e' un indice di dispersione statistico, vale a dire una stima della variabilita' di una popolazione di dati o di una variabile casuale.
Lo scarto tipo e' uno dei modi per esprimere la dispersione dei dati intorno ad un indice di posizione, quale puo' essere, ad esempio, la media aritmetica. */

cout << "\n===STATISTICHE SULL'ORGANIZZAZIONE DEL DIZIONARIO===\n";

for (unsigned int i=0; i<tableDim; ++i)
   cout << "\nBucket " << i << ": " << bucketDim[i] << " elementi";

cout << "\nIl numero totale di elementi memorizzati e' " << totalElem;
cout << "\nIl numero di bucket nel dizionario e' " << tableDim;
if (tableDim != 0) cout << "\nIl numero atteso di elementi per bucket e' " << means << "\nLa deviazione standard e' " << sqrt(standardDevSum/tableDim);
}