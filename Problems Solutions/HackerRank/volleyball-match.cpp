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

int a, b;
long long vis[30][30], nm;
int mod = 1000000007;

long long solve(int aa, int bb) {
	if (aa == a && bb == b)
		return (a == 24 ? nm : 1);
	if ((aa > a || bb > b) || (aa == 25))
		return 0;
	if (vis[aa][bb] != -1)
		return vis[aa][bb];
	return vis[aa][bb] = (solve(aa + 1, bb) % mod + solve(aa, bb + 1) % mod) % mod;
}

long long power(long long nm, long long pw) {
	if (!pw)
		return 1;
	long long rs = power(nm, pw / 2);
	return ((rs % mod) * (rs % mod) * ((pw & 1 ? nm : 1) % mod)) % mod;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	memset(vis, -1, sizeof(vis));
	cin >> a >> b;
	if (b > a)
		swap(a, b);
	if (a == b || (a > 25 && a - b != 2) || (a == 25 && b >= 24) || a < 25)
		cout << "0\n";
	else {
		if (a > 25) {
			nm = a - 24 - 2;
			nm = power(2, nm);
			a = b = 24;
		}
		cout << solve(0, 0) << '\n';
	}
	return 0;
}
