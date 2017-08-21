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

int n, m;
bool banr[1000], banc[1000];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		banr[a] = 1;
		banc[b] = 1;
	}
	banr[0] = 1;
	banr[n - 1] = 1;
	banc[0] = 1;
	banc[n - 1] = 1;
	int ans = 0;
	for (int i = 0; i < n / 2; i++) {
		ans += !banr[i];
		ans += !banr[n - 1 - i];
		ans += !banc[i];
		ans += !banc[n - 1 - i];
	}
	ans += (n & 1) && (!banr[n / 2] || !banc[n / 2]);
	cout << ans << '\n';
	return 0;
}
