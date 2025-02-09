#include <iostream>
#include <string>
#include "network.h"

using namespace network;
using namespace std;

// void print (Network &net);

void printImputLists (list::List &lst)
{
  if (lst.size ==0){
    cout << "\nLista vuota";
    return;
  }

  for (int i =0; i < lst.size; ++i){
    cout << lst.list[i];
    if (i == lst.size-1) {cout<< ".";}
    else {cout << ", ";}
  }
};

void printList (Network &net)
{
  // if (isEmpty(net)){return;}

  list::List testLists = list::createEmpty();
  char scelta;
  string input1, input2;

  cout << "che LISTA vuoi stampare?"<<endl;
  cout << "a. il nome di tutti gli user " << endl;
  cout << "b. il nome di tutti i gruppi" << endl;
  cout << "c. il nome di tutti gli amici di user" << endl;
  cout << "d. il nome di tutti i gruppi di user" << endl;
  cout << "e. il nome di tutti i gruppi creati da user" << endl;
  cin >> scelta;

  if (scelta == 'q') {
      return; // Uscita dal programma
  }

  switch (scelta) {
      case 'a':
          testLists = members(net);
          cout <<"\nGli utenti nel network sono: ";
          printImputLists(testLists);
          break;
      case 'b':
          testLists = groups(net) ;
          cout <<"\nI gruppi presenti nella rete sono: ";
          printImputLists(testLists);
          break;
      case 'c':
          cin >> input1;
          testLists = friends(input1, net);
          cout <<"\nGli amici di " <<input1<<" sono: ";
          printImputLists(testLists);
          break;
      case 'd':
          cin >> input1;
          testLists = memberOf(input1, net) ;
          cout <<"\n" << input1 <<" e' membro di: ";
          printImputLists(testLists);
          break;
      case 'e':
          cin >> input1;
          testLists = creatorOf(input1, net);
          cout << input1<<" ha creato: ";
          printImputLists(testLists);
          break;

      default:
          cout << "Scelta non valida!" << endl;
          break;
  }

  
}


const string menu_list = R"(Network menu:
    a. Create Empty Network
    b. Check if Network is Empty
    c. Add Member
    d. Become Friends
    e. Check if Friends
    f. Leave Friendship
    g. Create Group
    h. Join Group
    i. Leave Group
    j. Delete user
    k. Delete Group
    l. Make More Friends
    m. Print network menu (WIP)
    o. Print List menu
    p. Print this menu
    q. Exit )";

void menu()
{
    string user1, user2, gruppo;
    char choice;

    Network net = createEmptyNetwork();
    cout << menu_list;

    while (true) {
        cout << endl;
        cout<<"\n   Please enter a choice: ";
        cin >> choice;

        switch (choice)
        {
        case 'a':
            net = createEmptyNetwork();
            cout << "Empty network created.\n";
            break;
        
        case 'b':
            cout << (isEmpty(net) ? "Network is empty\n" : "Network is not empty\n");
            break;

        case 'c':
            cout << "Enter user name: ";
            cin >> user1;
            cout << (addMember(user1, net) ? "User added\n" : "User not added\n");
            break;

        case 'd':
            cout << "Enter first user name: ";
            cin >> user1;
            cout << "Enter second user name: ";
            cin >> user2;
            cout << (becomeFriends(user1, user2, net) ? "They are now friends\n" : "Friendship has failed\n");
            break;

        case 'e':
            cout << "Enter first user name: ";
            cin >> user1;
            cout << "Enter second user name: ";
            cin >> user2;
            cout << (areFriends(user1, user2, net) ? "Yes, they are friends\n" : "They are not friends\n");
            break;

        case 'f':
            cout << "Enter first user name: ";
            cin >> user1;
            cout << "Enter second user name: ";
            cin >> user2;
            cout << (leaveFriendship(user1, user2, net) ? "Friendship broken\n" : "They weren't friends\n");
            break;

        case 'g':
            cout << "\nEnter creator name: ";
            cin >> user1;
            cout << "Enter group name: ";
            cin >> gruppo;
            cout << (createGroup(user1, gruppo, net) ? "Group created\n" : "Problems occurred\n");
            break;

        case 'h':
            cout << "Enter user name: ";
            cin >> user1;
            cout << "Enter group name: ";
            cin >> gruppo;
            cout << (joinGroup(user1, gruppo, net) ? "Joined group\n" : "Failed to join group\n");
            break;

        case 'i':
            cout << "Enter user name: ";
            cin >> user1;
            cout << "Enter group name: ";
            cin >> gruppo;
            cout << (leaveGroup(user1, gruppo, net) ? "Left group\n" : "Failed to leave group\n");
            break;

        case 'j':
            cout << "Enter user name: ";
            cin >> user1;
            cout << (deleteMember(user1, net) ? "Deleted member\n" : "Failed to delete member\n");
            break;

        case 'k':
            cout << "Enter group name: ";
            cin >> gruppo;
            cout << (deleteGroup(gruppo, net) ? "Deleted group\n" : "Failed to delete group\n");
            break;

        case 'l':
            cout << "Enter user name: ";
            cin >> user1;
            cout << (makeMoreFriends(user1, net) ? "Made more friends\n" : "Failed to make more friends\n");
            break;

        case 'm':
            // Assuming a function to print the network details
            cout<<"\nFunction non temporary avaiable :c"<<endl;
            break;

        case 'o':
            printList(net);
            break;

        case 'p':
            cout << menu_list;
            break;

        case 'q':
            cout << "Exiting...\n";
            return;

        default:
            cout << "Invalid choice. Try again\n";
            break;
        }
    }
}

