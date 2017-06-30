#include <iostream>
#include <sstream>
using namespace std;

int t, counter, fcounter;
string word, subword;

int count(){
	counter = 0;
	fcounter = 0;

	for (int i = 0; i < word.length(); i+=subword.length()){
		counter = 0;
		for (int e = 0; e < subword.length(); e++){
			if (i + e >= word.length())
				break;
			if (word[i + e] == subword[e])
				counter++;
		}
		if (counter == subword.length())
			fcounter++;
	}

	return fcounter;
}

int getword(){
	subword = "";
	subword.push_back(word[0]);

	for (int i = 1; i < word.length(); i++){
		if (word.length() == subword.length()*count())
			break;
		subword.push_back(word[i]);
	}

	return 0;
}

int main(){

	cin >> t;
	while (t--){
		cin >> word;
		getword();
		cout << subword.length() << endl;
		if (t)
			cout << endl;
	}

	return 0;
}