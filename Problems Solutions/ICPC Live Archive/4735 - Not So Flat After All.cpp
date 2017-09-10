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

int n, m, t;

set<int> st;
map<int, int> mp, mp2;
void pfact(int nm, map<int, int> &mp) {
	mp.clear();
	if (nm == 1)
		return;
	if (nm % 2 == 0)
		st.insert(2);
	while (nm % 2 == 0) {
		mp[2]++;
		nm = nm / 2;
	}
	int sq = sqrt(nm);
	for (int i = 3; i <= sq; i += 2) {
		if (nm % i == 0)
			st.insert(i);
		while (nm % i == 0) {
			mp[i]++;
			nm = nm / i;
		}
	}
	if (nm > 2) {
		mp[nm]++;
		st.insert(nm);
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	while (cin >> n >> m && n && m) {
		st.clear();
		t++;
		pfact(n, mp);
		pfact(m, mp2);
		int dif = 0;
		for (auto it : st)
			dif += abs(mp[it] - mp2[it]);
		cout << t << ". " << st.size() << ':' << dif << '\n';
	}
	return 0;
}
