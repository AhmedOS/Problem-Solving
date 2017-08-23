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

int t, n, arr[20], fin;
long long dp[70000];

int getBit(int msk, int idx) {
	return (msk >> idx) & 1;
}

int setBit(int msk, int idx, int val) {
	if (val)
		return msk | (1 << idx);
	return msk & ~(1 << idx);
}

struct state {
	bool prc = 0;
	int def = 0, wep = 0;
};

stack<state> stk;
long long solve(int init) {
	state st;
	st.wep = init;
	stk.push(st);
	while (!stk.empty()) {
		state tp = stk.top();
		stk.pop();
		if (tp.prc) {
			long long sum = 0;
			for (int i = 0; i < n; i++)
				if (!getBit(tp.def, i) && getBit(tp.wep, i)) {
					int nm = setBit(tp.def, i, 1);
					sum += dp[nm];
				}
			dp[tp.def] = sum;
		}
		else {
			if (tp.def == fin)
				dp[tp.def] = 1;
			else if (dp[tp.def] == -1) {
				tp.prc = 1;
				stk.push(tp);
				for (int i = 0; i < n; i++)
					if (!getBit(tp.def, i) && getBit(tp.wep, i)) {
						state ns;
						ns.def = setBit(tp.def, i, 1);
						ns.wep = tp.wep | arr[i];
						stk.push(ns);
					}
			}
		}
	}
	return dp[0];
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		memset(dp, -1, sizeof(dp));
		cin >> n;
		fin = (1 << n) - 1;
		int init = 0;
		for (int i = -1; i < n; i++) {
			string s;
			cin >> s;
			int msk = 0;
			for (int e = 0; e < s.size(); e++)
				msk = setBit(msk, e, s[e] == '1');
			if (i == -1)
				init = msk;
			else
				arr[i] = msk;
		}
		cout << "Case " << tt << ": " << solve(init) << '\n';
	}
	return 0;
}
