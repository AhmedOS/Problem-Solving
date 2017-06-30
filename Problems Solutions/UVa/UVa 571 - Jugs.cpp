#pragma warning (disable : 4996)

#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1001;
int ac, bc, tr;

vector<string> ans;
bool stt[MAX][MAX];

bool vis[MAX][MAX];
vector<string> ans2;
pair<pair<int, int>, string> par[MAX][MAX];


bool dfs(int a, int b) {
	if (stt[a][b])
		return 0;
	stt[a][b] = 1;
	if (b == tr) {
		ans.push_back("success");
		return 1;
	}
	if (dfs(ac, b)) {
		ans.push_back("fill A");
		return 1;
	}
	if (dfs(a, bc)) {
		ans.push_back("fill B");
		return 1;
	}
	if (dfs(0, b)) {
		ans.push_back("empty A");
		return 1;
	}
	if (dfs(a, 0)) {
		ans.push_back("empty B");
		return 1;
	}
	int nb = b + min(bc - b, a);
	int na = a - min(bc - b, a);
	if (dfs(na, nb)) {
		ans.push_back("pour A B");
		return 1;
	}
	na = a + min(ac - a, b);
	nb = b - min(ac - a, b);
	if (dfs(na, nb)) {
		ans.push_back("pour B A");
		return 1;
	}
	return 0;
}

void genpath(pair<pair<int, int>, string> st) {
	while (st.first.first != -1 || st.first.second != -1) {
		ans2.push_back(st.second);
		st = par[st.first.first][st.first.second];
	}
}

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	par[0][0] = { { -1, -1 }, "" };
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		if (cur.second == tr) {
			genpath({ cur, "success" });
			break;
		}
		vis[cur.first][cur.second] = 1;
		if (!vis[ac][cur.second]) {
			q.push({ ac, cur.second });
			par[ac][cur.second] = { cur, "fill A" };
		}
		if (!vis[cur.first][bc]) {
			q.push({ cur.first, bc });
			par[cur.first][bc] = { cur, "fill B" };
		}
		if (!vis[0][cur.second]) {
			q.push({ 0, cur.second });
			par[0][cur.second] = { cur, "empty A" };
		}
		if (!vis[cur.first][0]) {
			q.push({ cur.first, 0 });
			par[cur.first][0] = { cur, "empty B" };
		}
		int nb = cur.second + min(bc - cur.second, cur.first);
		int na = cur.first - min(bc - cur.second, cur.first);
		if (!vis[na][nb]) {
			q.push({ na, nb });
			par[na][nb] = { cur, "pour A B" };
		}
		na = cur.first + min(ac - cur.first, cur.second);
		nb = cur.second - min(ac - cur.first, cur.second);
		if (!vis[na][nb]) {
			q.push({ na, nb });
			par[na][nb] = { cur, "pour B A" };
		}
	}
}

int main() {
	
	while (cin >> ac >> bc >> tr) {
		/*
		dfs(0, 0);
		for (int i = ans.size() - 1; i >= 0; i--)
			cout << ans[i] << '\n';
		cout << "================\n";
		*/
		bfs();
		for (int i = ans2.size() - 1; i >= 0; i--)
			cout << ans2[i] << '\n';
		memset(vis, 0, sizeof(vis));
		ans2.clear();
	}

	return 0;
}