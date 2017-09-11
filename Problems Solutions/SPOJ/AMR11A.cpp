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

int t, n, m, dp[1000][1000], arr[1000][1000];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int e = 0; e < m; e++)
				cin >> arr[i][e];
		int s = 1, e = 500000001, ans;
		while (s <= e) {
			int mid = (s + e) / 2;
			dp[0][0] = mid;
			for (int i = 1; i < n; i++) {
				dp[i][0] = arr[i][0] + dp[i - 1][0];
				if (dp[i - 1][0] <= 0)
					dp[i][0] = 0;
			}
			for (int i = 1; i < m; i++) {
				dp[0][i] = arr[0][i] + dp[0][i - 1];
				if (dp[0][i - 1] <= 0)
					dp[0][i] = 0;
			}
			for (int i = 1; i < n; i++)
				for (int e = 1; e < m; e++) {
					int mx = max(dp[i][e - 1], dp[i - 1][e]);
					dp[i][e] = mx + arr[i][e];
					if (mx <= 0)
						dp[i][e] = 0;
				}
			if (dp[n - 1][m - 1] > 0) {
				e = mid - 1;
				ans = mid;
			}
			else
				s = mid + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}