int main()
{
    menu();
    return 0;
}

/*
void print (Network &net)
{
  // if (isEmpty(net)){return;}

  char scelta;
  string input1, input2;

  cout<< "Cosa vuoi stampare?"<<endl;
  cout << "a. il nome di tutti gli user " << endl;
  cout << "b. il nome di tutti i gruppi" << endl;
  cout << "c. il nome di tutti gli amici di user" << endl;
  cout << "d. il nome di tutti i gruppi di user" << endl;
  cout << "e. il nome di tutti i gruppi creati da user" << endl;
  cout << "f. il nome di tutti i partecipanti del gruppo" << endl;

    cin >> scelta;

      if (scelta == 'q') {
          return; // Uscita dal programma
      }

      switch (scelta) {
          case 'a':
              printUserList(net);
              break;
          case 'b':
              printGroups(net);
              break;
          case 'c':
              cin >> input1;
              printUserFriend(input1, net);
              break;
          case 'd':
              cin >> input1;
              printUserGroups(input1, net);
              break;
          case 'e':
              cin >> input1;
              printCreatedGroups(input1, net);
              break;
          case 'f':
              cin >> input1;
              printGroupMemb(input1, net);
              break;
          default:
              cout << "Scelta non valida!" << endl;
              break;
      }
  
  
}

void printUserList (Network &net)
{
  if (isEmpty(net)){
    cout<<"e' vuota"<<endl;
    return;
  }
  
  cout << "\nGli utenti sono: ";

  User aux = net->userVertex;
  while (aux != nullptr){
    cout << aux->name;
    if (aux->next == nullptr){ 
      cout<< "."<<endl;} else {cout<< ", ";}
    aux = aux->next;
  }
  return;
}
//OK

void printGroups(Network &net){
    if (isEmpty(net)){
    cout<<"e' vuota"<<endl;
    return;
  }

  Group aux = net->groupVertex;

  if (aux == emptyGroup){
    cout<< "Non sono presenti gruppi."<<endl;
    return;
  }

  cout<<"\nI gruppi presenti nel network sono: ";
  while(aux!= emptyGroup){
    cout<< aux->gname;
    if (aux->next == nullptr){ 
      cout<< "."<<endl;} else {cout<< ", ";
    }
    aux = aux->next;
  }

  return;
}
//OK

void printUserFriend(string usr_Log, Network &net){
  if(isEmpty(net)){return;}

  User usr = getUser(usr_Log, net);
  if (usr == emptyUser){
    cout << "\nQuesto user non esiste"<<endl;
    return;
  }

  userList* aux = usr->friends;
  if (usr->friends == nullptr){
    cout << "Questo utente non ha amicizie"<<endl;
    return;
  }

  while (aux!= nullptr){
    cout <<aux->userPtr->name;
    if (aux->nextUser == nullptr){
      cout<< ".";} 
    else {cout<< ", ";}

    aux = aux->nextUser;
  }
  return;
}
//OK

void printUserGroups(string usr_Log, Network &net){
    if (isEmpty(net)){
    cout<< "Il network è vuoto"<<endl;
    return;
  }

  User usr = getUser(usr_Log, net);
  if (usr == emptyUser){
    cout << "Questo utente non esiste"<<endl;
    return;
  }

  usrGroupList* aux = usr->groups;
  if (aux == nullptr){
    cout<< usr_Log << " non e' in nessun gruppo"<<endl;
    return;
  }

  cout<< usr_Log << " e' membro di: ";
  while (aux!= nullptr){
    cout<< aux->groupPtr->gname << ", ";
    aux = aux->nextGroup;
  }
  cout<<endl;
  return;
}
//OK

void printCreatedGroups(string usr_Log, Network &net){
  if (isEmpty(net)){
    cout<< "Il network è vuoto"<<endl;
    return;
  }

  User usr = getUser(usr_Log, net);
  if (usr == emptyUser){
    cout << "Questo utente non esiste"<<endl;
    return;
  }

  usrGroupList* aux = usr->groups;
  if (aux == nullptr){
    cout<< usr_Log << " non ha creato gruppi"<<endl;
    return;
  }

  cout<< usr_Log << " ha creato: ";
  while (aux!= nullptr){
    if (aux->groupPtr->creator == usr_Log){
      cout<< aux->groupPtr->gname << ", ";
    }
    aux = aux->nextGroup;
  }
  cout<<endl;
  return;
}
//OK

void printGroupMemb(string g_Name, Network &net){
  if (isEmpty (net)){
    cout<< "Il network e' vuoto"<<endl;
    return;}
  
  Group grp = getGroup(g_Name, net);
  if (grp == emptyGroup){
    cout<< "Questo gruppo non esiste"<<endl;
    return;
  }

  userList* aux = grp->members;
  //opzione che non dovrebbe capitare, ma chi lo sa
  //io lo faccio per avere ogni possibilità
  if (aux == nullptr){
    cout << "Questo gruppo non ha membri"<<endl;
    return;
  }
  
  cout<<"I membri del gruppo sono: ";
  while (aux != nullptr){
    cout << aux->userPtr->name;
    if (aux->nextUser== nullptr){
      cout<<"."<<endl;}
    else {cout << ", ";}

    aux = aux->nextUser;
  }

  return;
}

*/