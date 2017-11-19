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

int n, k;
long long dp[2001][2001], mod = 1000000007;

long long solve(int prv, int co) {
	if (co == k)
		return 1;
	if (dp[prv][co] != -1)
		return dp[prv][co];
	long long ret = 0;
	for (int i = prv; i <= n; i += prv)
		ret = ((ret%mod) + (solve(i, co + 1)) % mod) % mod;
	return dp[prv][co] = ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans = ((ans%mod) + (solve(i, 1)) % mod) % mod;
	cout << ans << '\n';
	return 0;
}
