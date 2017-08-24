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

int n, m, nxt[3001], mx[3001];

int dsum(int nm) {
	int ret = 0;
	while (nm) {
		ret += nm % 10;
		nm /= 10;
	}
	return ret;
}

int divs(int nm) {
	int ret = 0, sq = sqrt(nm);
	for (int i = 1; i <= sq; i++)
		if (nm % i == 0) {
			ret += dsum(i);
			if (nm / i != i)
				ret += dsum(nm / i);
		}
	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	for (int i = 1; i <= 3000; i++)
		nxt[i] = divs(i);
	for (int i = 0; i <= 3000; i++) {
		int c = 1, nm = i;
		while (nm != nxt[nm]) {
			nm = nxt[nm];
			c++;
		}
		mx[i] = c;
	}
	int t = 1;
	while (cin >> n >> m) {
		bool f = 0;
		if (m < n) {
			swap(n, m);
			f = 1;
		}
		int bst = 0, s;
		for (int i = n; i <= m; i++)
			if (mx[i] > bst) {
				bst = mx[i];
				s = i;
			}
		if (f)
			swap(n, m);
		cout << "Input" << t << ": " << n << ' ' << m << '\n';
		cout << "Output" << t << ":";
		while (11) {
			cout << ' ' << s;
			if (s == nxt[s])
				break;
			s = nxt[s];
		}
		cout << '\n';
		t++;
	}
	return 0;
}
