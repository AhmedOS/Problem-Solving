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

int n, arr[4000], counter[4000][4001], idx[1000001], gid = 1, lst[4001];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (!idx[arr[i]])
			idx[arr[i]] = gid++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		memset(lst, 0, sizeof(lst));
		int c = 1;
		for (int e = i + 1; e < n; e++) {
			if (arr[i] == arr[e])
				c++;
			else {
				int id = idx[arr[e]];
				if (c > lst[id]) {
					counter[i][id] += 2;
					lst[id] = c;
				}
			}
		}
		for (int e = 1; e <= gid; e++) {
			counter[i][e] += c > lst[e];
			ans = max(ans, counter[i][e]);
		}
		ans = max(ans, c);
	}
	cout << ans << '\n';
	return 0;
}
