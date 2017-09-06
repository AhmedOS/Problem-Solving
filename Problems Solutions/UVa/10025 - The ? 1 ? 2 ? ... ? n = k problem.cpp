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

int t, n;

long long sum(long long nm) {
	long long a = nm, b = nm + 1;
	if (a & 1)
		b /= 2;
	else
		a /= 2;
	return a * b;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n;
		n = abs(n);
		long long ret;
		int s = 1, e = 1e9, ans;
		while (s <= e) {
			int mid = (s + e) / 2;
			ret = sum(mid);
			if (ret >= n) {
				e = mid - 1;
				ans = mid;
			}
			else
				s = mid + 1;
		}
		ret = sum(ans);
		while ((ret - n) & 1) {
			ans++;
			ret = sum(ans);
		}
		cout << ans << '\n';
		if (t)
			cout << '\n';
	}
	return 0;
}
