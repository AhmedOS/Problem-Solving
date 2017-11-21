#pragma comment (linker, "/STACK:256000000")
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
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int n, dp[100000][27];
string s;
map<pair<int, int>, bool> mp;

int solve(int nxt, int prv) {
	if (nxt == s.size())
		return 0;
	if (dp[nxt][prv] != -1)
		return dp[nxt][prv];
	int ret = 1 + solve(nxt + 1, prv);
	if (!mp[{prv, s[nxt] - 'a'}])
		ret = min(ret, solve(nxt + 1, s[nxt] - 'a'));
	return dp[nxt][prv] = ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	cin >> s >> n;
	while (n--) {
		string str;
		cin >> str;
		mp[{str[0] - 'a', str[1] - 'a'}] = 1;
		swap(str[0], str[1]);
		mp[{str[0] - 'a', str[1] - 'a'}] = 1;
	}
	cout << solve(0, 26) << '\n';
	return 0;
}
