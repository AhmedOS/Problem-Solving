#include <iostream>
#include <sstream>
using namespace std;

int t, counter, counter2;
string word;

int thr(){
	counter = 0;

	if (word[0] != 't')
		counter++;
	if (word[1] != 'h')
		counter++;
	if (word[2] != 'r')
		counter++;
	if (word[3] != 'e')
		counter++;
	if (word[4] != 'e')
		counter++;

	if (counter < 2)
		cout << "3" << endl;

	return 0;
}

int onetwo(){
	counter = 0;
	counter2 = 0;

	if (word[0] != 'o')
		counter++;
	if (word[1] != 'n')
		counter++;
	if (word[2] != 'e')
		counter++;

	if (word[0] != 't')
		counter2++;
	if (word[1] != 'w')
		counter2++;
	if (word[2] != 'o')
		counter2++;

	if (counter < counter2 && counter < 2)
		cout << "1" << endl;
	else if (counter2 < counter && counter2 < 2)
		cout << "2" << endl;

	return 0;
}

int main(){

	cin >> t;
	for (int i = 1; i <= t; i++){
		cin >> word;
		if (word.length() == 3)
			onetwo();
		else if (word.length() == 5)
			thr();
	}

	return 0;
}