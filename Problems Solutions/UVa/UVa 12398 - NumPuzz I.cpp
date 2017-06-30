#include <iostream>
#include <sstream>
using namespace std;
int arr[5][5] = { {} };

int inc(int x, int y){

	if (arr[x][y] == 9)
		arr[x][y] = 0;
	else
		arr[x][y]++;

	if (arr[x + 1][y] == 9)
		arr[x + 1][y] = 0;
	else
		arr[x + 1][y]++;

	if (arr[x - 1][y] == 9)
		arr[x - 1][y] = 0;
	else
		arr[x - 1][y]++;

	if (arr[x][y + 1] == 9)
		arr[x][y + 1] = 0;
	else
		arr[x][y + 1]++;

	if (arr[x][y - 1] == 9)
		arr[x][y - 1] = 0;
	else
		arr[x][y - 1]++;

	return 0;
}

int main(){
	string cm;
	int casenum = 1;

	while (getline(cin, cm)){

		for (int s = 1; s <= 5; s++){
			for (int d = 1; d <= 5; d++){
				arr[s][d] = 0;
			}
		}

		for (unsigned int e = 0; e < cm.length(); e++){
			if (cm[e] == 'a')
				inc(1, 1);
			else if (cm[e] == 'b')
				inc(1, 2);
			else if (cm[e] == 'c')
				inc(1, 3);
			else if (cm[e] == 'd')
				inc(2, 1);
			else if (cm[e] == 'e')
				inc(2, 2);
			else if (cm[e] == 'f')
				inc(2, 3);
			else if (cm[e] == 'g')
				inc(3, 1);
			else if (cm[e] == 'h')
				inc(3, 2);
			else if (cm[e] == 'i')
				inc(3, 3);
		}

		cout << "Case #" << casenum << ":" << endl;
		for (int s = 1; s <= 3; s++){
			for (int d = 1; d <= 3; d++){
				if (d - 1)
					cout << " ";
				cout << arr[s][d];
			}
			cout << endl;
		}

		casenum++;
	}

	return 0;
}