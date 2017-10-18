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

int n, m, k, q, toy[100001], co[100001];
vector<int> vec[100001];
bool nroot[100001];

const int logn = 17;
int par[100001][logn];
int h[100001];

void dfs(int v, int p = -1) {
	par[v][0] = p;
	if (p != -1)
		h[v] = h[p] + 1;
	for (int i = 1; i < logn; i++)
		if (par[v][i - 1] != -1)
			par[v][i] = par[par[v][i - 1]][i - 1];
	for (auto u : vec[v])
		if (u != p)
			dfs(u, v);
}

int LCA(int v, int u) {
	if (h[v] < h[u])
		swap(v, u);
	for (int i = logn - 1; i >= 0; i--)
		if (par[v][i] != -1 && h[par[v][i]] >= h[u])
			v = par[v][i];
	// now h[v] = h[u]
	if (v == u)
		return v;
	for (int i = logn - 1; i >= 0; i--)
		if (par[v][i] != par[u][i]) {
			v = par[v][i];
			u = par[u][i];
		}
	return par[v][0];
}

int count(int nxt) {
	co[nxt] = 1;
	for (int i = 0; i < vec[nxt].size(); i++)
		co[nxt] += count(vec[nxt][i]);
	return co[nxt];
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	memset(toy, -1, sizeof(toy));
	memset(par, -1, sizeof(par));
	cin >> n >> m >> k >> q;
	while (k--) {
		int a, b;
		cin >> a >> b;
		if (toy[b] != -1) {
			vec[toy[b]].push_back(a);
			nroot[a] = 1;
		}
		toy[b] = a;
	}
	for (int i = 1; i <= n; i++)
		if (!nroot[i]) {
			dfs(i);
			count(i);
		}
	while (q--) {
		int a, b;
		cin >> a >> b;
		if (toy[b] == -1)
			cout << "0\n";
		else {
			if (LCA(a, toy[b]) == a)
				cout << co[a] << '\n';
			else
				cout << "0\n";
		}
	}
	return 0;
}
