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

int t, sopf[500001], pp[500001];

int pfactsum(int nm) {
	int ret = 0;
	while (nm % 2 == 0) {
		ret += 2;
		nm = nm / 2;
	}
	int sq = sqrt(nm);
	for (int i = 3; i <= sq; i += 2) {
		while (nm % i == 0) {
			ret += i;
			nm = nm / i;
		}
	}
	if (nm > 2)
		ret += nm;
	return ret;
}

int solve(int nxt) {
	int ret = 1;
	while (nxt != sopf[nxt] && !pp[nxt]) {
		nxt = sopf[nxt];
		ret++;
	}
	if (nxt != sopf[nxt])
		ret += pp[sopf[nxt]];
	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	for (int i = 2; i <= 500000; i++)
		sopf[i] = pfactsum(i);
	for (int i = 2; i <= 500000; i++)
		pp[i] = solve(i);
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		int a, b;
		cin >> a >> b;
		int s = min(a, b), e = max(a, b), ans = 0;
		for (int i = s; i <= e; i++)
			ans = max(ans, pp[i]);
		cout << "Case #" << tt << ":\n" << ans << '\n';
	}
	return 0;
}
