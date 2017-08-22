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

int n;
vector<pair<int, int>> vec[100000];
vector<long long> leaf;

void solve(int nxt, int par, long long cost) {
	bool f = 0;
	for (int i = 0; i < vec[nxt].size(); i++)
		if (vec[nxt][i].first != par) {
			f = 1;
			solve(vec[nxt][i].first, nxt, cost + vec[nxt][i].second);
		}
	if (!f)
		leaf.push_back(cost);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	long long ans = 0;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		vec[a].push_back({ b, c });
		vec[b].push_back({ a, c });
		ans += c * 2;
	}
	solve(0, -1, 0);
	long long mx = 0;
	for (int i = 0; i < leaf.size(); i++)
		mx = max(mx, leaf[i]);
	cout << ans - mx << '\n';
	return 0;
}
