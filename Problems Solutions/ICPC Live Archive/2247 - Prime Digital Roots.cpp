#pragma warning (disable : 4996 4018)

//#include <thread>
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

int n, dprime[1000000];
bool prime[1000000];

void sieve() {
	for (int i = 2; i < 1000000; i++)
		prime[i] = 1;
	for (int i = 2; i < 1000000; i++)
		if (prime[i])
			for (int e = i + i; e < 1000000; e += i)
				prime[e] = 0;
}

int solve(int nm) {
	while (11) {
		if (dprime[nm])
			return dprime[nm];
		if (prime[nm])
			return nm;
		if (nm <= 9)
			return 0;
		int nnm = 0;
		while (nm) {
			nnm += nm % 10;
			nm /= 10;
		}
		nm = nnm;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	sieve();
	for (int i = 2; i < 1000000; i++)
		dprime[i] = solve(i);
	while (cin >> n && n) {
		char arr[15];
		memset(arr, 0, sizeof(arr));
		if (dprime[n]) {
			int dp = dprime[n];
			for (int i = 14; dp; i--) {
				int r = dp % 10;
				dp /= 10;
				arr[i] = r + '0';
			}
		}
		else {
			arr[14] = 'e';
			arr[13] = 'n';
			arr[12] = 'o';
			arr[11] = 'n';
		}
		for (int i = 6; n; i--) {
			int r = n % 10;
			n /= 10;
			arr[i] = r + '0';
		}
		for (int i = 0; i < 15; i++)
			cout << (arr[i] ? arr[i] : ' ');
		cout << '\n';
	}
	return 0;
}
