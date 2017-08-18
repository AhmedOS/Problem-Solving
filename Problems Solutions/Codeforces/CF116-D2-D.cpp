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

int n, m, sum, app[151][2], am[151];
char arr[151][151];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	int lst = -1;
	for (int i = 0; i < n; i++) {
		bool f = 0;
		for (int e = 0; e < m; e++) {
			cin >> arr[i][e];
			if (arr[i][e] == 'W') {
				app[i][f] = e;
				f = 1;
				app[i][f] = e;
				sum++;
				am[i]++;
				lst = i;
			}
		}
	}
	int r = 0, c = 0, dir = 0, wed = 0, ans = 0;
	for (int i = 0; i <= lst; i++) {
		if (am[r]) {
			ans += abs(c - app[r][dir]);
			ans += app[r][1] - app[r][0];
			c = app[r][!dir];
			wed += am[r];
		}
		if (i == lst)
			break;
		r++;
		ans++;
		dir = !dir;
	}
	cout << ans << '\n';
	return 0;
}
