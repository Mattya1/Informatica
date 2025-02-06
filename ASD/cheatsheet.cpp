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