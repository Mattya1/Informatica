#include <iostream>
#include "network.h"

namespace network{


struct user{
  string name; //nome univoco
  userList *friends; //lista di adiacenza amicizie
  usrGroupList *groups; //lista di adiacenza gruppi
  User next = emptyUser; //prossimo user nel network
};

//è la struct degli archi di utenti delle liste di adiacenza
struct userList{ 
  User userPtr = emptyUser;  //user a cui punto
  userList *nextUser = nullptr; //prossimo utente o amico
};

struct group{
  string creator; //non so ancora come utilizzarlo
  string gname;
  userList* members= nullptr;  //lista dei membri
  Group next=emptyGroup;
};

//struct degli archi di gruppi
struct usrGroupList{
  Group groupPtr = emptyGroup;  //il gruppo a cui punto
  usrGroupList *nextGroup; //il prossimo gruppo a cui partecipo
};

struct st_Network{ 
  User userVertex = emptyUser;  //lista degli utenti con relative info
  Group groupVertex = emptyGroup; //lista dei gruppi con relative info
}; 


/***********************************************************/
//implementazione delle funzioni

//con questa implementazione NON uso emptyNetwork
Network createEmptyNetwork()
{
  Network net = new st_Network;
  return net;
}
//OK

bool isEmpty(const Network& net)
{
  //controllo solo se non ha utenti perchè se non ha utenti non ha neanche gruppi
  //se così non fosse ci sarebbero problemi
  return net->userVertex == emptyUser;
}
//OK

//restituisce puntatore a un membro, se non lo trova, emptyuser
User getMember (string usr_Log, const Network &net){

  if (isEmpty(net)){return emptyUser;}

  //scorro la lista degli utenti
  User aux = net->userVertex;
  while (aux!= nullptr){
    if (aux->name == usr_Log){
      return aux;
    }
    aux = aux->next;  
  }
  return emptyUser;
}
//OK

//inserimento di un membro in lista
//se c'è già restituisce false
bool addMember(string usr_Log, Network &net)
{
  if(!isEmpty(net)){
    
    if (getMember(usr_Log, net)!=emptyUser){
      return false;} //esiste già
  }

  //inizializzo e aggiungo in testa
  User newUser = new user;

  newUser->name=usr_Log;
  newUser->next= net->userVertex;
  net->userVertex = newUser;
  return true;
}
//OK

//aggiungo un user nella lista amicizie dell'altro (inserimento in testa)
bool becomeFriends(string usr_Log1, string usr_Log2, Network &net)
{
  //verifico che entrambi i nomi esistano
  User usr1 = getMember(usr_Log1, net);
  User usr2 = getMember(usr_Log2, net);

  if (usr1 == emptyUser ||  usr2 == emptyUser){
    return false;}
  //else

  //se sono già amici return true
  if (areFriends(usr_Log1, usr_Log2, net)){
    return true;
  }

  //metto il secondo user nella lista del primo
  userList* user2 = new userList;
  user2->nextUser = usr1->friends;
  user2->userPtr = usr2;
  usr1->friends = user2;
  
  //metto il primo user nella lista del secondo
  userList* user1 = new userList;
  user1->nextUser = usr2->friends;
  user1->userPtr= usr1;
  usr2->friends= user1;
  
  return true;
}
//OK

//prende un puntatore ad uno dei due usr, scorre la lista delle amicizie e se trova
//il nome del secondo usr return true
//ps NON serve scorrere anche l'altra lista perchè non è orientato
bool areFriends(string usr_Log1, string usr_Log2, const Network &net)
{
  User usr = getMember(usr_Log1, net);
  if (usr == emptyUser){return false;}
  userList* aux = usr->friends;

  while (aux != nullptr){
    if (aux->userPtr->name == usr_Log2){
      return true;
    }
    aux = aux->nextUser;
  }

  return false;
}
//OK

//restituisce puntatore a un gruppo
//se non lo trova return emptygroup
Group getGroup (string g_Name, const Network &net)
{
  if (isEmpty(net)){return emptyGroup;}
  Group aux = net->groupVertex;
  while (aux!=emptyGroup){
    if (aux->gname == g_Name){
      return aux;
    }
    aux = aux->next;
  }

  return emptyGroup;
}
//OK

//lo usr del creatore del gruppo viene salvato in una stringa
bool createGroup(string creator, string g_Name, Network &net)
{
  if (getGroup(g_Name, net) != emptyGroup) {
    return false;
  }

  User usr = getMember(creator, net);
  if (usr == emptyUser) {return false;}

  Group newGroup = new group;

  newGroup->gname = g_Name;
  newGroup->creator = creator;
  newGroup->members = nullptr;
  newGroup->next = net->groupVertex;
  net->groupVertex = newGroup;

  joinGroup(creator, g_Name, net);

  return true;
}

//OK

bool joinGroup(string usr_Log, string g_Name, Network &net)
{
  User usr = getMember (usr_Log, net);
  if (usr == emptyUser){
    return false; }//non esiste questo utente
  
  Group grp = getGroup(g_Name, net);
  if (grp == emptyGroup){
    return false;} //il gruppo non esiste

  //else esistono

  //aggiungo il gruppo nella lista dell'utente
  usrGroupList* aux = new usrGroupList;
  aux->groupPtr = grp;
  aux->nextGroup = usr->groups;
  usr->groups = aux;

  //aggiungo l'utente nella lista membri del gruppo
  userList* member = new userList;
  member->nextUser = grp->members;
  member->userPtr = usr;

  grp->members = member;

  return true;
}
//OK

bool deleteMember(string usr_Log, Network &net)
{
  //se un user che viene eliminato aveva creato un gruppo
  //il gruppo viene eliminato

  User usr = getMember (usr_Log, net);
  if (usr == emptyUser){return false;}
  
  //lo levo dai gruppi
  //itero sulla lista dei SUOI gruppi e chiamo la leave
  usrGroupList* cur = usr->groups;
  usrGroupList* temp = nullptr;
  //se ne è creatore elimino il gruppo, altrimenti esco e basta
  while (cur != nullptr)
  {

    temp = cur;
    cur = cur->nextGroup;

    if (temp->groupPtr->gname == usr_Log)
    {
      deleteGroup(temp->groupPtr->gname, net);

    } else {  //cioè se non è il creatore
      leaveGroup (usr_Log, temp->groupPtr->gname, net);
    }

  }
  //fino a qui tutto ok
  usr = nullptr;
  //rimuovo l'utente dalla lista vertici degli utenti
  User aux = net->userVertex;
  User prev = emptyUser;

  while (aux != emptyUser){
    if (aux->name == usr_Log){

      if (prev == emptyUser){
        net->userVertex = aux->next;

      } else {
        prev->next =aux->next;
      }

      delete aux;
      return true;
    } 
    
    prev = aux;
    aux = aux->next;
  }
  return false;
}
//OK

bool deleteGroup(string g_Name, Network &net)
{
  Group grp = getGroup(g_Name, net);
  if (grp == emptyGroup){ return false;}

  //elimino gli archi che vanno dai membri al gruppo
  userList* members = grp->members;

  while (members!= nullptr){
    userList* temp = members;
    members = members->nextUser;
    leaveGroup(temp->userPtr->name, g_Name, net);
  }

  //elimino il gruppo dalla lista della rete
  Group searchGrp = net->groupVertex;
  Group prev = emptyGroup;
  while (searchGrp != emptyGroup){

    if (searchGrp->gname == g_Name){
      if(prev == emptyGroup){
        net->groupVertex = searchGrp->next;
      
      } else {
        prev->next=searchGrp->next;
      }

      delete searchGrp;
      return true;
    }

    prev = searchGrp;
    searchGrp = searchGrp->next;
  }

  return false;
}
//OK

bool leaveFriendship(string usr_Log1, string usr_Log2, Network &net)
{
  User usr1 = getMember(usr_Log1, net);
  User usr2 = getMember(usr_Log2, net);

  if (usr1 == emptyUser || usr2 == emptyUser){
    return false; }

  //levo usr2 dalla lista di usr1
  userList* aux = usr1->friends;
  userList* cur = nullptr;

  while (aux != nullptr){
    if (aux->userPtr->name == usr_Log2){
      if (cur == nullptr){  //ovvero è alla prima iterazione
        usr1->friends = aux->nextUser;
      
      } else {
        cur->nextUser = aux->nextUser;
      }

      delete aux;
      break;
    }
    cur = aux;
    aux = aux->nextUser;
  }

  //levo usr1 dalla lista di usr2
  aux = usr2->friends;
  cur = nullptr;

  while (aux != nullptr){
   
    if (aux->userPtr->name == usr_Log1){
      if (cur == nullptr){
        usr2->friends = aux->nextUser;

      } else {
        cur->nextUser = aux->nextUser;
      }

      delete aux;
      return true;
    }

    cur = aux;
    aux = cur->nextUser;
  }

  return false;
}
//OK

bool leaveGroup(string usr_Log, string g_Name, Network &net)
{
  User usr = getMember(usr_Log, net);
  if (usr == emptyUser){return false;}
  Group grp = getGroup(g_Name, net);
  if (grp == emptyGroup){return false;}
  //levo il gruppo dalla lista dei gruppi a cui appartiene user
  usrGroupList* cur = usr->groups;
  usrGroupList* aux = nullptr;

  while (cur!= nullptr){
    if (cur->groupPtr->gname == g_Name){
      if (aux == nullptr){
      
        usr->groups = cur->nextGroup;
      
      } else {
        aux->nextGroup = cur->nextGroup;
      }
      
      delete cur;
      break;

    }
    aux = cur;
    cur = cur->nextGroup;
  }

  //levo l'utente dalla memberlist del gruppo
  userList* current = grp->members;
  userList* prev = nullptr;

  while(current != nullptr){
    if (current->userPtr->name == usr_Log){
      if (prev == nullptr){
        grp->members = current->nextUser;
      
      } else {
        prev->nextUser = current->nextUser;
      }

      delete current;
      return true;
    }
    prev = current;
    current = current->nextUser;
  }

  return false;
}
//OK

//mi serve per aggiungere gli elementi di volta in volta ordinatamente
void addInOrder(string str, list::List &ls) 
{
  //se è il più piccolo o unico elem
  if (ls.size == 0 || ls.list[0] >= str) {
    list::addFront(str, ls);
    return;
  }

  //cerco il posto dove metterlo in mezzo
  for (int i = 0; i < ls.size- 1; ++i) {
    if (ls.list[i] < str && ls.list[i + 1] >= str) {

      list::add(i + 1, str, ls);
      return;
    }
  }
  //altrimenti in fondo
  list::addBack(str, ls);
}

//OK

list::List members(const Network &net)
{
  list::List members = list::createEmpty();
  if (isEmpty(net)){return members;}

  //scorro lista degli utenti e li metto in ordine in lista
  User aux = net->userVertex;
  while (aux != emptyUser){
    addInOrder (aux->name, members);
    aux = aux->next;
  }

  return members;
}
//OK

list::List groups(const Network &net)
{
  list::List grps = list::createEmpty();
  if (isEmpty(net)){return grps;}

  Group aux = net->groupVertex;
  while (aux != nullptr){
    addInOrder(aux->gname, grps);
    aux = aux->next;
  }

  return grps;
}
//OK

list::List friends(string usr_Log, const Network &net)
{
  list::List ls = list::createEmpty();

  User usr = getMember(usr_Log, net);
  if (usr == emptyUser){return ls;}

  userList* aux = usr->friends;
  while(aux != nullptr){
    addInOrder(aux->userPtr->name, ls);
    aux = aux->nextUser;
  }

  return ls;
}
//OK

list::List memberOf(string usr_Log, const Network &net)
{
  list::List ls = list::createEmpty();

  User usr = getMember(usr_Log, net);
  if (usr == emptyUser){return ls;}

  usrGroupList* aux = usr->groups;
  while (aux != nullptr){
    addInOrder(aux->groupPtr->gname, ls);
    aux = aux->nextGroup;
  }

  return ls;
}
//OK

//posso scorrere la lista dei gruppi e vedere in ognuno di essi chi è il creatore
list::List creatorOf(string usr_Log, const Network &net)
{
  list::List creations = list::createEmpty();
  
  User creator = getMember(usr_Log, net);
  if (creator == emptyUser){return creations;}//la restituisco vuota
 
  usrGroupList *aux = creator->groups;

  while (aux != nullptr){
    if (aux->groupPtr->creator == usr_Log){
      addInOrder(aux->groupPtr->gname, creations);
    }
    aux = aux->nextGroup;
  }

  return creations;
}
//OK

bool makeMoreFriends(string usr_Log, Network &net)
{
  User usr = getMember(usr_Log, net);
  if (usr == emptyUser){return false;}

  usrGroupList* groups = usr->groups;
  //scorro la lista dei gruppi
  while (groups != nullptr)
  {
    userList* members = groups->groupPtr->members;
    //scorro la lista dei membri del gruppo
    while (members != nullptr)
    {
      if (members->userPtr->name != usr_Log){

      //lancio la become friends, se sono già amici non fa nulla
      becomeFriends(usr_Log, members->userPtr->name, net);
      }
      members = members->nextUser;
    }
    groups = groups->nextGroup;
  }

  return true;
}
//OK


}