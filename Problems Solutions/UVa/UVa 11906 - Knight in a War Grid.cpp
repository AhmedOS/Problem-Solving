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

int ro, co, n, m, t, arr[100][100], wat[100][100], w, vis[100][100];

bool ok(int r, int c) {
	return r >= 0 && r < ro && c >= 0 && c < co && !wat[r][c];
}

int dr[] = { 1, 1, -1, -1 };
int dc[] = { 1, -1, 1, -1 };

struct state {
	int r, c;
};
stack<state> rec;
void solve() {
	rec.push({ 0, 0 });
	while (!rec.empty()) {
		state st = rec.top();
		rec.pop();
		if (!ok(st.r, st.c) || vis[st.r][st.c])
			continue;
		vis[st.r][st.c] = 1;
		for (int i = 0; i < 4; i++) {
			rec.push({ st.r + n*dr[i], st.c + m*dc[i] });
			rec.push({ st.r + m*dr[i], st.c + n*dc[i] });
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	//freopen("out.txt", "wt", stdout);
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		memset(vis, 0, sizeof(vis));
		memset(wat, 0, sizeof(wat));
		memset(arr, 0, sizeof(arr));
		cin >> ro >> co >> n >> m >> w;
		for (int i = 0; i < w; i++) {
			int a, b;
			cin >> a >> b;
			wat[a][b] = 1;
		}
		for (int i = 0; i < ro; i++)
			for (int e = 0; e < co; e++) {
				set<pair<int, int>> st;
				for (int d = 0; d < 4 && !wat[i][e]; d++) {
					int nr = i + n*dr[d], nc = e + m*dc[d];
					if (ok(nr, nc))
						st.insert({ nr, nc });
					nr = i + m*dr[d], nc = e + n*dc[d];
					if (ok(nr, nc))
						st.insert({ nr, nc });
				}
				arr[i][e] += st.size();
			}
		solve();
		int even = 0, odd = 0;
		for (int i = 0; i < ro; i++)
			for (int e = 0; e < co; e++)
				(arr[i][e] & 1 ? odd : even) += vis[i][e];
		cout << "Case " << tt << ": " << even << ' ' << odd << '\n';
	}
	return 0;
}
