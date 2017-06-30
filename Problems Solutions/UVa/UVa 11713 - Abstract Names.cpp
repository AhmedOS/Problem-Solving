#include <iostream>
#include <sstream>
using namespace std;

string first, second, vo = "aoiue";
bool flag;

int doit(){

	bool ok1 = false, ok2 = false;
	flag = true;

	if (first.length() != second.length()){
		flag = false;
		return 0;
	}
		
	for (int i = 0; i < first.length(); i++){
		if (first[i] != second[i]){

			for (int e = 0; e < 5; e++){
				if (first[i] == vo[e]){
					ok1 = true;
					break;
				}
			}
			for (int e = 0; e < 5; e++){
				if (second[i] == vo[e]){
					ok2 = true;
					break;
				}
			}

			if (!ok1 || !ok2){
				flag = false;
				return 0;
			}

		}
	}

	return 0;
}

int main(){
	int t;

	cin >> t;
	while (t--){
		cin >> first;
		cin >> second;
		doit();
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}