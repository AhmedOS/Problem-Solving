#include <iostream>
#include <sstream>
using namespace std;

int t, num[30];
string line;

int doit(){

	for (int i = 0; i < line.length(); i++){
		if ((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z'))
			line[i] = tolower(line[i]);
	}

	for (int i = 0; i < line.length(); i++){
		if ((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z'))
			num[line[i] - 'a']++;
	}

	int max = num[0];
	for (int i = 1; i < 30; i++){
		if (num[i] > max)
			max = num[i];
	}

	for (int i = 0; i < 30; i++){
		if (num[i] == max){
			char chr = i + 'a';
			cout << chr;
		}
	}
	cout << endl;

	for (int i = 0; i < 30; i++){
		num[i] = 0;
	}

	return 0;
}

int main(){

	bool flag = false;
	cin >> t;
	t++;
	while (t--){
		getline(cin, line);
		if (flag)
		{
			if (line.empty())
				cout << endl;
			else
				doit();
		}
		flag = true;
	}

	return 0;
}