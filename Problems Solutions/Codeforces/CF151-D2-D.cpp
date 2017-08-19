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

long long n, m, k, mod = 1000000007;

long long power(long long nm, long long pw) {
	if (!pw)
		return 1;
	long long rs = power(nm, pw / 2) % mod;
	return (((rs * rs) % mod) * ((pw & 1 ? nm : 1) % mod)) % mod;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> k;
	if (k == 1 || k > n)
		cout << power(m, n) << '\n';
	else if (n == k)
		cout << power(m, (n + 1) / 2) << '\n';
	else if (k & 1)
		cout << (m * (m - 1) + m) % mod << '\n';
	else
		cout << m << '\n';
	return 0;
}
