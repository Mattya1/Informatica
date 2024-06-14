#include <iostream>
#include "network.h"
// #include "list-array.h"

// using namespace std;
using namespace network;
// using namespace list;

void printList(const list::List& lst) {
    for (int i = 0; i < size(lst); ++i) {
        cout << get(i, lst) << " ";
    }
    cout << endl;
}

void menu() {
    Network net = createEmptyNetwork();
    list::List groupList = list::createEmpty();
    char choice;
    string usr_Log, usr_Log1, usr_Log2, g_Name;
    
    do {
        cout << "\nNetwork Menu:\n";
        cout << "a. Create Empty Network\n";
        cout << "b. Check if Network is Empty\n";
        cout << "c. Add Member\n";
        cout << "d. Become Friends\n";
        cout << "e. Leave Friendship\n";
        cout << "f. Add Group\n";
        cout << "g. Join Group\n";
        cout << "h. Leave Group\n";
        cout << "i. List Members\n";
        cout << "j. List Groups\n";
        cout << "k. List Friends\n";
        cout << "l. List Member Of Groups\n";
        cout << "m. List Creator Of Groups\n";
        cout << "n. Make More Friends\n";
        cout << "o. Print Network\n";
        cout << "p. Check if Friends\n";
        cout << "q. Delete Group\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 'a':
                net = createEmptyNetwork();
                cout << "Empty network created.\n";
                break;
            case 'b':
                cout << (isEmpty(net) ? "Network is empty.\n" : "Network is not empty.\n");
                break;
            case 'c':
                cout << "Enter user login: ";
                cin >> usr_Log;
                cout << (addMember(usr_Log, net) ? "Member added.\n" : "Failed to add member.\n");
                break;
            case 'd':
                cout << "Enter first user login: ";
                cin >> usr_Log1;
                cout << "Enter second user login: ";
                cin >> usr_Log2;
                cout << (becomeFriends(usr_Log1, usr_Log2, net) ? "Users are now friends.\n" : "Failed to become friends.\n");
                break;
            case 'e':
                cout << "Enter first user login: ";
                cin >> usr_Log1;
                cout << "Enter second user login: ";
                cin >> usr_Log2;
                cout << (leaveFriendship(usr_Log1, usr_Log2, net) ? "Friendship ended.\n" : "Failed to leave friendship.\n");
                break;
            case 'f':
                cout << "Enter group name: ";
                cin >> g_Name;
                cout << "Enter user login: ";
                cin >> usr_Log;
                cout << (createGroup(usr_Log, g_Name, net) ? "Group added.\n" : "Failed to add group.\n");
                break;
            case 'g':
                cout << "Enter group name: ";
                cin >> g_Name;
                cout << "Enter user login: ";
                cin >> usr_Log;
                cout << (joinGroup(usr_Log, g_Name, net) ? "User joined group.\n" : "Failed to join group.\n");
                break;
            case 'h':
                cout << "Enter user login: ";
                cin >> usr_Log;
                cout << "Enter group name: ";
                cin >> g_Name;
                cout << (leaveGroup(usr_Log, g_Name, net) ? "User left group.\n" : "Failed to leave group.\n");
                break;
            case 'i':
                // cout << "Members: ";
                // groupList = members(net);
                break;
            case 'j':
                // cout << "Groups: ";
                // groupList = groups(net);
                break;
            // case 'k':
            //     cout << "Enter user login: ";
            //     cin >> usr_Log;
            //     cout << "Friends: ";
            //     groupList = friends(usr_Log, net);
                break;
            case 'l':
                // cout << "Enter user login: ";
                // cin >> usr_Log;
                // cout << "Groups user is a member of: ";
                // groupList = memberOf(usr_Log, net);
                break;
            case 'm':
                // cout << "Enter user login: ";
                // cin >> usr_Log;
                // cout << "Groups user is a creator of: ";
                // creatorOf(usr_Log, net);
                break;
            case 'n':
                cout << "Enter user login: ";
                cin >> usr_Log;
                cout << (makeMoreFriends(usr_Log, net) ? "User made more friends.\n" : "Failed to make more friends.\n");
                break;
            case 'o':
                // print(net);
                break;
            case 'p':
                cout << "Enter first user login: ";
                cin >> usr_Log1;
                cout << "Enter second user login: ";
                cin >> usr_Log2;
                cout << (areFriends(usr_Log1, usr_Log2, net) ? "Users are friends.\n" : "Users are not friends.\n");
                break;
            case 'q':
                cout << "Enter group name: ";
                cin >> g_Name;
                cout << (deleteGroup(g_Name, net) ? "Group deleted.\n" : "Failed to delete group.\n");
                break;
            case '0':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '0');
}

int main() {
    menu();
    return 0;
}
