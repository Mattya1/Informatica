#include "dict-tree.h"
#include <string>

using namespace std;

// Funzione di supporto per ottenere la parola partendo da un nodo
string getWord(const dictTree& dt) {
    if (dt == nullptr || dt->val == '8') {
        return "";
    }
    return string(1, dt->val) + getWord(dt->son);
}

// Funzione principale
string minWord(const dictTree& dt) {
    if (dt == emptyDictTree) {
        return "";
    }

    // La parola più piccola tra i figli e i fratelli
    string smallest = getWord(dt);
    
    if (dt->brother != nullptr) {
        string brotherSmallest = minWord(dt->brother);
        if (brotherSmallest < smallest) {
            smallest = brotherSmallest;
        }
    }

    if (dt->son != nullptr) {
        string sonSmallest = minWord(dt->son);
        if (sonSmallest < smallest) {
            smallest = sonSmallest;
        }
    }

    return smallest;
}
