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

int n, dp[100000], arr[100000], idx[100001];

vector<int> par[100001];
set<int> childs[100001];

int solve(int prv) {
	if (prv == n)
		return 0;
	if (dp[prv] != -1)
		return dp[prv];
	int ret = 0;
	for (int i = 0; i < par[arr[prv]].size(); i++) {
		auto it = childs[par[arr[prv]][i]].upper_bound(prv);
		if (it != childs[par[arr[prv]][i]].end())
			ret = max(ret, 1 + solve(*it));
	}
	return dp[prv] = ret;
}

void magic() {
	for (int i = 2; i <= 100000; i++)
		if (!par[i].size())
			for (int e = i; e <= 100000; e += i)
				if (idx[e] != -1) {
					par[e].push_back(i);
					childs[i].insert(idx[e]);
				}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	memset(idx, -1, sizeof(idx));
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		idx[arr[i]] = i;
	}
	magic();
	int ans = 1;
	for (int i = 0; i < n; i++)
		ans = max(ans, 1 + solve(i));
	cout << ans << '\n';
	return 0;
}
