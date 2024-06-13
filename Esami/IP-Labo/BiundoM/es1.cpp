#include "funz.h"

unsigned int returnLucasNumberInPos(unsigned int pos){ 
	
  if (pos == 1){
    return 1;
  } else if (pos == 0){
    return 2;
  
  } else {
  
    return (returnLucasNumberInPos(pos-1)+returnLucasNumberInPos(pos-2));
  }
}

