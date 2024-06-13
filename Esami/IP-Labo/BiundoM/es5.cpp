#include "list.h"

unsigned int elementIstancesCount(List list, Elem toFind)
{
  if (list == nullptr){return 0;}
    
    int count =0;
    List cur = list;
    while (cur != nullptr){
      
      if(cur->elem == toFind){
      	count++;
      }

      cur = cur->next;
    }

    return count;
}
