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

string str, ans;

void solve(int s, int e, int nxt) {
	if (e < s)
		return;
	int mid = (s + e) / 2;
	ans[mid] = str[nxt];
	solve(s, mid - 1, nxt + 1);
	solve(mid + 1, e, nxt + 1 + mid - s);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	getline(cin, str);
	ans.resize(str.size());
	solve(0, str.size() - 1, 0);
	cout << ans << '\n';
	return 0;
}
