#include "list.h"
#include <iostream>

std::string lessFrequentFind(List list)
{

  if (list == nullptr){return "";}
  string word= list->elem, word2; 
  int count=0, count2=0;

  List cur = list;
  while (cur != nullptr){
    if (cur->elem == word){
      count++;
    }
    
    cur = cur->next; 
  }

  return word;
}


