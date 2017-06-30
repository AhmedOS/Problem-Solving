#include <iostream>
#include <sstream>
using namespace std;

int t, arrnum[10000];
string line, newline, let;

int ext(){
	stringstream ss;
	string temp;
	int num;

	int i = 0;
	ss << line;
	while (getline(ss, temp, ' ')) {
		if (stringstream(temp) >> num){
			arrnum[i] = num;
			i++;
		}
	}

	return 0;
}

int doit(){

	let.clear();
	newline.clear();

	for (int i = 0; i < line.length(); i++){
		if (line[i] >= 'A' && line[i] <= 'Z')
			let.push_back(line[i]);
	}

	for (int i = 0; i < line.length(); i++){
		if (line[i] >= 'A' && line[i] <= 'Z')
			line[i] = ' ';
	}

	ext();

	for (int i = 0; i < let.length(); i++)
		newline.append(string(arrnum[i], let[i]));

	return 0;
}

int main(){

	cin >> t;
	int i = 1;
	while (t--){
		cin >> line;
		doit();
		cout << "Case " << i << ": " << newline << endl;
		i++;
	}

	return 0;
}