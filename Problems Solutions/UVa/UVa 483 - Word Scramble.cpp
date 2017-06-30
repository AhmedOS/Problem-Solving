#include <iostream>
#include <sstream>
using namespace std;

string line, word;

int doit(){
	istringstream iss(line);

	while (iss) {
		word = "";
		iss >> word;
		for (int i = word.length() - 1; i >= 0; i--)
			cout << word[i];
		if (!iss.eof())
			cout << " "; 
	}

	return 0;
}

int main(){

	while (!cin.eof()){
		getline(cin, line);
		doit();
		if (!cin.eof())
			cout << endl;
	}

	return 0;
}