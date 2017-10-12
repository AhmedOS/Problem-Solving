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

int mod = 1000000007;

long long power(long long nm, int pw) {
	if (!pw)
		return 1;
	long long rs = power(nm, pw / 2);
	return ((((rs % mod) * (rs % mod)) % mod) * (pw & 1 ? nm : 1)) % mod;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	//while (11) {
		string s;
		cin >> s;
		long long p = power(2, s.size() - 1);
		long long idx = 0;
		for (int i = s.size() - 1, c = 0; i >= 0; i--, c++)
			if (s[i] == '1')
				idx = ((idx % mod) + (power(2, c) % mod)) % mod;
		cout << (idx * p) % mod << '\n';
		/*
		bitset<32> bs(s);
		int x = bs.to_ulong(), all = (1 << s.size());
		for (int e = 0; e < all; e++) {
			//x = e;
			vector<pair<int, int>> vec(all);
			for (int i = 0; i < all; i++)
				vec[i].first = i, vec[i].second = i ^ x;
			int ans = 0;
			for (int i = 0; i < all; i++)
				for (int e = i + 1; e < all; e++)
					ans += vec[i].first < vec[e].first && vec[i].second > vec[e].second;
			cout << ans << '\n';
			break;
		}
		*/
	//}
	return 0;
}
