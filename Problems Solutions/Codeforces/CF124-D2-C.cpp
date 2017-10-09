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

string s;
vector<int> primes;
set<pair<int, int>> st;
vector<int> vec[1000000];
bool vis[1000000];
int id, indices[1000], arr[26];

int dfs(int nxt) {
	indices[id++] = nxt;
	int ret = 0;
	for (int i = 0; i < vec[nxt].size(); i++)
		if (!vis[vec[nxt][i]]) {
			vis[vec[nxt][i]] = 1;
			ret++;
			ret += dfs(vec[nxt][i]);
		}
	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		arr[s[i] - 'a']++;
	for (int i = 0; i < 26; i++)
		if (arr[i])
			st.insert({ arr[i], i });
	for (int i = 2; i <= s.size(); i++) {
		bool prime = 1;
		for (int e = 2; e < i && prime; e++)
			prime = (i % e != 0);
		if (prime)
			primes.push_back(i);
	}
	for (int i = 0; i < primes.size(); i++)
		for (int e = 1; e <= s.size() / primes[i]; e++)
			if (primes[i] != primes[i] * e) {
				vec[primes[i]].push_back(primes[i] * e);
				vec[primes[i] * e].push_back(primes[i]);
			}
	string ans;
	ans.resize(s.size());
	for (int i = 0; i < primes.size(); i++)
		if (!vis[primes[i]]) {
			id = 0;
			vis[primes[i]] = 1;
			int c = dfs(primes[i]) + 1;
			auto it = st.lower_bound({ c, -1 });
			if (it != st.end()) {
				pair<int, int> p = *it;
				st.erase(it);
				if (p.first - c)
					st.insert({ p.first - c , p.second });
				for (int e = 0; e < id; e++)
					ans[indices[e] - 1] = p.second + 'a';
			}
			else {
				ans.resize(0);
				break;
			}
		}
	for (int i = 0; i < ans.size(); i++)
		if (!ans[i]) {
			pair<int, int> p = *st.begin();
			st.erase(st.begin());
			ans[i] = 'a' + p.second;
			p.first--;
			if (p.first)
				st.insert(p);
		}
	if (ans.size())
		cout << "YES\n" << ans << '\n';
	else
		cout << "NO\n";
	return 0;
}
