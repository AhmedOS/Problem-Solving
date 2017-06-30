#include <iostream>
#include <cmath>
using namespace std;

int main(){

	int n, arr[11][11], sum[6], casenum = 0;

	while (cin >> n && n){

		casenum++;

		for (int s = 1; s <= round(n / 2.0); s++){
			sum[s] = 0;
		}

		for (int s = 1; s <= n; s++){
			for (int d = 1; d <= n; d++){
				cin >> arr[s][d];
				for (int i = 0; i < n; i++){
					if (s == i + 1 || d == i + 1 || s == n - i || d == n - i){
						sum[i + 1] = sum[i + 1] + arr[s][d];
						break;
					}
				}
			}
		}


		cout << "Case " << casenum << ":";
		for (int i = 1; i <= round(n / 2.0); i++){
			cout << " " << sum[i];
		}
		cout << endl;

	}
	return 0;
}