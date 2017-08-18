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

int t, n, k, r, c;
char arr[3][100];
bool vis[3][100][2];

bool valid(int r, int c) {
	return r >= 0 && r < 3 && c < n && arr[r][c] == '.';
}

bool solve() {
	queue<pair<pair<int, int>, int>> qu;
	qu.push({ { r, c }, 0 });
	memset(vis, 0, sizeof(vis));
	while (!qu.empty()) {
		pair<pair<int, int>, int> fr = qu.front();
		qu.pop();
		if (vis[fr.first.first][fr.first.second][fr.second])
			continue;
		if (fr.first.second == n - 1)
			return 1;
		vis[fr.first.first][fr.first.second][fr.second] = 1;
		if (!fr.second) {
			fr.second = 1;
			fr.first.second++;
			if (valid(fr.first.first, fr.first.second))
				qu.push(fr);
			else
				continue;
			fr.first.first++;
			if (valid(fr.first.first, fr.first.second))
				qu.push(fr);
			fr.first.first -= 2;
			if (valid(fr.first.first, fr.first.second))
				qu.push(fr);
		}
		else {
			fr.second = 0;
			fr.first.second += 2;
			if (valid(fr.first.first, fr.first.second))
				qu.push(fr);
			if (fr.first.second == n)
				return 1;
		}
	}
	return 0;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < 3; i++)
			for (int e = 0; e < n; e++) {
				cin >> arr[i][e];
				if (arr[i][e] == 's') {
					r = i;
					c = e;
					arr[i][e] = '.';
				}
			}
		cout << (solve() ? "YES" : "NO") << '\n';
	}
	return 0;
}
