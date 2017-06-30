#include <iostream>
#include <sstream>
using namespace std;

int n, s = 1, mat[11][11], ab[2];

int ext(string lne){
	stringstream ss;
	string temp;
	int num, i = 0;

	ss << lne;
	while (getline(ss, temp, ' ')) {
		if (stringstream(temp) >> num){
			ab[i] = num;
			i++;
		}
	}
	return 0;
}

int main(){
	int t, m, temp, trans[11][11];
	char matc[11][11];
	bool ok;
	string op;

	cin >> t;
	for (int i = 1; i <= t; i++){

		cin >> n;
		for (int s = 1; s <= n; s++){
			for (int d = 1; d <= n; d++){
				cin >> matc[s][d];
			}
		}

		for (int s = 1; s <= n; s++){
			for (int d = 1; d <= n; d++){
				mat[s][d] = matc[s][d] - '0';
			}
		}

		cin >> m;
		ok = false;
		for (int u = 1; u <= (m + 1); u++){
			getline(cin, op);
			if (!ok)
				goto start;
			ext(op);
			if (op.find("row") != string::npos){
				for (int k = 1; k <= n; k++){
					temp = mat[ab[0]][k];
					mat[ab[0]][k] = mat[ab[1]][k];
					mat[ab[1]][k] = temp;
				}
			}
			else if (op.find("col") != string::npos){
				for (int k = 1; k <= n; k++){
					temp = mat[k][ab[0]];
					mat[k][ab[0]] = mat[k][ab[1]];
					mat[k][ab[1]] = temp;
				}
			}
			else if (op.find("inc") != string::npos){
				for (int s = 1; s <= n; s++){
					for (int d = 1; d <= n; d++){
						mat[s][d]++;
						if (mat[s][d] == 10)
							mat[s][d] = 0;
					}
				}
			}
			else if (op.find("dec") != string::npos){
				for (int s = 1; s <= n; s++){
					for (int d = 1; d <= n; d++){
						mat[s][d]--;
						if (mat[s][d] == -1)
							mat[s][d] = 9;
					}
				}
			}
			else if (op.find("transpose") != string::npos){
				for (int s = 1; s <= n; s++){
					for (int d = 1; d <= n; d++){
						trans[d][s] = mat[s][d];
					}
				}
				for (int s = 1; s <= n; s++){
					for (int d = 1; d <= n; d++){
						mat[s][d] = trans[s][d];
					}
				}
			}

		start:
			ok = true;
		}

		cout << "Case #" << i << endl;
		for (int s = 1; s <= n; s++){
			for (int d = 1; d <= n; d++){
				cout << mat[s][d];
			}
			cout << endl;
		}

		cout << endl;

	}
	return 0;
}