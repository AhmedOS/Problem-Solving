#include <bits/stdc++.h>
using namespace std;

int t;

int main() {
	//freopen("lazy.in", "rt", stdin);
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		int n, ans = 0;
		cin >> n;
		while (n != 1) {
			ans += n / 2;
			n = (n / 2) + (n % 2);
		}
		cout << "Case " << tt << ": " << ans << '\n';
	}
	return 0;
}
