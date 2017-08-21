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

int n, m, sr, sc, er, ec;
char arr[1000][1000];
int enm[1000][1000];
int vis[1000][1000];

bool valid(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m && arr[r][c] != 'T';
}

int dirr[] = { 0, 0, 1, -1 };
int dirc[] = { 1, -1, 0, 0 };
void solve() {
	memset(vis, -1, sizeof(vis));
	queue<pair<pair<int, int>, int>> qu;
	qu.push({ { er, ec }, 0 });
	while (!qu.empty()) {
		pair<pair<int, int>, int> fr = qu.front();
		qu.pop();
		if (!valid(fr.first.first, fr.first.second) || vis[fr.first.first][fr.first.second] != -1)
			continue;
		vis[fr.first.first][fr.first.second] = fr.second;
		for (int i = 0; i < 4; i++)
			qu.push({ {fr.first.first + dirr[i], fr.first.second + dirc[i]}, fr.second + 1 });
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int e = 0; e < m; e++) {
			cin >> arr[i][e];
			if (arr[i][e] == 'S') {
				sr = i;
				sc = e;
			}
			else if (arr[i][e] == 'E') {
				er = i;
				ec = e;
			}
			else if (arr[i][e] >= '0' && arr[i][e] <= '9')
				enm[i][e] = arr[i][e] - '0';
			if (arr[i][e] != 'T')
				arr[i][e] = '0';
		}
	solve();
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int e = 0; e < m; e++)
			if (enm[i][e] && vis[i][e] != -1 && vis[sr][sc] >= vis[i][e])
				ans += enm[i][e];
	cout << ans << '\n';
	return 0;
}
