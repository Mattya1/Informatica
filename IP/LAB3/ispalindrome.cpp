/*Scrivere un programma che chiede all’utente un numero intero e verifica se è palindromo, ovvero se le sue cifre (in base 10)
lette da destra a sinistra corrispondono alle cifre lette da sinistra a destra (ad esempio 165373561 è palindromo). Dopo la
verifica stampa il risultato all’utente. Per risolvere questo esercizio si può partire dalla soluzione dell’esercizio 3.8. [ File
ispalindrome.cpp ]*/

#include <iostream>
using namespace std;

int main ()
{

int k,num;
int inv=0;
int mod=0;

cout << "Inserire un numero positivo: ";
cin >> k;
num=k;

	if (k<0){
		cout << "Valore non valido";
		return 66;}

while (k!=0){		
	mod = k%10;		
	inv= inv*10;
	inv= inv+mod;
	k=k/10;}
	
/*es: 753
num= 753%10
quoz= 3
rev = 0+3 = 3

num 75%10
quoz 5
rev = 3+5 = 35

num 7%10
quoz 7
rev = 35+7 = 357	*/

cout << "si ottiene " << inv<< endl;

if (num == inv){
	cout<< "e' palindromo";
}
else{
	cout<< "non e' palindromo";
}

}