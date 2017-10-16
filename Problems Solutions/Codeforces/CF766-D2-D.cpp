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

int n, m, q, opp[100000];
map<string, int> idx;

vector<int> rnk, parent;
int trees;

int getParent(int node) {
	if (parent[node] == node)
		return node;
	return parent[node] = getParent(parent[node]);
}

bool connect(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a != b) {
		if (rnk[b] < rnk[a])
			swap(a, b);
		parent[a] = b;
		if (rnk[a] == rnk[b])
			rnk[b]++;
		trees--;
	}
	return a != b;
}

void DSU(int N) {
	rnk.resize(N);
	parent.resize(N);
	trees = N;
	for (int i = 0; i < N; i++) {
		rnk[i] = 1;
		parent[i] = i;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	memset(opp, -1, sizeof(opp));
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		idx[str] = i;
	}
	DSU(n);
	for (int i = 0; i < m; i++) {
		int nm, id1, id2;
		string a, b;
		cin >> nm >> a >> b;
		id1 = idx[a];
		id2 = idx[b];
		int g1 = getParent(id1), g2 = getParent(id2);
		if (opp[g1] != -1)
			opp[g1] = getParent(opp[g1]);
		if (opp[g2] != -1)
			opp[g2] = getParent(opp[g2]);
		if (opp[g1] == opp[g2] && opp[g1] != -1) {
			connect(g1, g2);
			g1 = getParent(id1);
			g2 = getParent(id2);
		}
		if (nm == 1) {
			if (opp[g1] != g2) {
				if (opp[g1] != -1 && opp[g2] == -1)
					opp[g2] = opp[g1];
				else if (opp[g1] == -1 && opp[g2] != -1)
					opp[g1] = opp[g2];
				else if (opp[g1] != -1 && opp[g2] != -1) {
					connect(opp[g1], opp[g2]);
					opp[g1] = opp[g2] = getParent(opp[g1]);
				}
				connect(id1, id2);
				cout << "YES\n";
			}
			else
				cout << "NO\n";
		}
		else if (nm == 2) {
			if (g1 != g2) {
				if (opp[g1] == -1 && opp[g2] == -1) {
					opp[g1] = g2;
					opp[g2] = g1;
				}
				else if (opp[g1] == -1) {
					connect(id1, opp[g2]);
					int par = getParent(id1);
					opp[par] = g2;
					opp[g2] = par;
				}
				else if (opp[g2] == -1) {
					connect(id2, opp[g1]);
					int par = getParent(id2);
					opp[par] = g1;
					opp[g1] = par;
				}
				else {
					connect(id1, opp[g2]);
					opp[getParent(id2)] = getParent(id1);
					connect(id2, opp[g1]);
					opp[getParent(id1)] = getParent(id2);
				}
				cout << "YES\n";
			}
			else
				cout << "NO\n";
		}
	}
	while (q--) {
		string a, b;
		cin >> a >> b;
		int id1 = idx[a];
		int id2 = idx[b];
		int g1 = getParent(id1), g2 = getParent(id2);
		if (opp[g1] != -1)
			opp[g1] = getParent(opp[g1]);
		if (opp[g2] != -1)
			opp[g2] = getParent(opp[g2]);
		if (opp[g1] == opp[g2] && opp[g1] != -1) {
			connect(g1, g2);
			g1 = getParent(id1);
			g2 = getParent(id2);
		}
		if (g1 == g2)
			cout << "1\n";
		else if (opp[g1] == g2)
			cout << "2\n";
		else
			cout << "3\n";
	}
	return 0;
}
