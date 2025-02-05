#include "set-dll.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

//Es 3
//Cancella dell'insieme la coppia (v1,v2)
//Se la coppia non e' presente non fa nulla
void deletePair(set_list& li,int v1,int v2){
if ( li == nullptr ) return;

if ( li -> sum != v1+ v2)return deletePair(li -> next , v1 ,v2 );

set_list current = li;
pair_list cur = current -> pairs;
bool found = false;
pair_list cur_pair;
while ( cur != nullptr )  { 
	if  (cur -> v1 == v1 && cur -> v2 == v2 ){
		found = true;
		cur_pair = cur;
	}
	cur = cur -> next_pair;
}
	if ( !found )return;

if (  cur_pair -> next_pair == nullptr && cur_pair -> prev_pair == nullptr  ){
	if  ( current -> next  == nullptr && current -> prev == nullptr ) {
		delete current;
		li = nullptr;
		return;
	}
	if ( current -> next  != nullptr && current -> prev == nullptr ){
			li = current  -> next ;
			li -> prev = nullptr;
			delete current;
			return;


	}
	if ( current -> next  == nullptr && current -> prev != nullptr ){
			li = current  -> prev ;
			li -> next = nullptr;
			delete current;
			return;


	}
	else {
		li = current -> next;
		li ->prev= current -> prev;
		delete current ;
		return;


	}
	}

if (  cur_pair -> next_pair != nullptr && cur_pair -> prev_pair == nullptr  ){
	pair_list temp = cur_pair;
	cur_pair = cur_pair	-> next_pair;
	cur_pair -> prev_pair = nullptr;
	current -> pairs  =  cur_pair;
	delete temp ;
	return;

}

if (  cur_pair -> next_pair == nullptr && cur_pair -> prev_pair != nullptr  ){
	pair_list temp = cur_pair;
	cur_pair = cur_pair	-> prev_pair;
	cur_pair -> next_pair = nullptr;
	delete temp ;
	return;
	
}
	pair_list temp = cur_pair;
	cur_pair = cur_pair	-> prev_pair;
	cur_pair -> next_pair = temp-> next_pair;
	cur_pair -> next_pair -> prev_pair = temp -> prev_pair;
	delete temp ;
	return;
}