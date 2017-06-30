#include <iostream>
using namespace std;

int main(){

	int n, arr[101][101], sum = 0, corr = 0, corr2 = 0, xy[2];

	while (cin >> n && n){

		int s, d;
		sum = 0;
		corr = 0;
		corr2 = 0;

		for (s = 1; s <= n; s++){

			for (d = 1; d <= n; d++){
				cin >> arr[s][d];
				sum = sum + arr[s][d];
			}
			
			if (sum % 2)
			{
				corr++;
				xy[0] = s;
			}

			sum = 0;

		}

		sum = 0;

		for (s = 1; s <= n; s++){

			for (d = 1; d <= n; d++){
				sum = sum + arr[d][s];
			}

			if (sum % 2){
				corr2++;
				xy[1] = s;
			}

			sum = 0;

		}

		if (corr == 0 && corr2 == 0)
			cout << "OK" << endl;
		else if (corr == 1 && corr2 == 1)
			cout << "Change bit (" << xy[0] << "," << xy[1] << ")" << endl;
		else
			cout << "Corrupt" << endl;

	}
	return 0;
}