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
#include <string.h>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

const int MAX = 1000 + 9;
const double PI = atan(1) * 4;
int t, n, arr[1009][10], dp[1009][10];

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	//const clock_t beg = clock();

	cin >> t;
	while (t--) {
		for (int i = 0; i < 1009; i++)
			for (int e = 0; e < 10; e++)
				dp[i][e] = 1 << 30;
		memset(arr, 0, sizeof(arr));
		cin >> n;
		n /= 100;
		for (int i = 9; i >= 0; i--)
			for (int e = 0; e < n; e++)
				cin >> arr[e][i];
		dp[0][0] = 0;
		for (int i = 1; i < n; i++)
			for (int e = 1; e < 10; e++) {
				dp[i][e] = dp[i - 1][e] + 30 - arr[i - 1][e];
				if (e + 1 < 10)
					dp[i][e] = min(dp[i][e], dp[i - 1][e + 1] + 20 - arr[i - 1][e + 1]);
				dp[i][e] = min(dp[i][e], dp[i - 1][e - 1] + 60 - arr[i - 1][e - 1]);
			}
		cout << dp[n - 1][1] + 20 - arr[n - 1][1] << "\n\n";
	}
	
	//cout << double(clock() - beg) / CLOCKS_PER_SEC << '\n';
	return 0;
}