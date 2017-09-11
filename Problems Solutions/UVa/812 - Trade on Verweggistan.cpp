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

int n, m, ans, mxg[50];
vector<int> arr[50], pos[50];
set<int> st;
bool vis[50][1001][1001];

void solve(int g, int sum, int sofar) {
	if (sum == ans)
		st.insert(sofar);
	if (g == n)
		return;
	if (vis[g][sofar][sum])
		return;
	vis[g][sofar][sum] = 1;
	solve(g + 1, sum, sofar);
	for (int i = 0; i < pos[g].size(); i++)
		solve(g + 1, sum + mxg[g], sofar + pos[g][i]);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	for (int t = 1; cin >> n && n; t++) {
		for (int i = 0; i < n; i++) {
			arr[i].clear();
			pos[i].clear();
		}
		ans = 0;
		st.clear();
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++) {
			cin >> m;
			arr[i].resize(m);
			for (int e = 0; e < m; e++)
				cin >> arr[i][e];
		}
		for (int i = 0; i < n; i++) {
			int mx = 0, sum = 0;
			for (int e = 0; e < arr[i].size(); e++) {
				sum += 10 - arr[i][e];
				mx = max(mx, sum);
			}
			mxg[i] = mx;
			ans += mx;
			sum = 0;
			for (int e = 0; e < arr[i].size(); e++) {
				sum += 10 - arr[i][e];
				if (sum == mx)
					pos[i].push_back(e + 1);
			}
		}
		solve(0, 0, 0);
		if (t != 1)
			cout << '\n';
		cout << "Workyards " << t << '\n';
		cout << "Maximum profit is " << ans << ".\n";
		cout << "Number of pruls to buy:";
		int c = 0;
		for (auto it : st) {
			cout << ' ' << it;
			c++;
			if (c == 10)
				break;
		}
		cout << '\n';
	}
	return 0;
}
