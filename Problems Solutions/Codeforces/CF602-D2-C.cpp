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

int n, m;
bool rail[400][400];
vector<int> vec[2][400];

int solve(int first, int second) {
	int vis[2][400];
	memset(vis, -1, sizeof(vis));
	int arr[] = { first, second };
	for (int it = 0; it < 2; it++) {
		queue<pair<int, int>> qu;
		qu.push({ 0, 0 });
		while (!qu.empty()) {
			pair<int, int> fr = qu.front();
			qu.pop();
			int id = arr[it];
			if (vis[id][fr.first] != -1 || (it == second && vis[first][fr.first] == fr.second))
				continue;
			vis[id][fr.first] = fr.second;
			for (int i = 0; i < vec[id][fr.first].size(); i++)
				qu.push({ vec[id][fr.first][i], fr.second + 1 });
		}
	}
	return vis[0][n - 1] == -1 || vis[1][n - 1] == -1 ? 1 << 30 : max(vis[0][n - 1], vis[1][n - 1]);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		rail[a][b] = rail[b][a] = 1;
		vec[0][a].push_back(b);
		vec[0][b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		for (int e = i + 1; e < n; e++)
			if (!rail[i][e]) {
				vec[1][i].push_back(e);
				vec[1][e].push_back(i);
			}
	int ans = min(solve(0, 1), solve(1, 0));
	cout << (ans == 1 << 30 ? -1 : ans) << '\n';
	return 0;
}
