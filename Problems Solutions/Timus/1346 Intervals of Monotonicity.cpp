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

int s, e, n, arr[100001], dp[100001][2];

int solve(int nxt, bool inc) {
	if (nxt == n - 1)
		return 1;
	if (dp[nxt][inc] != -1)
		return dp[nxt][inc];
	int ret = 1 << 30;
	if ((inc && arr[nxt] <= arr[nxt + 1]) || (!inc && arr[nxt] >= arr[nxt + 1]))
		ret = solve(nxt + 1, inc);
	ret = min({ ret, 1 + solve(nxt + 1, inc), 1 + solve(nxt + 1, !inc) });
	return dp[nxt][inc] = ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> s >> e;
	n = e - s + 1;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	memset(dp, -1, sizeof(dp));
	cout << min(solve(0, 0), solve(0, 1)) << '\n';
	return 0;
}
