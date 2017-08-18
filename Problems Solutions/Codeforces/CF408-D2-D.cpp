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

int n, arr[1001], mod = 1000000007;
long long cost[1001];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int e = arr[i]; e != i; e++)
			cost[i] = (cost[i] + cost[e]) % mod;
		cost[i] = (cost[i] + 2) % mod;
		ans = (ans + cost[i]) % mod;
	}
	cout << ans << '\n';
	return 0;
}
