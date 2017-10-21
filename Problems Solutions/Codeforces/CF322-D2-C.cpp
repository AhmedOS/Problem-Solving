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

string s;
vector<pair<long long, long long>> vec;
int dirx[] = { 0, 0, -1, 1 };
int diry[] = { 1, -1, 0, 0 };
char ch[] = { 'U', 'D', 'L', 'R' };
map<char, int> mp;

int type(long long nm) {
	if (!nm)
		return 0;
	return nm > 0 ? 1 : 2;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	for (int i = 0; i < 4; i++)
		mp[ch[i]] = i;
	int a, b;
	cin >> a >> b >> s;
	if (!a && !b) {
		cout << "Yes\n";
		return 0;
	}
	for (int i = 0; i < s.size(); i++) {
		int id = mp[s[i]];
		vec.push_back({ dirx[id], diry[id] });
		if (i) {
			vec[i].first += vec[i - 1].first;
			vec[i].second += vec[i - 1].second;
		}
	}
	bool ok = 0;
	for (int i = 0; i < vec.size() && !ok; i++) {
		long long na = a - vec[i].first;
		long long nb = b - vec[i].second;
		if (!na && !nb) {
			ok = 1;
			continue;
		}
		if (type(na) == type(vec[vec.size() - 1].first) && type(nb) == type(vec[vec.size() - 1].second)) {
			long long am1 = 0, am2 = 0;
			if (na) {
				if (na % vec[vec.size() - 1].first == 0)
					am1 = na / vec[vec.size() - 1].first;
				else
					am1 = -1;
			}
			if (nb) {
				if (nb % vec[vec.size() - 1].second == 0)
					am2 = nb / vec[vec.size() - 1].second;
				else
					am2 = -1;
			}
			ok = (am1 != -1 && am2 != -1) && (am1 == am2 || !am1 || !am2);
		}
	}
	cout << (ok ? "Yes" : "No") << '\n';
	return 0;
}
