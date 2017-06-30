#include <iostream>
#include <sstream>
using namespace std;

int pos = 0, ge, st = 0;
string dir[100];

int ext(string lne){
	int casenum;
	stringstream ss;
	string temp;

	ss << lne;
	while (getline(ss, temp, ' ')) {
		if (stringstream(temp) >> casenum){
			if (casenum > 0 && casenum < ge){
				if (dir[casenum - 1] == "RIGHT")
				{
					pos = pos + 1;
					dir[ge - 2] = "RIGHT";
				}
				else if (dir[casenum - 1] == "LEFT")
				{
					pos = pos - 1;
					dir[ge - 2] = "LEFT";
				}
			}
		}
	}
		return 0;
}


int main(){
	int t, n;
	string cm;
	cin >> t;
	if (t <= 100){
		for (int i = 0; i < t; i++){
			pos = 0;
			st = 0;
			cin >> n;
			if ((n >= 1) && (n <= 100)){
				for (ge = 1; ge <= (n+1); ge++){
					getline(cin, cm);
					if (st == 0)
						goto start;
					if (cm == "RIGHT")
					{
						pos = pos + 1;
						dir[ge - 2] = "RIGHT";
					}
					else if (cm == "LEFT")
					{
						pos = pos - 1;
						dir[ge - 2] = "LEFT";
					}
					else if (cm.find("SAME AS") != string::npos)
						ext(cm);
					start :
					st++;
				}
				cout << pos << endl;
			}
		}
	}


}