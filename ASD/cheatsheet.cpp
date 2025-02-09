#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
/*
LISTE SEMPLICI
LISTE CON SENTINELLA
LISTE DOPPIAMENTE COLLEGATE (CON SENTINELLA)
*/

/*
ARRAY DINAMICI
VECTOR
*/

/*
QUEUE
STACK
*/

/*
TABELLE DI HASH
BST
BINARY TREES
GRAFI
LISTE DI ADIACENZA
COSE CON PRIORITA'
*/

//LISTE SEMPLICI
struct cell{
    int valore;
    cell* next = nullptr;
};

typedef cell* BasicList;
const BasicList emptyList = nullptr;

void headInsert (BasicList& list, int val)
{
    cell* aux = new cell;
    aux->next = list;
    aux->valore = val;
    list = aux;
}

void tailInsert(BasicList& list, int val)
{
    cell* aux = list;
    cell* NewCell = new cell;
    NewCell->valore = val;
    while( aux->next != nullptr)
    {
        aux = aux->next;
    }
    aux->next = NewCell;
}

//LISTE CIRCOLARI CON SENTINELLA

void createEmpty (BasicList& list)
{
    cell* aux = new cell;
    aux->next = aux;    //punta a sè
    list = aux;
}

void tailInsertCirc (BasicList& list, int val)
{
    cell* aux = new cell;
    aux->valore = val;
    if (list == emptyList)
    {
        aux->next = aux; // è l'unico elemento
    } 
    else 
    {
        //creo un cursore per arrivare alla fine della lisa
        cell* temp = list;
        while (temp->next != list)
        {
            temp = temp->next;
        }
        temp->next = aux;
        aux->next = list;
    }
    list = aux;
}

/*ARRAY DINAMICI: dimensione stabilita in runtime*/
void newArr (void)
{
    int dim;
    int *arr;
    std::cout << "Quanto deve essere lungo?" <<endl;
    cin >> dim;
    arr = new int[dim];
    //manovro l'array con i puntatori
    //ricordare di deallocare la memoria con
    delete[] arr;
}
//meglio i VECTOR   
void newVect(void)
{
    vector<int> vec;
    vec.push_back(11);  // aggiunta in coda
    vec.front();        // restituisce primo elem
    vec.back();         // returna ultimo elem
    vec.pop_back();     // rem last elem
    vec.empty();        // sarebbe isEmpty
    vec.size();         // numero di elementi inseriti
    vec.at(1);          // returna elemento a posizione
    vec.resize(4);      // delete vec e ricopia in nuovo + grande / del eccessp
  //vec.insert(1);      //NON SO PERCHÈ NON VAAAAAA
}

//QUEUE & STACK
void stacks (void) //FIFO First In First Out
{
    stack<int> s;
    s.push(5);      // 5
    s.push(7);      // 5 7
    s.push(6);      // 5 7 6
    s.push(3);      // 5 7 6 3
    s.push(1);      // 5 7 6 3 1
    s.pop();        // 7 6 3 1
    s.top();        // ti fa vedere 7
    s.empty();
    s.size();
}

//CODA UGUALE
void code (void)
{
    queue<int> q;
    //etc
}

//HASH TABLES CON COLLISIONI
//bisogna creare una funzione che distribuisca bene i valori nella tabella
typedef string Key;
typedef string Value;
typedef hCell* Bucket;
typedef Bucket* Dictionary;

struct hCell{
    Value elem;
    hCell* next;
};

//dimensione tabela
const int tableDim;
//funzione TIPO per calcolo indice
int h(Key s){

   //potrei usare la size in qualche modo
   if (s.empty()){
      throw ("Key not valid");
   } 

   unsigned int val = ((s.length()  * int (s.back())) % tableDim);

   return val;
}

void hashTab (void)
{
    Dictionary dic = new Dictionary[tableDim];
    for (int i = 0; i < tableDim; i++)
    {
        dic[i] = nullptr;
    }
}

//per aggiungere elementi
void addElemHash (Dictionary& dic, Key k, Value v)
{
    //provo a cercarlo
    //search(key, k)
    int index = h(k); //calcolo la posizione

    hCell* newCell = new hCell;
    newCell->elem = v;
    newCell->next = dic;
    //prendo e scorro
}

