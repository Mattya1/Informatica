/* Scrivere una funzione che preso come argomento numero intero strettamente positivo stampa un triangolo rettangolo fatto
di '*' con lato lungo quanto il numero letto. Ad esempio, ricevuto come argomento il valore 5, stamperà: triangolo*/

#include <iostream>
using namespace std;

struct OutOfRangeError
{
	string functionName;
	string paramName;
	int paramValue;
};

void replicate(int lenght, char c)
{
	if (lenght<0){
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


void triangle (int lenght)
{
	
	if (lenght <=0)
	{
		OutOfRangeError err;
		err.functionName = "triangle";
		err.paramName = "lenght";
		err.paramValue = lenght;
		throw err;
	}
	else
	{
	int i;
	
		for (i=0; i<=lenght; i++)
		{
			replicate (i, '*');
			cout << "\n";
		}
	}
}

int main ()
{
	try
	{
		int len;
		cout << "Inserisci un numero maggiore di 0: ";
		cin >> len;
		
		triangle(len);
	}
	catch(OutOfRangeError& err){
		cout << "Errore\n"
			<< err.functionName << " "
			<< err.paramName << " = "
			<< err.paramValue;
		
	}
}