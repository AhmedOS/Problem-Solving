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

int n, arr[100000], id;
long long prefix[100000], suffix[100000];
map<long long, int> idx;
set<int> vec[100001];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (!idx[arr[i]])
			idx[arr[i]] = ++id;
		vec[idx[arr[i]]].insert(i);
	}
	prefix[0] = arr[0];
	for (int i = 1; i < n; i++)
		prefix[i] = prefix[i - 1] + arr[i];
	suffix[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--)
		suffix[i] = suffix[i + 1] + arr[i];
	// 0 -> i-1 , i -> n-1
	bool ok = 0;
	for (int i = 0; i < n && !ok; i++) {
		long long lft = (i ? prefix[i - 1] : 0), rit = suffix[i];
		long long dif = abs(lft - rit);
		if (!dif)
			ok = 1;
		else if (!(dif & 1)) {
			dif /= 2;
			if (lft > rit) {
				auto it = vec[idx[dif]].lower_bound(0);
				ok = (it != vec[idx[dif]].end() && *it < i && i != 1);
			}
			else {
				auto it = vec[idx[dif]].lower_bound(i);
				ok = (it != vec[idx[dif]].end() && i != n - 1);
			}
		}
	}
	cout << (ok ? "YES" : "NO") << '\n';
	return 0;
}
