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

int t, n, m, arr[100];
map<int, bool> fib;

int co = 0;
long long dsum(int nm) {
	long long ret = co = 1;
	int sq = sqrt(nm);
	for (int i = 2; i <= sq; i++)
		if (nm % i == 0) {
			ret += i;
			co++;
			if (i != nm / i) {
				ret += nm / i;
				co++;
			}
		}
	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	fib[1] = fib[2] = arr[1] = arr[2] = 1;
	for (int i = 3; i < 47; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
		fib[arr[i]] = 1;
	}
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		cin >> n >> m;
		long long divs = dsum(n) % m;
		co = 0;
		dsum(divs);
		cout << "Case #" << tt << " : " << (fib[co] ? "YES" : "NO") << ".\n";
	}
	return 0;
}
