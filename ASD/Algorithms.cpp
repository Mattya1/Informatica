#include <iostream>
#include <vector>
using namespace std;
/*ALGORITMI*/

/*
SELECTION SORT
BINARY SEARCH
MERGE SORT
INSERTION SORT
BUBBLE SORT
SELECTION SORT
QUICK SORT
BINARY SEARCH (RECURSIVE)

DFS DEPTH FIRST SEARCH 
BFS BREATH FIRST SEARCH
*/

void selectionSort ( int arr[], int lenght)
{
    // SS - Selection Sort
    /* cerco l'elemento più piccolo e lo metto in cima
    poi cerco il secondo più piccolo e lo metto al secondo posto
    ... */

    for (int i = 0; i < lenght - 1; ++ i)
    {
        //cerco smallestIndex
        int smallestIndex = i;
        for (int j = i+1; j < lenght -1; ++j)
        {
            if (arr[j] < arr[smallestIndex])
            {
                smallestIndex = j; 
            }
            
        }
        //swap del numero + piccolo nella seconda posizione
        int temp = arr[smallestIndex];
        arr[smallestIndex] = arr[i];
        arr[i] = temp;
    }
}


// INSERTION SORT
void insertionSort (int arr[], int lenght)
{
    int location;
    int temp;
    
    for(int f = 1; f < lenght; ++f)
    {
        if (arr[f] < arr[f-1])
        {                       //cioè se successivo < precedente
            
            temp = arr[f];      
            location = f;
            
            do //sposto l'elemento più grande indietro
            {
                arr [location] = arr [location - 1];
                location--;
            }
            while (location > 0 && arr [location-1] > temp);
            //continuo a spostarli tutti finchè non arrivo al posto giusto per temp
            arr[location] = temp; //colloco temp al posto giusto
        }
    }
}

// Bubblesort
void bubbleSort (int arr[], int lenght)
{
    for (int i = 0; i < lenght; ++i)
    {
        //lenght -1 -i perchè a ogni iterazione l'elem più grande
        //sarà già ordinato
        for (int j = 0; j < lenght -1-i; ++j)
        {
            if (arr[j] > arr[i])
            {   
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

// Bubblesort + efficente
void bubbleSort2 (int arr[], int lenght)
{
    for (int i = 0; i < lenght; ++i)
    {
        bool swapped = false;
        //lenght -1 -i perchè a ogni iterazione l'elem più grande
        //sarà già ordinato
        for (int j = 0; j < lenght -1-i; ++j)
        {
            swapped = false;
            if (arr[j] > arr[i])
            {   
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                swapped = true;
            }
            //così se è già ordinato finisco prima
            if (!swapped){
                return;
            }
        }
    }
}

//funziona solo su liste ordinate
int binarySearch(int arr[], int lenght, int val)
{
    for (int i = 0; i < lenght; ++i)
    {
        int min = 0;
        int max = lenght-1;
        int med;
        bool found;

        while (min <= max && found == false)
        {
            med = (min + max)/2;

            if (arr[med] == val){
                found = true;
            }
            //allora devo cercare più su
            else if (arr[med] > val)
            {
                max = med;
                med = (min + max)/2;
            }
            else //arr[med] < val
            {
                max = med-1;
            }

        }

        if (found){
            return med;
        } else{
            return -1;
        }
    }
}

void mergeSort(int arr[], int first, int last)
{

}

int partition(int arr[], int first, int last)
{
    int pivot = arr[last];  // il pivot è l'ultimo elem
    int i = first - 1;      //
    // Loop through the array to find elements smaller than the pivot
    for (int j = first; j < last; ++j)
    {
        if (arr[j] < pivot)
        {
            i++;  // Increment the smaller element index
            // Swap arr[i] with arr[j] to bring smaller elements to the left
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap the pivot element (arr[last]) with the element at arr[i + 1]
    int temp = arr[i + 1];
    arr[i + 1] = arr[last];
    arr[last] = temp;

    // Return the pivot index
    return i + 1;
}


void quickSort(int arr[], int first, int last)
{
    if (first < last) //si fermerà quando first == last
    {
        int pivot = partition(arr, first, last);
        quickSort(arr, 0, pivot-1);
        quickSort(arr, pivot+1, last);
    }
}

int recursiveBinarySearch(int arr[], int lenght, int val)
{
    // non he ho voglia ciaooooooooooo
    return 0;
}

void printArray (int arr[], int lenght)
{
    for (int i = 0; i < lenght; ++i)
    {
        std::cout << arr[i] << ", " << std::endl; 
    }
}

int main() {
    int arr[] = {34, 7, 23, 32, 5, 62, 78, 1, 45, 19}; // Array disordinato
    char choice;

    do {
        std::cout << "\n--- Menu ---" << std::endl;
        std::cout << "1. Selection Sort" << std::endl;
        std::cout << "2. Insertion Sort" << std::endl;
        std::cout << "3. Bubble Sort" << std::endl;
        std::cout << "4. Bubble Sort Ottimizzato" << std::endl;
        std::cout << "5. Binary Search" << std::endl;
        std::cout << "6. Merge Sort" << std::endl;
        std::cout << "7. Quick Sort" << std::endl;
        std::cout << "8. Binary Search Ricorsiva" << std::endl;
        std::cout << "q. Esci" << std::endl;
        std::cout << "Scegli un'opzione: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                selectionSort(arr, 9);
                std::cout << "Array ordinato con Selection Sort: ";
                printArray(arr, 9);
                break;

            case '2':
                insertionSort(arr, 9);
                std::cout << "Array ordinato con Insertion Sort: ";
                printArray(arr, 9);
                break;

            case '3':
                bubbleSort(arr, 9);
                std::cout << "Array ordinato con Bubble Sort: ";
                printArray(arr, 9);
                break;

            case '4':
                bubbleSort2(arr, 9);
                std::cout << "Array ordinato con Bubble Sort Ottimizzato: ";
                printArray(arr, 9);
                break;

            case '5': {
                int target;
                std::cout << "Inserisci il valore da cercare: ";
                std::cin >> target;
                int index = binarySearch(arr, 9, target);
                if (index != -1) {
                    std::cout << "Valore trovato all'indice " << index << "." << std::endl;
                } else {
                    std::cout << "Valore non trovato." << std::endl;
                }
                break;
            }

            case '6':
                mergeSort(arr, 0, 9);
                std::cout << "Array ordinato con Merge Sort: ";
                printArray(arr, 9);
                break;

            case '7':
                quickSort(arr, 0, 9);
                std::cout << "Array ordinato con Quick Sort: ";
                printArray(arr, 9);
                break;

            case '8': {
                int target;
                std::cout << "Inserisci il valore da cercare: ";
                std::cin >> target;
                int index = recursiveBinarySearch(arr, 9, target);
                if (index != -1) {
                    std::cout << "Valore trovato all'indice " << index << "." << std::endl;
                } else {
                    std::cout << "Valore non trovato." << std::endl;
                }
                break;
            }

            case 'q':
            case 'Q':
                std::cout << "Uscita dal programma." << std::endl;
                break;

            default:
                std::cout << "Opzione non valida. Riprova." << std::endl;
        }
    } while (std::tolower(choice) != 'q');

    return 0;
}
