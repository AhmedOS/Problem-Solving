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

int n, m, all, it;
char arr[52][52];
int dirr[] = { 1, -1, 0, 0 };
int dirc[] = { 0, 0, 1, -1 };
int vis[52][52];

int dfs(int r, int c) {
	if (arr[r][c] != '#' || vis[r][c] == it)
		return 0;
	vis[r][c] = it;
	int ret = 1;
	for (int i = 0; i < 4; i++)
		ret += dfs(r + dirr[i], c + dirc[i]);
	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int e = 1; e <= m; e++) {
			cin >> arr[i][e];
			all += arr[i][e] == '#';
		}
	if (all < 3) {
		cout << "-1\n";
		return 0;
	}
	int ans = 2;
	for (int i = 1; i <= n; i++)
		for (int e = 1; e <= m; e++)
			if (arr[i][e] == '#') {
				it++;
				arr[i][e] = '.';
				int c = 1 << 30;
				for (int i = 1; i <= n; i++)
					for (int e = 1; e <= m; e++)
						if (arr[i][e] == '#') {
							c = dfs(i, e);
							goto en;
						}
			en:
				arr[i][e] = '#';
				if (c < all - 1)
					ans = 1;
			}
	cout << ans << '\n';
	return 0;
}
