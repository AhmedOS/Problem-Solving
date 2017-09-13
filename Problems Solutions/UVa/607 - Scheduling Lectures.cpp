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

int t, n, len, cost, arr[1001], dp[1001][1001], dp2[1001][1001];

int calc(int nm) {
	if (!nm)
		return 0;
	if (nm >= 1 && nm <= 10)
		return -cost;
	return (nm - 10) * (nm - 10);
}

int solve(int nxt, int rem) {
	if (nxt == n)
		return 0;
	if (dp[nxt][rem] != -1)
		return dp[nxt][rem];
	int ret = 1 << 30;
	if (rem >= arr[nxt])
		ret = solve(nxt + 1, rem - arr[nxt]);
	return dp[nxt][rem] = min(ret, 1 + solve(nxt + 1, len - arr[nxt]));
}

int solve2(int nxt, int rem) {
	if (nxt == n)
		return calc(rem);
	if (dp2[nxt][rem] != -1)
		return dp2[nxt][rem];
	int ret = 1 << 30, opt = solve(nxt, rem), op1 = 1 << 30, op2 = 1 << 30;
	if (rem >= arr[nxt])
		op1 = solve(nxt + 1, rem - arr[nxt]);
	op2 = 1 + solve(nxt + 1, len - arr[nxt]);
	if (op1 == opt)
		ret = solve2(nxt + 1, rem - arr[nxt]);
	if (op2 == opt)
		ret = min(ret, calc(rem) + solve2(nxt + 1, len - arr[nxt]));
	return dp2[nxt][rem] = ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	while (cin >> n && n) {
		t++;
		memset(dp, -1, sizeof(dp));
		memset(dp2, -1, sizeof(dp2));
		cin >> len >> cost;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		if (t != 1)
			cout << '\n';
		cout << "Case " << t << ":\n";
		cout << "Minimum number of lectures: " << solve(0, 0) << '\n';
		cout << "Total dissatisfaction index: " << solve2(0, 0) << '\n';
	}
	return 0;
}
