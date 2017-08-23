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

int t, n, et, dis[1000], vis[1000][2];
vector<int> vec[1000];

bool dfs(int nxt, bool pass, int guard) {
	if (!nxt)
		return pass;
	if (vis[nxt][pass] == guard + 1)
		return 1;
	vis[nxt][pass] = guard + 1;
	pass |= nxt == guard;
	bool ret = 1;
	for (int i = 0; i < vec[nxt].size(); i++)
		ret &= dfs(vec[nxt][i], pass, guard);
	return ret;
}

void bfs() {
	queue<pair<int, int>> qu;
	qu.push({ et, 0 });
	while (!qu.empty()) {
		pair<int, int> fr = qu.front();
		qu.pop();
		if (dis[fr.first] != -1)
			continue;
		dis[fr.first] = fr.second;
		for (int i = 0; i < vec[fr.first].size(); i++)
			qu.push({ vec[fr.first][i], fr.second + 1 });
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		memset(dis, -1, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++)
			vec[i].clear();
		cin >> n >> et;
		cin.ignore();
		string s;
		while (getline(cin, s) && s.size()) {
			stringstream ss;
			ss << s;
			int a, b;
			ss >> a;
			ss >> b;
			vec[b].push_back(a);
		}
		bfs();
		int ans = 0, bst = 1 << 30;
		for (int i = 0; i < n; i++)
			if (i != et && dis[i] < bst && dfs(et, 0, i)) {
				bst = dis[i];
				ans = i;
			}
		cout << "Put guards in room " << ans << ".\n";
		if (t)
			cout << '\n';
	}
	return 0;
}
