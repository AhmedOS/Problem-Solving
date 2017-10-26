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

int n, arr[100001], co[100001];
vector<pair<int, int>> vec[100001];

int count(int nxt, int par) {
	co[nxt] = 1;
	for (int i = 0; i < vec[nxt].size(); i++)
		if (vec[nxt][i].first != par)
			co[nxt] += count(vec[nxt][i].first, nxt);
	return co[nxt];
}

int solve(int nxt, int par, long long sofar) {
	if (sofar > arr[nxt])
		return co[nxt];
	sofar = max(sofar, 0LL);
	int ret = 0;
	for (int i = 0; i < vec[nxt].size(); i++)
		if (vec[nxt][i].first != par)
			ret += solve(vec[nxt][i].first, nxt, sofar + vec[nxt][i].second);
	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 2; i <= n; i++) {
		int a, c;
		cin >> a >> c;
		vec[a].push_back({ i, c });
		vec[i].push_back({ a, c });
	}
	count(1, 0);
	cout << solve(1, 0, 0) << '\n';
	return 0;
}
