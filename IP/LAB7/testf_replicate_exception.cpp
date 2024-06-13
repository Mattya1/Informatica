/* Scrivere una funzione chiamata replicate, che restituisce void. La funzione riceve come argomenti un numero intero N> 0
e un carattere c, e stampa N volte il carattere c. Usare le eccezioni per gestire i casi di errore. In particolare la funzione
replicate come segue. Dichiarare una struct OutOfRangeError con un campo stringa chiamato functionName, un campo
stringa chiamato paramName e uno di tipo intero chiamato paramValue. */

#include <iostream>
using namespace std;

struct OutOfRangeError{
	string functionName;
	string paramName;
	int paramValue;
};

void replicate(int lenght, char c)
{
	if (lenght<=0){
		OutOfRangeError err;
		err.functionName = "replicate";
		err.paramName = "lenght";
		err.paramValue = lenght;
		throw err;
	}
	else{
	
		int i;
		for (i=0; i<lenght; i++)
		{	
			cout << c;
		}
	}
}

int main ()
{
	
	try{
		int len;
		cout << "Inserisci un numero maggiore di 0: ";
		cin >> len;
		
		char c;
		cout << "Inserisci il carattere da replicare: ";
		cin >> c;
		
		replicate (len, c);
	}
	catch(OutOfRangeError& err)
	{
		cout<< "Errore:\n" 
			<< err.functionName << " "
			<< err. paramName << " = "
			<< err.paramValue;
	}	
}