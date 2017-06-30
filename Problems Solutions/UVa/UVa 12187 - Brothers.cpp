#include <iostream>
using namespace std;

int n, r, c, k, battleb[110][110], battlea[110][110];

int clear(){

	for (int s = 1; s <= r; s++){
		for (int d = 1; d <= c; d++){
			battleb[s][d] = 0;
		}
	}

	for (int s = 1; s <= r; s++){
		for (int d = 1; d <= c; d++){
			battlea[s][d] = 0;
		}
	}

	return 0;
}

int GetSetOriginal(char option){

	if (option == 'g')
	{
		for (int s = 1; s <= r; s++){
			for (int d = 1; d <= c; d++){
				battlea[s][d] = battleb[s][d];
			}
		}
	}
	else if (option == 's')
	{
		for (int s = 1; s <= r; s++){
			for (int d = 1; d <= c; d++){
				battleb[s][d] = battlea[s][d];
			}
		}
	}

	return 0;
}

int fight(){

	for (int i = 1; i <= k; i++){
		for (int s = 1; s <= r; s++){
			for (int d = 1; d <= c; d++){
				if (battleb[s][d] + 1 == battleb[s + 1][d]){ battlea[s + 1][d] = battleb[s][d]; }
				if (battleb[s][d] + 1 == battleb[s - 1][d]){ battlea[s - 1][d] = battleb[s][d]; }
				if (battleb[s][d] + 1 == battleb[s][d + 1]){ battlea[s][d + 1] = battleb[s][d]; }
				if (battleb[s][d] + 1 == battleb[s][d - 1]){ battlea[s][d - 1] = battleb[s][d]; }

				if (battleb[s][d] == n - 1 && battleb[s + 1][d] == 0){ battlea[s + 1][d] = battleb[s][d]; }
				if (battleb[s][d] == n - 1 && battleb[s - 1][d] == 0){ battlea[s - 1][d] = battleb[s][d]; }
				if (battleb[s][d] == n - 1 && battleb[s][d + 1] == 0){ battlea[s][d + 1] = battleb[s][d]; }
				if (battleb[s][d] == n - 1 && battleb[s][d - 1] == 0){ battlea[s][d - 1] = battleb[s][d]; }
			}
		}
		GetSetOriginal('s');
	}

	return 0;
}

int main(){

	while (cin >> n >> r >> c >> k && n && r && c && k){

		for (int s = 1; s <= r; s++){
			for (int d = 1; d <= c; d++){
				cin >> battleb[s][d];
			}
		}

		GetSetOriginal('g');
		fight();

		for (int s = 1; s <= r; s++){
			for (int d = 1; d <= c; d++){
				if (d - 1)
					cout << " ";
				cout << battlea[s][d];
			}
			cout << endl;
		}

		clear();

	}

	return 0;
}