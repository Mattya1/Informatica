/* 3. Scrivere un programma che scrive in lettere i nomi italiani delle ore, approssimati ai 15 minuti. Il programma deve prendere
in input due valori interi, uno tra 0 e 23 (ore) e l’altro tra 0 e 59 (minuti) e se i valori dati in input non rispettano il vincolo
stampa un messaggio di errore ed esce ritornando -1 come codice di errore. 
Se l’input è corretto, scrive “Sono le ore " seguito dal valore delle ore 
(p.es. se è 11 scrive “undici", ma se è 1 scrive “l’una" e se è 0 scrive “mezzanotte") e dal valore dei minuti,
approssimato per difetto al quarto d’ora (ad esempio se i minuti sono 15-29 scrive “ e un quarto", se 30-44 scrive “ e mezza",
se 45-59 scrive “ e tre quarti"; se 0-14 invece non scrive niente). Infine, se i minuti non sono divisibili esattamente per 15,
scrive “ passate". Esempio: 12:34 "Sono le ore dodici e mezza passate", 00:56 "Sono le ore mezzanotte e tre quarti passate".
[ File saytime.cpp */

#include <iostream>
using namespace std;

int main ()
{
	
int ore, min;

cout <<"Inserisci un orario: ";
cin >> ore >> min;

	if (0> ore >23 || 0 > min> 59){
		cout << "orario non valido";
	}
	else{
		
		cout << "sono le ore ";
		if (ore == 0){
			cout<< "mezzanotte ";}
		else if (ore == 1 || ore == 13){
			cout<< "l'una ";}
		else if (ore == 2 || ore == 14){
			cout<< "due ";}
		else if (ore == 3 || ore == 15){
			cout<< "tre ";}
		else if (ore == 4 || ore == 16){
			cout<< "quattro ";}
		else if (ore ==5 || ore == 17){
			cout<< "cinque ";}
		else if (ore == 6 || ore == 18){
			cout<< "sei ";}
		else if (ore == 7 || ore == 19){
			cout<< "sette ";}
		else if (ore == 8 || ore == 20){
			cout<< "otto ";}
		else if (ore ==9 || ore == 21){
			cout<< "nove ";}
		else if (ore == 10 || ore == 22){
			cout<< "dieci ";}
		else if (ore == 11 || ore == 23){
			cout<< "undici ";}
			
		if (min >= 15 && min <= 29){
		cout<< "e un quarto";}
		else if (min >= 30 && min <=44){
		cout<< "e mezza";}
		else if (min >= 45 && min <=59){
		cout<< "e tre quarti";}
		
		if (min%15!=0){
		cout<< " passate";}
	}
	
}