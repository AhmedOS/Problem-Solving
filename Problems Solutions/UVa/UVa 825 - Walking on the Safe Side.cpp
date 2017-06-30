#pragma warning (disable : 4996 4018)

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
#include <string.h>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

const int MAX = 1000 + 9;
const double PI = atan(1) * 4;
int t, w, n;
int arr[109][109];

long long solve() {
	arr[1][1] = 1;
	for (int i = 1; i <= w; i++)
		for (int e = 1; e <= n; e++)
			if (arr[i][e] == -1)
				arr[i][e] = (i > 1 ? arr[i - 1][e] : 0) + (e > 1 ? arr[i][e - 1] : 0);
	return arr[w][n];
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	//const clock_t beg = clock();

	cin >> t;
	string str;
	while (t--) {
		memset(arr, -1, sizeof(arr));
		cin >> w >> n;
		cin.ignore();
		for (int i = 1; i <= w; i++) {
			getline(cin, str);
			stringstream ss(str);
			int co;
			ss >> co;
			while (ss >> co)
				arr[i][co] = 0;
		}
		cout << solve() << '\n';
		if (t)
			cout << '\n';
	}
	
	//cout << double(clock() - beg) / CLOCKS_PER_SEC << '\n';
	return 0;
}