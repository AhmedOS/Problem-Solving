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

int n, m, ara[100000], arb[100000];

long long cost(int nm) {
	long long ret = 0;
	for (int i = 0; i < n; i++)
		if (ara[i] < nm)
			ret += nm - ara[i];
	for (int i = 0; i < m; i++)
		if (arb[i] > nm)
			ret += arb[i] - nm;
	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> ara[i];
	for (int i = 0; i < m; i++)
		cin >> arb[i];
	long long s = 1, e = 1000000000;
	while (e - s > 3) {
		long long lft = (s * 2 + e) / 3, rit = (s + e * 2) / 3;
		if (cost(rit) > cost(lft))
			e = rit;
		else
			s = lft;
	}
	long long ans = 1LL << 62;
	for (int i = s; i <= e; i++)
		ans = min(ans, cost(i));
	cout << ans << '\n';
	return 0;
}
