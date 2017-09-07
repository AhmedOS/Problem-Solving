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

int tt, t, prime[10000000], vis[130];
string s;
set<int> st;

int getBit(int msk, int idx) {
	return (msk >> idx) & 1;
}

int setBit(int msk, int idx, int val) {
	if (val)
		return msk | (1 << idx);
	return msk & ~(1 << idx);
}

void solve(int msk) {
	if (vis[msk] == tt)
		return;
	vis[msk] = tt;
	string str = "";
	for (int i = 0; i < s.size(); i++)
		if (getBit(msk, i))
			str += s[i];
	sort(str.begin(), str.end());
	if (msk) {
		do {
			stringstream ss;
			ss << str;
			int nm;
			ss >> nm;
			if (prime[nm])
				st.insert(nm);
		} while (next_permutation(str.begin(), str.end()));
	}
	for (int i = 0; i < s.size(); i++)
		if (!getBit(msk, i)) {
			int nmsk = setBit(msk, i, 1);
			solve(nmsk);
		}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	for (int i = 2; i < 10000000; i++)
		prime[i] = 1;
	for (int i = 2; i < 10000000; i++)
		for (int e = i + i; prime[i] && e < 10000000; e += i)
			prime[e] = 0;
	cin >> t;
	for (tt = 1; tt <= t; tt++) {
		cin >> s;
		solve(0);
		cout << st.size() << '\n';
		st.clear();
	}
	return 0;
}

//Another Solution
/*
int tt, t, prime[10000000], vis[10000000];
string s;

int solve(int nxt, int sofar) {
	int ret = prime[sofar] && vis[sofar] != tt;
	vis[sofar] = tt;
	if (nxt == s.size())
		return ret;
	return ret + solve(nxt + 1, sofar) + solve(nxt + 1, sofar * 10 + (s[nxt] - '0'));
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	for (int i = 2; i < 10000000; i++)
		prime[i] = 1;
	for (int i = 2; i < 10000000; i++)
		for (int e = i + i; prime[i] && e < 10000000; e += i)
			prime[e] = 0;
	cin >> t;
	for (tt = 1; tt <= t; tt++) {
		int ans = 0;
		cin >> s;
		sort(s.begin(), s.end());
		do {
			ans += solve(0, 0);
		} while (next_permutation(s.begin(), s.end()));
		cout << ans << '\n';
	}
	return 0;
}
*/
