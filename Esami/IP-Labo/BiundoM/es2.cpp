#include "array.h"
#include <iostream>

int nextEven (const int* arr, int pos, unsigned int dim){

  unsigned int i;
  int cur = arr[pos];

  for (i = pos+1; i<dim; ++i){
    if ( arr[i]%2 ==0){
      return (arr[i]>=cur);
    }

  }
 
 return true;  
}

bool nextOdd (const int* arr, int pos, unsigned int dim){
  
  unsigned int i;
  int cur = arr[pos];

  for ( i = pos+1; i<dim; ++i){
    if ( arr[i]%2 !=0){
      return(arr[i]>=cur);
    }

  }
  return true;
}

bool ascendingSequenceEvenOdd(const int* arr, unsigned int dim){
 
  if (dim==0){return true;}
  
  for (unsigned int i =0; i<dim; ++i){

    if (arr[i]%2 == 0){
      if (nextEven(arr, i, dim)== false){
	return false;
      }

    } else {//fine primo if
      if (nextOdd(arr, i, dim)==false){
	return false;
      }
    }
  }//fine for

  return true;
}
