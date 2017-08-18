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
char arr[500][500];
bool vis[500][500];

int dirr[] = { 1, -1, 0, 0 };
int dirc[] = { 0, 0, 1, -1 };
bool valid(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}
bool ok(int sr, int sc, int er, int ec) {
	memset(vis, 0, sizeof(vis));
	map<pair<int, int>, pair<int, int>> prv;
	queue<pair<int, int>> qu;
	qu.push({ sr, sc });
	bool flag = 0;
	while (!qu.empty()) {
		pair<int, int> fr = qu.front();
		qu.pop();
		if (fr.first == er && fr.second == ec && flag) {
			do {
				arr[fr.first][fr.second] = 'X';
				fr = prv[fr];
			} while (fr != make_pair(sr, sc));
			return 1;
		}
		flag = 1;
		for (int i = 0; i < 4; i++) {
			int nr = fr.first + dirr[i], nc = fr.second + dirc[i];
			if ((nr == er && nc == ec) || (valid(nr, nc) && arr[nr][nc] != 'X' && !vis[nr][nc])) {
				qu.push({ nr, nc });
				prv[{ nr, nc }] = fr;
				vis[nr][nc] = 1;
			}
		}
	}
	return 0;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int e = 0; e < m; e++)
			cin >> arr[i][e];
	cin >> sr >> sc >> er >> ec;
	sr--, sc--, er--, ec--;
	bool cracked = arr[er][ec] == 'X', reached = ok(sr, sc, er, ec);
	cout << (reached && (cracked || ok(er, ec, er, ec)) ? "YES" : "NO") << '\n';
	return 0;
}
