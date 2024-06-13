#include "network.h"
#include <cstddef>
#include <string>
#include <iostream>

using namespace std;
using namespace network;

int main() {
    // Creazione di una rete vuota
    Network net = createEmptyNetwork();
    
    // Verifica che la rete sia vuota
    if (isEmpty(net)) {
        cout << "La rete è vuota." << endl;
    } else {
        cout << "Errore: la rete dovrebbe essere vuota." << endl;
    }

    // Aggiunta di membri alla rete
    cout << "Aggiunta membri..." << endl;
    addMember("user1", net);
    addMember("user2", net);
    addMember("user3", net);
    addMember("user4", net);
    addMember("user5", net);

    // Verifica che i membri siano stati aggiunti
    cout << "Verifica membri aggiunti..." << endl;
    list::List membersList = members(net);
    cout << "Membri della rete: ";
    for (size_t i = 0; i < static_cast<size_t>(list::size(membersList)); ++i) {
        cout << list::get(i, membersList) << " ";
    }
    cout << endl;

    // Creazione di amicizie
    cout << "Creazione amicizie..." << endl;
    becomeFriends("user1", "user2", net);
    becomeFriends("user1", "user3", net);
    becomeFriends("user2", "user3", net);
    becomeFriends("user2", "user4", net);
    becomeFriends("user3", "user5", net);

    // Verifica delle amicizie
    cout << "Verifica amicizie..." << endl;
    if (areFriends("user1", "user2", net)) {
        cout << "user1 e user2 sono amici." << endl;
    } else {
        cout << "Errore: user1 e user2 dovrebbero essere amici." << endl;
    }

    if (areFriends("user1", "user3", net)) {
        cout << "user1 e user3 sono amici." << endl;
    } else {
        cout << "Errore: user1 e user3 dovrebbero essere amici." << endl;
    }

    if (!areFriends("user1", "user4", net)) {
        cout << "user1 e user4 non sono amici." << endl;
    } else {
        cout << "Errore: user1 e user4 non dovrebbero essere amici." << endl;
    }

    // Creazione di gruppi
    cout << "Creazione gruppi..." << endl;
    createGroup("user1", "group1", net);
    createGroup("user2", "group2", net);
    createGroup("user3", "group3", net);

    // Unione ai gruppi
    cout << "Unione ai gruppi..." << endl;
    joinGroup("user3", "group1", net);
    joinGroup("user4", "group1", net);
    joinGroup("user5", "group2", net);
    joinGroup("user1", "group3", net);

    // Verifica dei gruppi
    cout << "Verifica gruppi..." << endl;
    list::List groupsList = groups(net);
    cout << "Gruppi della rete: ";
    for (size_t i = 0; i < static_cast<size_t>(list::size(groupsList)); ++i) {
        cout << list::get(i, groupsList) << " ";
    }
    cout << endl;

    list::List groupMembers = memberOf("user1", net);
    cout << "Gruppi di cui user1 è membro: ";
    for (size_t i = 0; i < static_cast<size_t>(list::size(groupMembers)); ++i) {
        cout << list::get(i, groupMembers) << " ";
    }
    cout << endl;

    list::List user1Friends = friends("user1", net);
    cout << "Amici di user1: ";
    for (size_t i = 0; i < static_cast<size_t>(list::size(user1Friends)); ++i) {
        cout << list::get(i, user1Friends) << " ";
    }
    cout << endl;

    // Verifica creatori di gruppi
    list::List user1CreatedGroups = creatorOf("user1", net);
    cout << "Gruppi creati da user1: ";
    for (size_t i = 0; i < static_cast<size_t>(list::size(user1CreatedGroups)); ++i) {
        cout << list::get(i, user1CreatedGroups) << " ";
    }
    cout << endl;

    // Verifica dell'amicizia multipla
    makeMoreFriends("user3", net);

    // Verifica nuove amicizie di user3
    list::List user3Friends = friends("user3", net);
    cout << "Nuovi amici di user3: ";
    for (size_t i = 0; i < static_cast<size_t>(list::size(user3Friends)); ++i) {
        cout << list::get(i, user3Friends) << " ";
    }
    cout << endl;

    // Eliminazione di membri e gruppi
    deleteMember("user4", net);
    deleteGroup("group2", net);

    // Verifica dell'eliminazione
    membersList = members(net);
    cout << "Membri della rete dopo eliminazione: ";
    for (size_t i = 0; i < static_cast<size_t>(list::size(membersList)); ++i) {
        cout << list::get(i, membersList) << " ";
    }
    cout << endl;

    groupsList = groups(net);
    cout << "Gruppi della rete dopo eliminazione: ";
    for (size_t i = 0; i < static_cast<size_t>(list::size(groupsList)); ++i) {
        cout << list::get(i, groupsList) << " ";
    }
    cout << endl;

    // Lasciare amicizie e gruppi
    leaveFriendship("user1", "user2", net);
    leaveGroup("user3", "group1", net);

    // Verifica dell'uscita dalle amicizie e dai gruppi
    if (!areFriends("user1", "user2", net)) {
        cout << "user1 e user2 non sono più amici." << endl;
    } else {
        cout << "Errore: user1 e user2 non dovrebbero essere più amici." << endl;
    }

    groupMembers = memberOf("user3", net);
    cout << "Gruppi di cui user3 è membro dopo aver lasciato group1: ";
    for (size_t i = 0; i < static_cast<size_t>(list::size(groupMembers)); ++i) {
        cout << list::get(i, groupMembers) << " ";
    }
    cout << endl;

    // Aggiunta di ulteriori membri e test con gruppi
    addMember("user6", net);
    addMember("user7", net);

    // Creazione di nuove amicizie
    becomeFriends("user6", "user7", net);
    becomeFriends("user6", "user1", net);

    // Creazione di nuovi gruppi
    createGroup("user6", "group4", net);
    createGroup("user7", "group5", net);

    // Unione ai nuovi gruppi
    joinGroup("user1", "group4", net);
    joinGroup("user2", "group5", net);
    joinGroup("user3", "group4", net);

    // Verifica delle nuove amicizie
    if (areFriends("user6", "user7", net)) {
        cout << "user6 e user7 sono amici." << endl;
    } else {
        cout << "Errore: user6 e user7 dovrebbero essere amici." << endl;
    }

    if (areFriends("user6", "user1", net)) {
        cout << "user6 e user1 sono amici." << endl;
    } else {
        cout << "Errore: user6 e user1 dovrebbero essere amici." << endl;
    }

    // Verifica dei nuovi gruppi
    list::List newGroupsList = groups(net);
    cout << "Gruppi della rete (inclusi nuovi): ";
    for (size_t i = 0; i < static_cast<size_t>(list::size(newGroupsList)); ++i) {
        cout << list::get(i, newGroupsList) << " ";
    }
    cout << endl;

    // Tentare di eliminare un membro non esistente
    if (!deleteMember("user8", net)) {
        cout << "Errore: user8 non esiste nella rete." << endl;
    }

    // Tentare di eliminare un gruppo non esistente
    if (!deleteGroup("groupNonExistent", net)) {
        cout << "Errore: groupNonExistent non esiste nella rete." << endl;
    }

    // Rimuovi amicizia e verifica
    leaveFriendship("user6", "user1", net);
    if (!areFriends("user6", "user1", net)) {
        cout << "user6 e user1 non sono più amici." << endl;
    } else {
        cout << "Errore: user6 e user1 non dovrebbero essere più amici." << endl;
    }

    // Rimuovi un utente e verifica
    deleteMember("user5", net);
    membersList = members(net);
    cout << "Membri della rete dopo eliminazione di user5: ";
    for (size_t i = 0; i < static_cast<size_t>(list::size(membersList)); ++i) {
        cout << list::get(i, membersList) << " ";
    }
    cout << endl;

    // Rimuovi un gruppo e verifica
    deleteGroup("group1", net);
    groupsList = groups(net);
    cout << "Gruppi della rete dopo eliminazione di group1: ";
    for (size_t i = 0; i < static_cast<size_t>(list::size(groupsList)); ++i) {
        cout << list::get(i, groupsList) << " ";
    }
    cout << endl;

    return 0;
}
