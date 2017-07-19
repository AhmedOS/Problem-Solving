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

int t, n, k;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		long long ans = 0;
		int mx = 0, mxi = -1;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			int nm;
			cin >> nm;
			if (nm <= k && mx > k)
				ans += mxi + 1;
			else if (nm > k) {
				ans += i + 1;
				mxi = i;
				mx = nm;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
