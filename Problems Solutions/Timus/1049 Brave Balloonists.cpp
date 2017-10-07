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

map<int, int> mp, gmp;

void pfact(int nm) {
	if (nm == 1)
		return;
	for (int i = 2; nm != i; i++)
		if (nm % i == 0) {
			pfact(i);
			pfact(nm / i);
			return;
		}
	mp[nm]++;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	for (int i = 0; i < 10; i++) {
		int nm;
		cin >> nm;
		if (nm == 1)
			continue;
		mp.clear();
		pfact(nm);
		for (auto it : mp)
			gmp[it.first] += it.second;
	}
	int rs = 1;
	for (auto i = gmp.begin(); i != gmp.end(); i++)
		rs = (rs * (i->second + 1)) % 10;
	cout << rs << '\n';
	return 0;
}
