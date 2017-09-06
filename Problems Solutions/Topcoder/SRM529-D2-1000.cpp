#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <bitset>
#include <limits>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

class MinskyMysteryDiv2 {
public:
	long long div(long long nm) {
		long long sq = sqrt(nm);
		for (int i = 2; i <= sq; i++)
			if (nm % i == 0)
				return i;
		return nm;
	}
	long long computeAnswer(long long N) {
		if (!N || N == 1)
			return -1;
		long long nm = div(N);
		return N / nm + nm;
	}
};

//Simulation
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int arr[] = { 2, 3, 4, 15, 14, 21, 23, 13 };
	for (int i = 0; i < 8; i++) {
		vector<int> bag(5);
		bool ok = 1;
		bag[0] = arr[i];
		bag[1]++;
		while (ok) {
			bag[1]++;
			bag[4] = 0;
			while (bag[0]) {
				for (int i = 0; i < 5; i++)
					cout << bag[i] << ' ';
				cout << '\n';
				int mn = min(bag[0], bag[1]);
				bag[0] -= mn;
				bag[1] -= mn;
				bag[2] += mn;
				bag[3] += mn;
				bag[4]++;
				if (!bag[0] && !bag[1]) {
					bag[4] += bag[3];
					ok = 0;
					break;
				}
				bag[1] += bag[3];
				bag[3] = 0;
			}
			bag[0] += bag[2];
			bag[2] = 0;
			cout << '\n';
		}
		MinskyMysteryDiv2 mm;
		cout << bag[4] << " : " << mm.computeAnswer(arr[i]) << '\n';
		cout << "==========\n\n";
	}
	return 0;
}
