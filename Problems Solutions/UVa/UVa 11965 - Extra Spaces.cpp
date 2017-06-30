#include <iostream>
#include <sstream>
using namespace std;

string line[51], word, newline[51];
int t, n;

int clear(){
	for (int i = 0; i < n; i++){
		line[i].clear();
		newline[i].clear();
	}
	return 0;
}

int doit(int pos){

	if (line[pos][0] == ' ')
		newline[pos].append(" ");

	istringstream iss(line[pos]);
	while (iss) {
		word = "";
		iss >> word;
		newline[pos].append(word);
		if (!iss.eof())
			newline[pos].append(" ");
	}

	return 0;
}

int main(){

	cin >> t;
	int tc = 1;
	while (t--){

		cin >> n;
		int i = 0;
		bool flag = false;
		while (getline(cin, line[i])){
			if (flag){
				doit(i);
				i++;
				if (i >= n)
					break;
			}
			flag = true;
		}

		cout << "Case " << tc << ":";
		for (int i = 0; i < n; i++){
			if (n - i)
				cout << endl;
			cout << newline[i];
		}
		cout << endl;
		if (t)
			cout << endl;
		tc++;
		clear();
	}

	return 0;
}