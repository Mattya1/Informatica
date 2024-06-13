//conf efficenza

#include <iostream>
using namespace std;

int main ()
{
	int N=30, arr[N]={1,2,3,4,5,6,7,8,9,11,13,15,17,19,20,22,29,30,31,32,36,45,48,49,50,55,57,60,62,65};
	//30 elementi
	
	int item;
	cout<<"inserisci l'item da cercare: ";
	cin >> item;
	
	int first = 0;
	int last = N-1;
	int mid;
	int	count=0;
	bool found = false;

	while (first<=last && !found)
	{

		mid=(first+last)/2;
		count++; 					//qua conto accessi all'array
		
		//in questo blocco sposto il punto di focus
		if (arr[mid]==item){
		found = true;
		count++;}		
		else if (arr[mid]>item){
			last=mid-1;}			//item è nella prima metà
		else{
			first=mid+1;}			//item è nella seconda metà
		
	}
	
	if (found==true){
		cout<< "\ntrovato"<<endl;}
	else{
		cout<< "\nnon trovato :("<<endl;
		return -1;}
		
	cout<<"accesso effettuato " << count<< " volte";

	
	return 0;
}