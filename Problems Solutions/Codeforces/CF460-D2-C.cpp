#pragma comment (linker, "/STACK:256000000")
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

int n, m, w, arr[100000];

bool ok(long long val) {
	long long seg[100000];
	long long ret = 0, cover = 0;
	memset(seg, 0, sizeof(seg));
	for (int i = 0; i < n; i++) {
		cover -= i - w >= 0 ? seg[i - w] : 0;
		if (arr[i] + cover < val) {
			long long diff = val - arr[i] - cover;
			seg[i] = diff;
			ret += diff;
			cover += diff;
		}
	}
	return ret <= m;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> w;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	long long s = 1, e = 1e14, ans;
	while (s <= e) {
		long long mid = (s + e) / 2;
		if (ok(mid)) {
			ans = mid;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}
	cout << ans << '\n';
	return 0;
}
