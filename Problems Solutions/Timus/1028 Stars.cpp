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

int n, bit[32002], ans[15000];

int query(int fen[], int idx) {
	int ret = 0;
	for (int i = idx; i; i -= (i & -i))
		ret += fen[i];
	return ret;
}

void update(int fen[], int idx, int val) {
	for (int i = idx; i <= 32001; i += (i & -i))
		fen[i] += val;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a++, b++;
		int lvl = query(bit, a);
		ans[lvl]++;
		update(bit, a, 1);
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << '\n';
	return 0;
}
