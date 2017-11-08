#include <bits/stdc++.h>
using namespace std;

int t;

int main() {
	//freopen("katryoshka.in", "rt", stdin);
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		long long ans = 0;
		int eye, mo, bod;
		cin >> eye >> mo >> bod;
		int mn = min(min(eye, mo), bod);
		eye -= mn;
		mo -= mn;
		bod -= mn;
		ans += mn;
		ans += min(eye / 2, bod);
		cout << "Case " << tt << ": " << ans << '\n';
	}
	return 0;
}
