#include "list.h"

void tailInsert(List &list, Elem newElem)
{
  

  List newCell = new Cell;
  newCell->elem = newElem;
  newCell->next = nullptr;

  if (list == nullptr){
    list = newCell;
    return;
  }

  List cur = list;
  while (cur->next != nullptr){
  
    cur = cur->next;  
  }

  cur->next = newCell;


}
