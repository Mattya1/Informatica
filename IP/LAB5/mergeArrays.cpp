/*creare due array e riempirli di numeri casuali.
metterli in maniera ordinata in un terzo array di lunghezza uguale alla somma
della lunghezza dei due array */

#include <iostream>
using namespace std;

int main ()
{
	int N, M;
	cout << "Inserisci lunghezza del primo array: ";
	cin >> N;
	
	cout << "\nInserisci lunghezza del secondo array: ";
	cin >> M;
	
	int s1[N], s2[M], result[N+M];
	int i;
	
	srand(time(NULL)); // questa linea va eseguita una volta sola nel programma4
	
	/*rand() ritorna un int randomico
	%10 limita il range dell'int da 0 a 9 */
	
	// riempo di numeri randomici il primo array
	for (i=0; i<N; ++i)
	{
		s1[i]= (rand()%256);		//serve a generare ogni volta un num random
	}
	
	cout << "\nArray s1 (generato) = (";
	for (i=0; i<N-1; i++)
	{
		cout << s1[i] <<", ";
	}
	cout << s1 [(i)]<<")";
	
// riempo di numeri randomici il secondo array
	for (i=0; i<M; ++i)
	{
		s2[i]= (rand()%256);
	}

	cout << "\nArray s2 (generato) = (";
	for (i=0; i<M-1; ++i)
	{
		cout << s2[i] <<", ";
	}
	cout << s2[(i)]<<")";
	
//ora devo sortare separatamente i due array
//sorting s1
	for (i=0; i<N-1; ++i)
	{
		//cerco smallestIndex tra s1[i] e s1[M-1] e assegno il suo valore a mini
		int smallestIndex=i;	//tiene traccia della posizione
		for (int mini= i+1; mini<N; ++mini)
		{
			if (s1[mini]<s1[smallestIndex])
				smallestIndex=mini; //swappo la posizione di riferimento
		}
		
		//scambio s1[i] con s1[smallestIndex]
		int temp = s1[smallestIndex];
		s1[smallestIndex] = s1[i];
		s1[i]=temp;
	}

//sorting s2
	for (i=0; i<M-1; ++i)
	{
		//cerco smallestIndex tra s2[i] e s2[N-1] e assegno il suo valore a mini
		int smallestIndex=i;	//tiene traccia della posizione
		for (int mini= i+1; mini<M; ++mini)
		{
			if (s2[mini]<s2[smallestIndex])
				smallestIndex=mini; //swappo la posizione di riferimento
		}
		
		//scambio s1[i] con s1[smallestIndex]
		int temp = s2[smallestIndex];
		s2[smallestIndex] = s2[i];
		s2[i]=temp;
	}
	

	cout << "\nArray s1 (ordinato) = (";
	for (i=0; i<N-1; ++i)
	{
		cout << s1[i] <<", ";
	}
	cout << s1[(i)]<<")";
	
	cout << "\nArray s2 (ordinato) = (";
	for (i=0; i<M-1; ++i)
	{
		cout << s2[i] <<", ";
	}
	cout << s2[(i)]<<")";

//merge dei due array in maniera ordinata
//devo confrontare i numeri pian piano che li metto

	int j=0, k=0;
	i=0;
	
	while (i<N && j<M)	//questa operazione finisce alla fine di uno dei due array
	{
		if (s1[i]<=s2[j]){
			result[k]=s1[i]; //oppure result[k++] = s1[i++](usa k/i e poi aumenta)
			k++;
			i++;
		}
		else{
			result[k] = s2 [j];
			k++;
			j++;
		}
		
	}
	
	//se mancano item dal primo array
	while (i<N){
	result[k++] =s1[i++];}
	
	//se mancano item dal secondo array
	while (j<M){
	result[k++]= s2[j++];}

	cout << "\nArray d= (";
	for (i=0; i<(M+N)-1; i++)
	{
		cout << result[i] <<", ";
	}
	cout << result [(i)]<<")";
	
	return 0;
}