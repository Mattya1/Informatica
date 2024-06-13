//confronto efficenza

using namespace std;

int main ()
{
	int N=30, arr[N]={1,2,3,4,5,6,7,8,9,11,13,15,17,19,20,22,29,30,31,32,36,45,48,49,50,55,57,60,62,65};
	//30 elementi
	
	int i;
	
	int count =0;

	int loc = -1;
	bool found = false;
	int item;

	cout << "inserisci item da cercare: ";
	cin >> item;

	cout <<"\n" << "inserisci l'array: ";

	for (i=0; i<N; i++)
	{
		cin >> arr[i];
	}

	for (i=0; i<N; i++)
	{
		if (arr[i] == item){
			found=true;
			loc = i;
			count++;
			break;		//cosi' esco dal loop, altrimenti loc cambierebbe
		}
	 
	}

	if (found==true){
		cout << item << " e' stato trovato in posizione " << loc;}
	else{
		cout << item << " non e' stato trovato";}
		
	cout<< "\nricerca effettuata "<< count << " volte.";
		
	return 0;
}