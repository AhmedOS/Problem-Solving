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

int n, arr[200001], c;
vector<int> vec[200001];
int vis[200001], sz[200001], chk[200001], val, itr[200001], it;
vector<int> comp[200001];
long long mod = 1000000007;

int dfs(int nxt) {
	if (vis[nxt] != -1)
		return 0;
	comp[c].push_back(nxt);
	int ret = 1;
	vis[nxt] = c;
	for (int i = 0; i < vec[nxt].size(); i++)
		ret += dfs(vec[nxt][i]);
	return ret;
}

bool dfs2(int nxt, int co) {
	if (!nxt)
		return 0;
	if (chk[nxt]) {
		if (itr[nxt] == it) {
			val = co - chk[nxt];
			return 1;
		}
		return 0;
	}
	itr[nxt] = it;
	chk[nxt] = co;
	return dfs2(arr[nxt], co + 1);
}

long long power(long long nm, int pw) {
	if (!pw)
		return 1;
	long long rs = power(nm, pw / 2);
	return (((rs%mod) * (rs%mod) % mod) % mod * (pw & 1 ? nm : 1) % mod) % mod;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	memset(vis, -1, sizeof(vis));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		vec[i].push_back(arr[i]);
		vec[arr[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == -1) {
			sz[c] = dfs(i);
			c++;
		}
	}
	long long ans = 1;
	for (int i = 0; i < c; i++) {
		int cz = 0;
		for (int e = 0; e < comp[i].size(); e++) {
			it++;
			if (!chk[comp[i][e]] && dfs2(comp[i][e], 1))
				cz = val;
		}
		ans = ((ans%mod) * ((((power(2, cz) - 2)%mod) * (power(2, sz[i] - cz)%mod)) % mod)) % mod;
	}
	cout << ans << '\n';
	return 0;
}
