#include <iostream>
#include <string>
#include "dict-tree.h"

/*
  Funzione che costruisce manualmente un albero dizionario.
  Le parole inserite sono:
    - "cat"   (c -> a -> t -> '\0')
    - "car"   (c -> a -> (t brother r) -> '\0')
    - "dog"   (d -> o -> g -> '\0')
    - "door"  (d -> o -> (g brother o) -> r -> '\0')
*/
dictTree createDict() {
    // Costruzione della parte per le parole che iniziano per 'c': "cat" e "car"
    dictNode* node_c = new dictNode{'c', nullptr, nullptr};         // nodo 'c'
    dictNode* node_a = new dictNode{'a', nullptr, nullptr};           // figlio di 'c'
    node_c->son = node_a;

    // Nodo dopo 'a': biforcazione per 't' (per "cat") e 'r' (per "car")
    dictNode* node_t = new dictNode{'t', nullptr, nullptr};
    dictNode* node_r = new dictNode{'r', nullptr, nullptr};
    node_a->son = node_t;
    node_t->brother = node_r;

    // Terminazione della parola "cat"
    dictNode* node_end_cat = new dictNode{'8', nullptr, nullptr};
    node_t->son = node_end_cat;

    // Terminazione della parola "car"
    dictNode* node_end_car = new dictNode{'8', nullptr, nullptr};
    node_r->son = node_end_car;

    // Costruzione della parte per le parole che iniziano per 'd': "dog" e "door"
    dictNode* node_d = new dictNode{'d', nullptr, nullptr};
    // Inserisco 'd' come fratello di 'c'
    node_c->brother = node_d;

    dictNode* node_o = new dictNode{'o', nullptr, nullptr};
    node_d->son = node_o;

    // Per "dog": nodo 'g'
    dictNode* node_g = new dictNode{'g', nullptr, nullptr};
    node_o->son = node_g;
    dictNode* node_end_dog = new dictNode{'8', nullptr, nullptr};
    node_g->son = node_end_dog;

    // Per "door": partendo dallo stesso nodo 'o', si aggiunge un'alternativa come fratello di 'g'
    dictNode* node_o2 = new dictNode{'o', nullptr, nullptr};
    node_g->brother = node_o2;
    dictNode* node_r2 = new dictNode{'r', nullptr, nullptr};
    node_o2->son = node_r2;
    dictNode* node_end_door = new dictNode{'8', nullptr, nullptr};
    node_r2->son = node_end_door;

    return node_c; // restituisce la radice dell'albero
}

int main() {
    // Creazione del dizionario
    dictTree myDict = createDict();

    char choice;
    std::string word;

    // Stampa iniziale del menù
    std::cout << "Menu:" << std::endl;
    std::cout << "1 - Conta le parole nel dizionario (nbWords)" << std::endl;
    std::cout << "2 - Verifica se una parola e' presente (isPresent)" << std::endl;
    std::cout << "3 - Trova la parola piu' piccola (minWord)" << std::endl;
    std::cout << "p - Stampa di nuovo il menù" << std::endl;
    std::cout << "q - Esci" << std::endl;

    // Ciclo principale: finché l'utente non preme 'q'
    do {
        std::cout << "\nInserisci la tua scelta: ";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                unsigned int count = nbWords(myDict);
                std::cout << "Numero di parole nel dizionario: " << count << std::endl;
                std::cout << "Risultato mio: " << count << std::endl;
                std::cout << "Risultato atteso: 4" << std::endl;
                break;
            }
            case '2': {
                std::cout << "Inserisci la parola da cercare: ";
                std::cin >> word;
                bool result = isPresent(word, myDict);
                std::cout << "La parola '" << word << "' ";
                if (result)
                    std::cout << "e' presente nel dizionario." << std::endl;
                else
                    std::cout << "non e' presente nel dizionario." << std::endl;
                // Nel dizionario creato, solo "cat", "car", "dog" e "door" sono presenti.
                bool expected = (word == "cat" || word == "car" || word == "dog" || word == "door");
                std::cout << "Risultato mio: " << (result ? "true" : "false") << std::endl;
                std::cout << "Risultato atteso: " << (expected ? "true" : "false") << std::endl;
                break;
            }
            case '3': {
                std::string min = minWord(myDict);
                if (min.empty())
                    std::cout << "Il dizionario e' vuoto." << std::endl;
                else
                    std::cout << "La parola piu' piccola e': " << min << std::endl;
                std::cout << "Risultato mio: " << min << std::endl;
                std::cout << "Risultato atteso: car" << std::endl;
                break;
            }
            case 'p': {
                // Ristampa il menù
                std::cout << "\nMenu:" << std::endl;
                std::cout << "1 - Conta le parole nel dizionario (nbWords)" << std::endl;
                std::cout << "2 - Verifica se una parola e' presente (isPresent)" << std::endl;
                std::cout << "3 - Trova la parola piu' piccola (minWord)" << std::endl;
                std::cout << "p - Stampa di nuovo il menù" << std::endl;
                std::cout << "q - Esci" << std::endl;
                break;
            }
            case 'q': {
                std::cout << "Terminazione del programma." << std::endl;
                break;
            }
            default:
                std::cout << "Scelta non valida! Premi 'p' per visualizzare il menù." << std::endl;
        }
    } while (choice != 'q');

    return 0;
}
