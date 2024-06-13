#include "array.h"


bool isEven (int num){
  return (num%2==0);
}



dyn_array indexOfEvenInArray(const int* arr,unsigned int dim){
  dyn_array ret;
  
  int j=0;

  for (unsigned int i = 0; i < dim; i++){
    if (arr[i] %2==0){
      ret.A[j]=i;
      ret.D++;
      j++;
    }
  }

  return ret;
}
