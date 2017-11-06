/*
	Solution idea:
		- Assume that nodes with the same value are connected together, so we add edges values to the answer.
		- Next, iterate for each possible divisor and try to connect its multiples if they aren't already connected.
		- Iterating over divisors descendingly guarantees connecting numbers with its GCD.
*/
#include <bits/stdc++.h>
using namespace std;

int t, n, arr[100001];
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

void DSU() {
	rnk.clear();
	rnk.resize(100001);
	parent.clear();
	parent.resize(100001);
	trees = 100000;
	for (int i = 1; i <= 100000; i++) {
		rnk[i] = 1;
		parent[i] = i;
	}
}

int main() {
	//freopen("dream.in", "rt", stdin);
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		memset(arr, 0, sizeof(arr));
		DSU();
		cin >> n;
		for (int i = 0; i < n; i++) {
			int nm;
			cin >> nm;
			arr[nm]++;
		}
		long long ans = 0;
		for (int i = 1; i <= 100000; i++)
			if (arr[i])
				ans += (long long)i * (arr[i] - 1);
		for (int i = 100000; i >= 1; i--) {
			int fr = -1;
			for (int e = i; e <= 100000; e += i) {
				if (arr[e]) {
					if (fr == -1)
						fr = e;
					else if (getParent(fr) != getParent(e)) {
						connect(fr, e);
						ans += i;
					}
				}
			}
		}
		cout << "Case " << tt << ": " << ans << '\n';
	}
	return 0;
}
