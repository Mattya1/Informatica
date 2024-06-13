#include <fstream>

//lettura stringa da file
	
	ifstream infile;
	infile.open ("fileDaLeggere.txt");
	
	string data;
	infile >> data;

	int num = stoi (data); //stoi = string to integer
	
	infile.close();
	
//scrittura di var su file
	ofstream outfile;
	outfile.open ("fileDaScrivere.txt");
	outfile << var
	
	outfile.close();