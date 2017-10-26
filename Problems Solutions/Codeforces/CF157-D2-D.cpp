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

int n, m;
long long bit[100001];

void update(long long fen[], int idx, long long val) {
	for (int i = idx; i <= n; i += (i & -i))
		fen[i] += val;
}
long long query(long long fen[], int idx) {
	long long ret = 0;
	for (int i = idx; i; i -= (i & -i))
		ret += fen[i];
	return ret;
}

void update_range(long long fen[], int s, int e, long long val) {
	if (s > e)
		return;
	update(fen, s, val);
	update(fen, e + 1, -val);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	vector<pair<int, bool>> vec;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		char ch;
		int nm;
		cin >> ch >> nm;
		vec.push_back({ nm, ch == '-' });
		if (ch == '+') {
			update_range(bit, nm, nm, 1);
		}
		else {
			update_range(bit, 1, nm - 1, 1);
			update_range(bit, nm + 1, n, 1);
		}
	}
	vector<int> cr;
	for (int i = 1; i <= n; i++)
		if (m && query(bit, i) == m)
			cr.push_back(i);
	for (int i = 0; i < n; i++) {
		if (!m) {
			cout << "Lie\n";
			continue;
		}
		long long ret = query(bit, vec[i].first);
		if (vec[i].second) {
			if (ret == m && cr.size() == 1)
				cout << "Lie\n";
			else if (ret == m && cr.size() != 1)
				cout << "Not defined\n";
			else
				cout << "Truth\n";
		}
		else {
			if (ret != m)
				cout << "Lie\n";
			else
				cout << (cr.size() == 1 ? "Truth" : "Not defined") << '\n';
		}
	}
	return 0;
}
