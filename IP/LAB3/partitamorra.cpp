/*9. Partendo dall’esercizio 2.9 (vedi precedente sezione) scrivere un programma che gioca più mani di morra cinese però contro
il computer. Come primo passo consigliamo di modificare l’esercizio 2.9 in modo da inserire per il turno del computer
(che sostituisce Giocatore 2) la generazione di una mossa random (suggerimento: generare un numero intero tra 0 e 2 e
associarlo alle mosse 0=>’f’, 1=>’c’, 2=>’s’). Esempio minimale di generazione di un numero random compreso tra 0 e 9
(per l’esercizio servirà tra 0 e 2):

Poi, alla fine di ogni mano il programma deve dire chi ha vinto (cioè il giocatore umano o il computer) ha vinto e chiedere all’utente se vuole continuare; se l’utente risponde ’S’ o ’s’ prosegue con un’altra mano, altrimenti termina. [ File
partitamorra.cpp ]*/

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() 
{
    char gioc1, gioc2;
	char ancora;
	srand(time(NULL)); // questa linea va eseguita una volta sola nel programma	

while (true){

    cout << "mossa giocatore 1: "<< endl;
    cin >> gioc1;

//con il ciclo while controllo l' corretto dei valori
    while (gioc1 != 'f' && gioc1 != 's' && gioc1 != 'c')
    {
        cout << "valore non valido, riprova: ";
        cin >> gioc1;
    }

	int randomNumber = (rand()%10); // questa invece va eseguita ogni volta che vogliamo generare un nuovo numero    
	if (randomNumber == 0){
		gioc2 = 'f';}
	else if (randomNumber == 1){
		gioc2 = 'c';}
	else if (randomNumber == 2){
		gioc2='s';}
		
	cout<< gioc2<<endl;
       

//controllo prima il caso di parità, e poi confronto gli altri
    if (gioc1 == gioc2){
        cout << "parita'! "<<endl;
    }
    else if (gioc1 == 'f'){
        if(gioc2 == 'c'){
            cout << "Giocatore 1 hai vinto!"<<endl;
        }
        else {
            cout << "Giocatore 2 hai vinto!"<<endl;
        }
    }
    else if (gioc1 == 's'){
        if (gioc2 == 'f'){
            cout << "Giocatore 1 hai vinto!" <<endl;
        }
        else {
            cout << "Giocatore 1 hai vinto!" <<endl;
        }
    }

//chiedo se vuole giocare ancora

 cout<< "vuoi giocare ancora?"<< endl;
 cin >> ancora;
 if (ancora != 's' && ancora != 'S'){
 break;}
}
}