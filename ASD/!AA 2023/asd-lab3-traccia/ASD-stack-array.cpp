// FILE DA MODIFICARE
#include <iostream>
#include <fstream>
#include <string>

#include "ASD-stack-array.h"

using namespace stack;
using namespace std;

/**************************************************/
/*      funzioni da implementare                  */
/**************************************************/
/* restituisce lo stack vuoto */
Stack stack::createEmpty(){
	Stack sret;

   sret.data = new Elem [BLOCKDIM]; //alloco mem per il dato
   sret.size = 0;
   sret.maxsize = BLOCKDIM;

	return sret;
}

/* restituisce true se lo stack e' vuoto */
bool stack::isEmpty(const Stack& st){
	
   return (st.size==0);
}

/* aggiunge elem in cima (operazione safe, si può sempre fare) */
void stack::push(const Elem el, Stack& st){
   if (st.size == st.maxsize){
      st.data[st.size] = el;  //il dato in posizione size (ultima)

      st.maxsize++;  //aggiorno nuova maxsize
      st.data= new Elem [BLOCKDIM];
      st.size++;  //aggiorno nuova size
   
   } else {
      st.data[st.size] = el;
      st.size++;
   }
}

/* toglie dallo stack l'ultimo elemento e lo restituisce */
/* se lo stack è vuoto solleva una eccezione di tipo string */
Elem stack::pop(Stack& st){
   // to do
   if (st.size == 0){
      throw std::string("Stack empty");
   }

   //mi basta diminuire la size, perchè quando farò una push ciò che è scritto in data verrà sovrascritto   
	Elem ret = st.data[st.size-1];
   st.size--; 
	return ret;
}	

/* restituisce l'ultimo elemento dello stack senza toglierlo.*/
/* Se lo stack è vuoto solleva una eccezione di tipo string*/
Elem stack::top(Stack& st){
   if (st.size == 0){
      throw std::string ("Stack empty");
   }

	Elem ret = st.data[st.size-1];
	return ret;
}


/**************************************************/
/*      funzioni implementate                    */
/**************************************************/

/* riempie lo stack da file */
Stack stack::readFromFile(std::string name_file){
   ifstream infile;
   string read_data;
   infile.open(name_file);
   Stack sret=createEmpty();
   while (getline (infile,read_data)){
      if(read_data.length()>0){
         push(stoi(read_data),sret);
      } 
   }
   return sret;
}

/* legge il contenuto di uno stack da standard input */
Stack stack::readFromStdin(){
   cout << "Inserire una sequenza di numeri separati da spazi seguiti da END per terminare\n";
   Stack sret=createEmpty();
   string read_data;
   cin>>read_data;
   while(read_data!="END"){
      push(stoi(read_data),sret);
      cin>>read_data;
   }
   return sret;
}

/* stampa lo stack*/
void stack::print(const Stack& st){
   cout<<tostring(st)<<endl;
}

/* produce una stringa contenente lo stack*/
std::string stack::tostring(const Stack& st){
   string out="";
   out+="{";
   unsigned int pos=0;
   while(pos<st.size){
      out+=to_string(st.data[pos]);
      if(pos+1!=st.size){
         out+=",";
      }
      ++pos;
   }
   out+="}";
   return out;
}

