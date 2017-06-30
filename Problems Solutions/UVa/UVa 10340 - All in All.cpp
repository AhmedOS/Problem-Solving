#include <iostream>
#include <sstream>
using namespace std;

string s, t, st;
bool flag = true;

int doit(){

	st.clear();
	int i = 0;
	for (int e = 0; e < t.length(); e++){
		if (s[i] == t[e]){
			st.push_back(s[i]);
			i++;
			if (i >= s.length())
				break;
		}
	}

	flag = true;

	if (s != st){
		flag = false;
		return 0;
	}

	return 0;
}

int main(){

	while (cin >> s >> t){
		doit();
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}