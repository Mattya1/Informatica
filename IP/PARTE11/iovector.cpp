#include <iostream>
#include <vector>
#include <string>
#include "iovector.h"
using namespace std;

void readVector (vector<int> &v)
{
	cout << "Inserisci la dimensione della sequenza: ";
	int N=0; cin >> N;
	
	while (N<=0)
	{
		cout << "La dimensione deve essere positiva - riprova: ";
		cin >> N;
	}
	
	//v.resize (N); in questo modo modifico la dimensione e la riempo
	//ma è meglio usare push.back
	
	for (int i=0; i<N; ++i)
	{
		cout << "\nInserisci il " << i+1 << "^ elemento: ";
		int val=0;
		cin>>val;
		v.push_back(val);
	}
	
};

void readVectorAlt (vector <int> &v)
{
	string s;
	int i=1;
	
	while (true)
	{
		cout << "\nInserisci il " << i << "^ elemento, o termina (y): ";
		
		cin >> s;
		
		if (s=="y"){
			break;}
			
		v.push_back(stoi(s));
		++i;
	}
// uso queste "", altrimenti sarebbe un char

};

void printVector (vector<int> &v)
{
	
	for (unsigned int i=0; i <v.size(); ++i)
	{
		cout << v[i];
		if (i<v.size()-1)
			cout <<", ";
		else 
			cout << " ";
	}
	
	cout << endl;
};