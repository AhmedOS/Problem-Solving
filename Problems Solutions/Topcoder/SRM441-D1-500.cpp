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

class StrangeCountry {
	vector<int> rnk, parent;
	int trees, n;

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
		rnk.resize(n);
		parent.resize(n);
		trees = n;
		for (int i = 0; i < n; i++) {
			rnk[i] = 1;
			parent[i] = i;
		}
	}

public:
	int transform(vector<string> g) {
		n = g.size();
		DSU();
		int eed[50];
		memset(eed, 0, sizeof(eed));
		for (int i = 0; i < n; i++)
			for (int e = 0; e < n; e++)
				if (g[i][e] == 'Y' && !connect(i, e) && i < e)
					eed[i]++;
		set<pair<int, int>> st;
		for (int i = 0; i < n; i++) {
			int p = getParent(i);
			if (p != i) {
				eed[p] += eed[i];
				eed[i] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			int p = getParent(i);
			st.insert(make_pair(eed[p], p));
		}
		int ans = 0;
		while (st.size() > 1) {
			set<pair<int, int>>::iterator it = st.end();
			it--;
			pair<int, int> p1 = *it;
			it--;
			pair<int, int> p2 = *it;
			if (!p1.first || rnk[p2.second] == 1)
				return -1;
			connect(p1.second, p2.second);
			int par = getParent(p1.second);
			eed[p1.second] = eed[p2.second] = 0;
			eed[par] = p1.first + p2.first - 1;
			st.erase(it);
			it = st.end();
			it--;
			st.erase(it);
			st.insert(make_pair(eed[par], par));
			ans++;
		}
		return ans;
	}
};
