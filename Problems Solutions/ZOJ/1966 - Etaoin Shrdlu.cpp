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

int n;
map<pair<char, char>, int> mp;
vector<pair<int, string>> vec;

bool cmp(pair<int, string> &a, pair<int, string> &b) {
	if (a.first != b.first)
		return a.first > b.first;
	return a.second < b.second;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	while (cin >> n && n) {
		vec.clear();
		mp.clear();
		cin.ignore();
		char ch;
		int all = 0;
		for (int i = 0; i < n; i++) {
			string s;
			getline(cin, s);
			if (i) {
				mp[{ch, s[0]}]++;
				all++;
			}
			for (int e = 0; e < s.size() - 1; e++) {
				mp[{s[e], s[e + 1]}]++;
				all++;
			}
			ch = s[s.size() - 1];
		}
		for (auto it : mp) {
			string tmp = "";
			tmp += it.first.first;
			tmp += it.first.second;
			vec.push_back({ it.second, tmp });
		}
		sort(vec.begin(), vec.end(), cmp);
		for (int i = 0; i < 5; i++)
			cout << fixed << setprecision(6) << vec[i].second << ' ' << vec[i].first << ' ' << (double)vec[i].first / all << '\n';
		cout << '\n';
	}
	return 0;
}
