/* 15. Scrivere un programma che scambia fra loro i valori di due variabili int senza usare variabili di appoggio. Il programma
deve essere scritto in un file chiamato magicswap.cpp.
[SUGGERIMENTO: l’or esclusivo, o XOR (in C++ l’operatore ^), gode di varie proprietà, tra cui la proprietà di simmetria
– cioè A^B == B^A – e la proprietà associativa – cioè (A^B)^C == A^(B^C). Inoltre, A^A ==0 e A^0==A per
qualsiasi A, B e C */

#include <iostream>
using namespace std;

int main ()
{

int num1, num2;

cout << "inserisci due numeri: ";
cin >> num1 >> num2;

  /*Supponiamo che l'utente inserisca a = 5 e b = 9
	a = a ^ b; 	a = 5 ^ 9 = 12
    b = a ^ b;  b = 12 ^ 9 = 5
    a = a ^ b; 	a = 12 ^ 5 = 9 */


num1= num1^num2;

cout << "primo xor " << num1 <<endl;

num2= num1^num2;

cout << "secondo xor " << num2 << endl;

num1= num1^num2;

cout << "terzo xor " << num1 << endl;

cout << "il primo numero e' " << num1 << '\n'
	 << "il secondo numero e' " << num2;

}