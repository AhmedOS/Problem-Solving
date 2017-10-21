#pragma comment (linker, "/STACK:256000000")
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
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

long long n, k, p;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> k >> p;
	if ((n & 1) && k) {
		n--;
		k--;
	}
	while (p--) {
		long long nm;
		cin >> nm;
		if (nm > n) {
			cout << 'X';
			continue;
		}
		if (!k) {
			cout << '.';
			continue;
		}
		if (nm & 1) {
			if (k > n / 2) {
				long long rest = k - n / 2;
				long long nd = n / 2;
				long long val = nd - (nm / 2.0) + 1;
				if (val <= rest)
					cout << 'X';
				else
					cout << '.';
			}
			else
				cout << '.';
		}
		else {
			long long nd = n / 2;
			long long val = nd - (nm / 2) + 1;
			if (val <= k)
				cout << 'X';
			else
				cout << '.';
		}
	}
	return 0;
}
