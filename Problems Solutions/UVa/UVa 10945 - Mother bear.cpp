#include <iostream>
#include <sstream>
using namespace std;

string line, word, newline;
bool flag;

int doit(){

	newline = "";
	istringstream iss(line);
	while (iss) {
		word = "";
		iss >> word;
		for (int i = 0; i < word.length(); i++)
			if ((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z'))
				newline.push_back(tolower(word[i]));
	}

	flag = true;
	for (int i = 0; i < newline.length() / 2; i++){
		if (newline[i] != newline[newline.length() - 1 - i])
			flag = false;
	}

	return 0;
}

int main(){

	while (getline(cin, line) && line != "DONE"){
		doit();
		if (flag)
			cout << "You won't be eaten!" << endl;
		else
			cout << "Uh oh.." << endl;
	}

	return 0;
}