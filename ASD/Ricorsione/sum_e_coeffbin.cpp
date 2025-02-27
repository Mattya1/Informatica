#include <iostream>
using namespace std;


unsigned sommatoria(unsigned n)
{
    cout << "sommatoria " << n << "\n";
	if (n==0) 
		return 0;
    else
	    return n+sommatoria(n-1);
}


unsigned coeffBin(unsigned n, unsigned k) {
// se k>n solleva eccezione
	if (k>n) 
	{
        string err = "\ncoeff bin non corretto\n";
        throw (err); 
    }
    
    // se n==k oppure k==0 ritorna 1
	if (n==k || k==0)
		return 1;

    // altrimenti ritorna la somma del coefficiente binomiale di n-1 e k-1 e del coefficiente binomiale di n-1 e k
	else
		return (coeffBin(n-1, k-1)+coeffBin(n-1, k));	
}



int main()
{
    try{
    	    int input, n, k;
    		cout << "\nInserire un numero maggiore o uguale a zero per la sommatoria: ";
    		cin >> input;
              cout << "\nInserire n per coeffBin: ";
    		cin >> n;
              cout << "\nInserire k (minore di n) per coeffBin: ";
    		cin >> k;
		    
            if (input < 0 || n < 0 || k < 0) 
			    cout << "\nInput sbagliato!\n";
		   
            else
            {
    			cout << "\n";
   		    	unsigned sum_res = sommatoria(input);
   			    cout << "\nIl risultato della sommatoria per i che va da 1 a " << input << " di i e' " << sum_res << "\n";
               
                unsigned coeff_res = coeffBin(n,k);
   			    cout << "\nIl coefficiente binomiale di " << n << " su " << k << " e' " << coeff_res << "\n";
			} 
		}
	catch(string e)
	{	 
		cout << e;
	}
}

